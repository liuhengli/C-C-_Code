/*
双向链表，顾名思义，就是数据本身具备了左边和右边的双向指针。双向链表相比较单向链表，主要有下面几个特点：
（1）在数据结构中具有双向指针
（2）插入数据的时候需要考虑前后的方向的操作
（3）同样，删除数据的是有也需要考虑前后方向的操作
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Double_Link_Node
{
    ElemType data;
    struct Double_Link_Node *prior;
    struct Double_Link_Node *next;
};

typedef struct Double_Link_Node Double_Link_list;

// 初始化双向链表
int Init_Double_Link(Double_Link_list *list)
{
    list = (Double_Link_list *)malloc(sizeof(Double_Link_list));
    if (list == NULL)
    {
        printf("Malloc fail !!!\n");
        return -1;
    }
    //空的双向链表的前驱和后驱都会指向自己；
    list->next = list;
    list->prior = list;
    return 1;
}

// 清空双向链表
void Clear_Double_Link(Double_Link_list *list)
{
    Double_Link_list *temp = list->next; // temp指向链表的的一个元素
    while (temp != list)
    {
        temp = temp->next;
        free(temp->prior);
    }
    temp->next = list;
    temp->prior = list;
}

// 销毁双向链表
void Destory_Double_Link(Double_Link_list *list)
{
    Clear_Double_Link(list);
    free(list);
    list = NULL;
}

// 判断链表是否为空
int IsEmpty_Double_Link(Double_Link_list *list)
{
    if (list->next == list && list->prior == list) //满足两个条件
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// 获取链表的长度
int Get_Length_Double_Link(Double_Link_list *list)
{
    Double_Link_list *temp = list->next;
    int count = 0;
    while (temp != list)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 获取链表的某元素
ElemType Get_PosElem_Double_Link(Double_Link_list *list, int pos)
{
    if (pos < 1 || pos > Get_Length_Double_Link(list))
    {
        printf("Index Out of range!!!\n");
        return -1;
    }
    Double_Link_list *temp = list;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

// 查找某元素的位置
int Find_Elem_Double_Link(Double_Link_list *list, ElemType elem)
{
    Double_Link_list *temp = list->next;
    int pos = 0;
    while (temp != list)
    {
        pos++;
        if (temp->data == elem)
        {
            return pos;
        }
    }
    return 0;
}

// 获取前一个元素
ElemType Get_PriorElem_Doubel_Link(Double_Link_list *list, ElemType elem)
{
    Double_Link_list *temp = list->next->next; // temp指向链表的第二个元素
    while (temp != list)
    {
        if (temp->data == elem)
        {
            return temp->prior->data;
        }
    }
    printf("Not exist prior elem\n");
    return 0;
}

// 获取下一个元素
ElemType Get_NextElem_Double_Link(Double_Link_list *list, ElemType elem)
{
    Double_Link_list *temp = list->next->next;
    while (temp != list)
    {
        if (temp->prior->data == elem)
        {
            return temp->data;
        }
    }
    printf("Not exist next elem\n");
    return 0;
}

// 向双向链表中插入元素
int Insert_Elem_Double_Link(Double_Link_list *list, int pos, ElemType elem)
{
    if (pos < 1 || pos > Get_Length_Double_Link(list))
    {
        printf("Index Out of range\n");
        return 0;
    }
    Double_Link_list *temp = list;
    for (int i = 0; i < pos-1; i++) // 找到第pos-1个节点
    {
        temp = temp->next;
    }
    Double_Link_list *q = temp->next; // q指向第pos个节点
    Double_Link_list *s = (Double_Link_list *)malloc(sizeof(struct Double_Link_Node));
    s->data = elem;
    s->next = q; // 先改变向右的指针
    temp->next = s;
    s->prior = temp; // 改变向左的指针
    q->prior = s; 

    return 0;
}

// 删除某个节点元素
int Delete_Elem_Double_Link(Double_Link_list *list, int pos)
{
    if (pos < 1 || pos > Get_Length_Double_Link(list))
    {
        printf("Index Out of range\n");
        return 0;
    }
    Double_Link_list *temp = list;
    for (int i = 0; i< pos - 1; i++)// 找到第pos-1个节点
    {
        temp = temp->next;
    }
    Double_Link_list *deleteElem = temp->next; // deleteElem指向第pos个节点
    // Double_Link_list *p;
    temp->next = deleteElem->next;
    deleteElem->next->prior = temp;
    free(deleteElem);
    return 0;
}
