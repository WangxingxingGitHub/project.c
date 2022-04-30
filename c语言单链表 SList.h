#include<stdio.h>


//创建一个链表节点结构体类型
typedef int SLTDataType;

struct SListNode
{
	SLTDataType data;  //data用来存储数据
	struct SListNode* next;  //一个链表节点结构体类型的指针，指向下一个节点
};


//函数的声明
void SListPrint(struct SListNode* phead);  //打印链表函数的声明

void SListPushback(struct SListNode* phead,SLTDataType x);  //尾插链表函数的声
