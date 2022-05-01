#include"SList.h"


//打印链表函数的实现
void SListPrint(struct SListNode* phead)
{
	struct SListNode* ps = phead;  //定义一个指针使其指向链表的首个节点
	while(ps != NULL)
	{
		printf("%d  ",ps->data);  //打印数据data
		ps = ps->next;  //使ps指针指向下一个节点
	}
}

//尾插链表函数的实现
void SListPushback(struct SListNode* phead,SLTDataType x)
{
	//1.找到最后一个节点
	struct SListNode* ps = phead;  //定义一个指针使其指向链表的首个节点
	while(ps->next != NULL)
	{
		ps = ps->next;  //使ps指针指向下一个节点
	}
	//此时ps是指向最后一个节点的指针

	//2.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = (struct SListNode*)malloc(sizeof(struct SListNode));
	//newnode是一个指向新开辟的内存的指针，该内存也是一个节点
	newnode->data = x;
	newnode->next = NULL;

	//3.将原先最后一个节点的指针next指向新节点  ps->next = newnode

}

