// 线性表的链式存储实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#define ElementType int
#define MAXSIZE 10
typedef struct LNode* List;
struct LNode {
    ElementType Data;
    List Next;
};
struct Lnode L;
List PtrL;

//1.求表长
int Length(List PtrL)
{   List p = PtrL;      /*p指向表的第一个结点*/
    int j = 0;
    while (p) {
        p = p->Next;    /*当前p指向的是第j个结点*/
        j++;
    }
    return j;
}
//时间复杂度为O(n)

//2.查找
//(1)按序号查找：FindKth;
List FindKth(int K, List PtrL)
{   List p = PtrL;
    int i = 1;
    while (p != NULL && i < K) {
        p = p->Next;
        i++;
    }
    if (i == K)return p;    /*找到第K个，返回指针*/
    else return NULL;       /*否则返回空*/
}
//(2)按值查找：Find;
List Find(ElementType X, List PtrL)
{   List p = PtrL;
    while (p != NULL && p->Data != X)
    p = p->Next;
    return p;
}

//3.插入（在第i-1(l<=i<=n+1)个结点后插入一个值为X的新结点）
//(1)先构造一个新结点，用s指向；
//(2)再找到链表的第i-1个结点，用p指向；
//(3)然后修改指针，插入结点（p之后插入新结点是s）
List Insert(ElementType X, int i, List Ptrl) 
{   List p, s;
    if (i == 1) {                                   /*新结点插入在表头*/
        s = (List)malloc(sizeof(struct LNode));     /*申请、填装结点*/
        s->Data = X;
        s->Next = PtrL;
        return s;                                   /*返回新表头指针*/
    }
    p = FindKth(i - 1, PtrL);                       /*查找第i-1个结点*/
    if (p == NULL) {                                /*第i-1个不存在，不能插入*/
        printf("参数i错");
        return NULL;
    }
    else {
        s = (List)malloc(sizeof(struct LNode));     /*申请、填装结点*/
        s->Data = X;
        s->Next = p->Next;                          /*新结点插入在第i-1个结点的后面*/
        p->Next = s;
        return PtrL;
    }
}
//平均查找次数为n/2

//4.删除（删除链表的第i(l<=i<=n)个位置上的结点)
//(1)先找到链表的第i-1个结点，用p指向；
//(2)再用指针s指向要被删除的结点（p的下一个结点）；
//(3)然后修改指针，删除s所指结点；
//(4)最后释放s所指结点的空间。
List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1) {                                   /*若要删除的是表的第一个结点*/
        s = PtrL;                                   /*s指向第1个结点*/
        if (PtrL != NULL) PtrL = PtrL->Next;        /*从链表中删除*/
        else return NULL;
        free(s);                                    /*释放被删除结点*/
        return PtrL;
    }
    p = FindKth(i-1, PtrL);                         /*查找第i-1个结点*/
    if (p == NULL) {                                /*第i-1个不存在，不能插入*/
        printf("第%d个结点不存在",i - 1);    return NULL;
    }
    else if (p->Next == NULL) {
        printf("第%d个结点不存在", i);    return NULL;
    }
    else{
        s = p->Next;                                /*s指向第i个结点*/
        p->Next = s->Next;                          /*从链表中删除*/
        free(s);                                    /*释放被删除结点*/
        return PtrL;
    }
}

int main()
{
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
