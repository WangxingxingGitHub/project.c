#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//创建一个链表节点结构体类型
typedef int SLTDataType;  //SLTDataType是存储数据的数据类型

struct SListNode
{
	SLTDataType data;  //data是存储的数据
	struct SListNode* next;  //一个链表节点结构体类型的指针，指向下一个节点
};



//函数的声明
void SListPrint(struct SListNode* phead);  //打印链表函数的声明

void SListPushback(struct SListNode** pphead, SLTDataType x);  //尾插链表函数的声明

void SListPushfront(struct SListNode** pphead, SLTDataType x);  //头插链表函数的声明

void SListPopback(struct SListNode** pphead);  //尾删链表函数的声明

void SListPopfront(struct SListNode** pphead);  //头删链表函数的声明

