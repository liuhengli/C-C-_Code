/*静态链表  
数组第一个元素和最后一个元素特殊化处理  
1:s[0].cur存放备用链表的第一个节点的下标(备用链表的头结点)，
非0表示存在备用链表，为0表示不存在备用链表  
2：s[MAXSIZE-1].cur存放第一个有数值的节点的下标（相当于头结点）
非0表示存在有效链表，为0表示不存在有效链表

3:静态链表的优缺点:
（1）优点：在插入和删除操作时，只需要修改游标，不需要移动元素。从而改进了在顺序存储结构中插入和删除元素时需要移动大量元素的缺点。
（2）缺点：没有解决连续存储分配带来的表长难以确定的问题；失去了顺序存储结构随机存取的特性。
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data; //数据域的类型可以是任意类型
    int cur;
}StaticNode;
typedef StaticNode static_link[MAX_SIZE];

// 初始化操作
void Init_Static_Link(static_link *S)
{
    for (int i = 0;  i < MAX_SIZE - 1;  i++)
    {
        S[i]->cur = i + 1;
    }
    S[MAX_SIZE - 1]->cur = 0;//开始静态链表为空，没有有效节点，所以有效链表的头结点的指向为NULL   
}

//Malloc函数实现
//开辟成功：返回开辟节点的下标  
//开辟失败：返回0  
//该方法的作用是返回下一个元素存入的位置。
int Malloc_Static_Linklist(static_link *S)
{
    int i = S[0]->cur;
    if (i == 0 || i == MAX_SIZE - 1)
    {
        return 0;
    }
    else //存在备用链表
    {
        S[0]->cur = S[i]->cur; //备用链表用了一个节点，把它的下一个节点用来备用
    }
    return i;
}

//将释放的节点，头插到备用链表中
//将下标为k的空闲结点回收为备用链表的结点
void Free_Static_Linklist(static_link *S, int k)
{
    S[k]->cur = S[0]->cur;
    S[0]->cur = k;
}

//打印静态链表
void Print_Static_Linklist(static_link *S)
{
    int i = S[MAX_SIZE - 1]->cur;//找到第一个有效节点的下标
    while (i != 0)
    {
        printf("%d\n-->", S[i]->data);
        i = S[i]->cur;
    }
    printf("Null\n");
}
//假设静态链表L已存在，返回静态链表L中数据元素的个数
int Get_length_Static_Link(static_link *S)
{
    int i = S[MAX_SIZE - 1]->cur;
    int n = 0;
    if (i)
    {
        i = S[i]->cur;
        n ++;  
    }
    return n;
}


//在L中第i个元素之前插入新的数据元素
int Insert_Elem_Static_Link(static_link *S, int pos, ElemType elem)
{
    if (pos < 1 || pos > Get_length_Static_Link(S) + 1)
    {
        return 0;
    }
    int j = Malloc_Static_Linklist(S); // 获取空闲分量的下标
    if (j == 0)
    {
        return 0;
    }
    S[j]->data = elem;
    int k = MAX_SIZE - 1; //k首先为最后一个元素的下标，通过k获取第一个结点的位置

    for (int i = 1; i < pos; i++)
    {
        //找到第pos个元素之前的位置
        k = S[k]->cur;
    }
    S[j]->cur = S[k]->cur;//把第pos个元素之前元素的cur赋值给新元素的cur
    S[k]->cur = j;//把新元素的cur赋值给第i个元素之前元素的cur
    return 1;
}

//静态链表的删除操作
//删除静态链表L中第pos个数据元素
int Delete_Elem_Static_Link(static_link *S, int pos)
{
    if (pos < 1 || pos > Get_length_Static_Link(S) - 1)
    {
        return 0;
    }
    int k = MAX_SIZE - 1; // k首先为最后一个元素的下标，通过k获取第一个结点的位置
    
    for (int i = 1; i < pos; i++)
    {
        k = S[i]->cur; //找到第pos个元素的位置
    }
    
    int j  = S[k]->cur; // j为第pos个元素之前元素的cur
    S[k]->cur = S[j]->cur; //将第pos个元素之前的cur赋值第pos个元素的cur

    Free_Static_Linklist(S, j);
    return 1;
}

int main()
{
    static_link *S;
    Init_Static_Link(S);
    Print_Static_Linklist(S);
    return 1;
}


