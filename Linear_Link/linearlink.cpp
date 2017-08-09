/*
线性表的顺序存储结构，是指用一段地址连续的存储单元依次存储线性表的数
据元素。既然线性表的每个数据元素类型都相同，所以可以用一维数组来实现
顺序存储结构，即把第一个元素存储在下标为0的位置上，接着把线性表相邻的
元素存储在数组中相邻的位置。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//定义元素类型

struct List //定义节点类型
{
    ElemType *list; //数组存储数据元素，存储空间基址
    int lengths; //当前大小
    int MaxSize; //最大的存储容量    
};

//初始化线性表
int Init_List(struct List *L, int max_size)
{
    if (max_size < 0)
    {
        printf("max_size must be greater than zero\n");
        return -1;
    }
    L->MaxSize = max_size;
    L->list = (ElemType *)malloc(sizeof(ElemType) * max_size)
    if (!L->list)
    {
        printf("malloc fail !!!\n");
        return -1;
    }
    //初始线性表元素个数为0
    L->lengths = 0;
}

//清除线性表中的所有元素，释放存储空间
void Clear_List(struct List *L)
{
    if (L->list != NULL)
    {
        free(L->list);
        L->list = 0;
        L->lengths = L->MaxSize = 0;
    }
}

//求线性表的长度
int Get_List_Lengths(struct List *L)
{
    return L->lengths;
}

//判断线性表是否为空
int Is_Empty_List(struct List *L)
{
    if (L->lengths == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//根据索引获取线性表中的某个元素
ElemType Get_Elem_List(struct List *L, int pos)
{
    if (pos < 1 || pos > L->lengths)
    {
        printf("pos is out of rang\n");
        return -1;
    }
    return L->list[pos-1];
}

//遍历线性表，打印线性表
void Print_List(struct List *L)
{
    for (int i = 0; i < L->lengths; i++)
    {
        printf("%d, ", L->list[i]);
    }
    printf("\n");
}

//从线性表中查找某个元素（第一个），有则返回其位置，否则返回-1
int Find_Elem_List(struct List *L, ElemType elem)
{
    for (int i = 0; i < L->lengths; i++)
    {
        if (L->list[i] == elem)  
        {
            return i;
            //此处类型ElemType为整型，当为字符串类型（char *）时，
            //if语句应改为: if (strcmp(L->list[i], x) == 0)  
        }
    }
    return -1;
}

//修改线性表中的指定位置元素
int Modify_Elem_List(struct List *L, int pos, ElemType elem)
{
    if (pos < 1 || pos > L->MaxSize)
    {
        printf("pos is out of rang\n");
        return -1;
    }
    else
    {
        L->list[pos-1] = elem;
        return 1;
    }
}

//判断线性表已达最大存储量，并重新分配更大的内存
int Again_Malloc(struct List *L)
{
    //此处重新分配的空间为原来的2倍  
    ElemType *newList = (ElemType *)realloc(L->list, 2 * L->MaxSize * sizeof(ElemType));
    if (!newList)
    {
        printf("realloc fail!!!\n");
        return -1;
    }
    L->list = newList;
    L->MaxSize = 2 * L->MaxSize;
    return 1;
}

void Inser_First_List(struct List *L, ElemType elem)
{
    if (L->lengths == L->MaxSize)//内存已满
    {
        Again_Malloc(L);
    }
    for (int i = L->lengths-1; i >= 0; i--)
    {
        L->list[i+1] = L->list[i];
    }
    L->list[0] = elem;
    L->lengths++;
}

//表尾插入元素
void Insert_Last_List(struct List *L, ElemType elem)
{
    if (L->lengths == L->MaxSize)
    {
        Again_Malloc(L);
    }
    L->list[L->lengths] = elem;
    L->lengths++;
}

//向pos位置插入元素
int Insert_Elem_List(struct List *L, int pos, ElemType elem)
{
    if (pos < 1 || pos > L->lengths)
    {
        return -1;   
    }
    if (L->lengths == L->MaxSize)
    {
        Again_Malloc(L);
    }
    for (int i = L->lengths-1; i >= pos-1; i--)
    {
        L->list[i + 1] = L->list[i];
    }
    L->list[pos - 1] = elem;
    L->lengths++;
    return 1;
}

//从线性表L中删除第pos个元素并返回它，若删除失败则停止程序运行 
ElemType Delete_PosElem_List(struct List *L, int pos)
{
    ElemType elem;
    if (pos < 1 || pos > L->lengths)
    {
        printf("pos out of rang\n");
        return -1;
    }
    elem = L->list[pos - 1];
    for (int i = pos-1; i < L->lengths-1; i++)
    {
        L->list[i] = L->list[i + 1];
    }
    L->lengths--;
    return elem;
}

// 从线性表L中删除值为x的第一个元素，若删除成功返回1否则返回0 
int Delete_ValueElem_List(struct List * L, ElemType elem)
{
    int idx = Find_Elem_List(L, elem);
    if (idx >= 0)
    {
        Delete_PosElem_List(L, idx);
        return 1;
    }
    return -1;
}


int main() 
{
    int a[10] = {2,4,6,8,10,12,14,16,18,20};  
    int i;  
    struct List L;  
    return 0;
}
