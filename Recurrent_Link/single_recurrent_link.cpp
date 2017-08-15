/*
将单链表中终端结点的指针端由空指针改为头结点，就使整个单链表形成一个环，这种头尾相接的单链表就称为单循环链表，简称循环链表。
循环链表的好处是：从任何结点出发，都可以访问到链表的所有结点。
为了使空链表和非空链表处理一致，我们通常设一个头结点。注意，并不说循环链表一定要有头结点。
单向链表最后指向为NULL，也就是为空，那单向循环链表就是不指向为NULL了，指向头节点，
所以下面这个程序运行结果就是，你将会看到遍历链表的时候就是一个死循环，因为它不指向为NULL，
也是周而复始的执行。串成了一个环型。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct Recurrent_Link_Node
{
    ElemType data;
    struct Recurrent_Link_Node *next;
};
typedef struct Recurrent_Link_Node R_Link_list;


// 初始化循环链表
int Init_Recurrent_Link(R_Link_list *list)
{
    list = (R_Link_list *)malloc(sizeof(struct Recurrent_Link_Node));
    if (list == NULL)
    {
        printf("Malloc fail !!!\n");
        return -1;
    }
    list->next = list;
    return 1;
}

//清空操循环链表，不释放了头结点。
int Clear_Recurrent_Link(R_Link_list *list)
{
    R_Link_list *p = list->next;
    R_Link_list *temp = p;
    while (list != p)
    {
        p = p->next;
        free(temp);
        temp = p;
    }
    list->next = list;
    printf("Link have cleared \n");
    return 1;
}

//DestroyList操作，释放了头结点。
int Destroy_Recurrent_Link(R_Link_list *list)
{
    Clear_Recurrent_Link(list);
    free(list);//释放头节点
    list = NULL;
    return 1;
}

//判断链表是否为空,为空则返回0,否则返回1。
int isEmpty_Recurrent_link(R_Link_list *list)
{
    if (list->next == list)//头节点的尾指针指向头节点
    {
        return 0;
    }
    return 1;
}

//获取链表的长度，并返回长度
int Get_Lengths_Recurrent_link(R_Link_list *list)
{
    int lengths = 0;
    R_Link_list *temp = list->next;
    while (temp != list)
    {
        lengths ++;
        temp = temp->next;
    }
    return lengths;
}

//获取链表的某个元素
ElemType Get_PosElem_Recurrent_Link(R_Link_list *list, int pos)
{
    if (pos < 1 || pos > Get_Lengths_Recurrent_link(list))
    {
        printf("Out of range, Please input true pos!!!\n");
        return -1;
    }
    R_Link_list *temp = list->next;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

//查找链表的某个元素，并返回该节点
R_Link_list * Find_Elem_Recurrent_Link(R_Link_list *list, ElemType elem)
{
    R_Link_list *temp = list->next;
    // int pos = 1;
    while (temp != list)
    {
        if (temp->data == elem)
        {
            return temp;
        }
        // pos ++;
    }
    printf("R_Link_list not have this elem\n");
    return NULL;
}

//获取某元素的的后继，返回elem的后继
ElemType Get_Next_Recurrent_Link(R_Link_list *list, ElemType elem)
{
    R_Link_list *current = Find_Elem_Recurrent_Link(list, elem);
    if (current == NULL)
    {
        return -1;
    }
    else if (current->next == list) 
    {
        return list->next->data;
    }
    else
    {
        return current->next->data;
    }
}


//在循环链表某个位置插入元素
int Inser_PosElem_Recurrent_Link(R_Link_list *list, int pos, ElemType elem)
{
    if (pos < 1 || pos > Get_Lengths_Recurrent_link(list))
    {
        printf("Out of range\n");
        return -1;
    }
    R_Link_list *p = list;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    R_Link_list *pNewNode = (R_Link_list *)malloc(sizeof(struct Recurrent_Link_Node));
    R_Link_list *temp = p->next;
    pNewNode = p->next;
    pNewNode->next = temp;
    free(temp);
    pNewNode->data = elem;
    return 1;
}

//在循环链表某个位置删除元素
ElemType Delete_PosElem_Recurrent_Link(R_Link_list *list, int pos)
{
    if (pos < 1 || pos > Get_Lengths_Recurrent_link(list))
    {
        printf("Out of range\n");
        return -1;
    }
    R_Link_list *p = list;
    for (int i = 0; i < pos-1; i++)
    {
        p = p->next;
    }
    R_Link_list *temp = p->next;
    ElemType data = temp->data;
    p->next = temp->next;
    free(temp);
    return data;
}

//打印整个循环链表
void Print_Recurrent_Link(R_Link_list *list)
{
    R_Link_list *pCur = list->next;
    int i = 0;
    while (pCur != list)
    {
        printf("第%d个元素为：%d\n", ++i, pCur->data);
        pCur = pCur->next;
    }
}


int main()
{
    R_Link_list *list;
    int res = Init_Recurrent_Link(list);
    if (res < 0)
    {
        printf("Initalizer fail !!!\n");
        return -1;
    }
    return 1;
}