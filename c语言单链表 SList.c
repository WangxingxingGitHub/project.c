#include"SList.h"


//创建节点函数的实现
struct SListNode* CreateListNode(SLTDataType x)
{
	struct SListNode* newnode = (struct SListNode*)malloc(sizeof(struct SListNode));
	//newnode是一个指向新开辟的内存的指针，该内存是一个节点
	if(newnode == NULL)  //开辟空间失败
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}


//打印链表函数的实现
void SListPrint(struct SListNode* phead)
{
	struct SListNode* ps = phead;  //定义一个指针使其指向链表的首个节点
	while(ps != NULL)
	{
		printf("%d ->",ps->data);  //打印数据data
		ps = ps->next;  //使ps指针指向下一个节点
	}
	printf("NULL\n");
}


//尾插链表函数的实现
void SListPushback(struct SListNode** pphead,SLTDataType x)
{	
	struct SListNode* ps ;

	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

    //2.将新节点进行链接
	if(*pphead == NULL)  //说明链表为空
	{
		*pphead = newnode;  //把头指针指向newnode
	}

	else  //链表不为空，要找到最后一个尾节点
	{ 
		ps = *pphead;  //使指针指向链表的首个节点
		while(ps->next != NULL)  //尾节点标志是next指针为NULL
		{
			ps = ps->next;  //使ps指针指向下一个节点
		}
		//此时ps是指向最后一个节点的指针
		ps->next = newnode;	//将最后一个节点的指针next指向新节点newnode  
	}
}


//头插链表函数的实现
void SListPushfront(struct SListNode** pphead, SLTDataType x)
{
	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

	newnode->next = *pphead;
	*pphead = newnode;
}


//尾删链表函数的实现
void SListPopback(struct SListNode** pphead)
{
	struct SListNode* prev;
	struct SListNode* ps;
	//没有节点的情况
	if(*pphead == NULL) //plist指针为空，说明链表为空
	{
		return;
	}
	//assert(*pphead != NULL);  断言，若plist为空就报错

	//只有一个节点的情况
	if((*pphead)->next == NULL)
	{
		free(*pphead);  //释放plit指向的空间
		*pphead = NULL;  //将plist指针置空
	}

	//多个节点的情况
	else
	{
		`ps = *pphead;
		while(ps->next != NULL)
		{
			prev = ps;
			ps = ps->next;
		}
		//此时ps是指向尾节点的指针,prev是指向尾节点前一个节点的指针
		free(ps);
		ps = NULL;
		prev->next = NULL;  //尾节点前一个节点的next指针置空
	}
}


//头删链表函数的实现
void SListPopfront(struct SListNode** pphead)
{

}
