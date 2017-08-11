/**************************************************************************************************************
以下为操作链表的算法，该链表为单链表。
链表以头指针为索引，头指针指向头节点，头节点指向首节点，以此类推，直到尾节点。
头节点中不存放数据，只存放指向首节点的指针，
设置头节点的目的是为了方便对链表的操作，如果不设置头节点，而是直接由头指针指向首节点，
这样在对头指针后的节点进行插入删除操作时就会与其他节点进行该操作时有所不同，便要作为一种特殊情况来分析
**************************************************************************************************************/
#define _CRT_STDIO_INLINE

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data; //这里只是简单学习，只设置了简单的int，还可以为其他的各种数据结构
    struct Node *next;
};

/*
* 链表初始化
*/
int InitLinkList(struct Node *L)
{
    L = (struct Node *)malloc(sizeof(struct Node));
    if(L == 0)
    {
        return -1;
    }
    L->next = NULL;
    return 1;
}

/*
*清空链表, 只保留头节点
*/
void ClearLinkList(struct Node *L)
{
    struct Node *temp;
    while(L->next)
    {
        temp = L->next;
        L->next = temp->next;
        free(temp);
    }
}

/*
*销毁链表
*/
void DestroyLinklist(struct Node *L)
{
    ClearLinkList(L);
    free(L);//释放头结点
    L = NULL; //链表的变量归于初始值
}

/*
*获取链表的长度
*/
int GetLinklistLength(struct Node *L)
{
    int count = 0;
    if (L == NULL)
    {
        printf("该链表不存在！！！");
        return 0;
    }
    
    while(L->next)
    {
        count++;
        L = L->next;
    }
    return count;
}

/*
*判断链表是否为空
*/
int IsEmpty(struct Node *L)
{
    if(L->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
*获取某一位置元素
*/
int GetLinklistElem(struct Node *L, int pos, int data)
{
    int j = 1;
    struct Node *current = L->next;
    while(current && j < pos)
    {
        current = current->next;
        j++;
    }
    if (current==NULL || j > pos)
    {
        printf("位置信息有误！！！\n");
        return 0;
    }

    data = current->data;
    return data;
}

/*
*查找链表中的某一元素
*/
int FindLinklistElem(struct Node *L, int pos, int data)
{
    pos = 1;
    struct Node *current = L->next;
    while(current && current->data!=data)
    {
        current = current->next;
        pos++;
    }
    if(current != NULL)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

/*
*创建一个链表
*/
struct Node* CreatLinklist()
{
    int data;
    struct Node *pHeader = (struct Node *)malloc(sizeof(struct Node));
    struct Node *current = pHeader;
    current->next = NULL;
    if(pHeader == NULL)
    {
        printf("分配内存失败！！！");
        return NULL;
    }
    printf("请输入第一个数据（按q退出）：");
    while(scanf("%d", &data)==1)
    {
        struct Node *pNode = (struct Node *)malloc(sizeof(struct Node));
        if (pNode == NULL)
        {
            printf("分配内存失败！！！");
            return NULL;
        }
        current->next = pNode;
        pNode->data = data;
        pNode->next = NULL;
        current = pNode;
        printf("请输入下一个数据（按q退出）：");
    }
    return pHeader;
}

/*
*打印所有元素
*/
void PrintLinklist(struct Node *L)
{
    struct Node *current = L->next;
    while(current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

/*
*链表插入元素
*/
bool InsertElem(struct Node *L, int data, int pos)
{
    int i = 1;
    struct Node *current = L;
    while(current && i < pos)
    {
        current = current->next;
        i++;
    }
    if (current == NULL || i > pos)
    {
        printf("请在正确的位置插入元素！！！");  
        return false;
    }
    struct Node *pNewNode = (struct Node*)malloc(sizeof(struct Node));
    pNewNode->data = data;
    pNewNode->next = current->next;
    current->next = pNewNode;
    return true;
}

/*
*删除指定位置的元素
*/
bool DeleteLinkListElem(struct Node *L, int pos)
{
    int i = 1;
    struct Node *current = L->next;
    while (current && i < pos)
    {
        current = current->next;
        i++;
    }
    if (current == NULL || i > pos)
    {
        printf("请输入正确的位置信息！！！");
        return false;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return true;
}

/*
*使用冒泡排序法对链表进行排序
*/
void SortLinklist(struct Node *L)
{
    int i, j, t, n;
    struct Node *current = L;
    struct Node *temp;
    n = GetLinklistLength(L);
    for (size_t i = 1; i < n-1; i++)
    {
        current = current->next;
        temp = current;
        for (size_t j = 1; j < n-i; j++)
        {
            if (temp->data > temp->next->data)
            {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int len;
    int data;
    struct Node *Linklist = NULL;
    //创建链表并输出
    Linklist = CreatLinklist();
    PrintLinklist(Linklist);
    
    return 1;
} 