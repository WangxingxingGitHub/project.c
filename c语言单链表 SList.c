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
void SListPushBack(struct SListNode** pphead,SLTDataType x)
{	
	struct SListNode* ps ;
	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

    //2.将新节点进行尾接
	  //说明链表为空
	if(*pphead == NULL)  
	{
		*pphead = newnode;  //把头指针指向newnode
	}
      //链表不为空，要找到最后一个尾节点
	else
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
void SListPushFront(struct SListNode** pphead, SLTDataType x)
{
	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

	//2.将新节点进行头插
	newnode->next = *pphead;
	*pphead = newnode;
}


//尾删链表函数的实现
void SListPopBack(struct SListNode** pphead)
{
	struct SListNode* prev = NULL;
	struct SListNode* ps = *pphead;  //找尾指针
	//1.没有节点的情况
	//if(*pphead == NULL) //plist指针为空，说明链表为空
	//{
	//	return;
	//}
	assert(*pphead != NULL);  //断言，若plist为空就报错

	//2.只有一个节点的情况
	if((*pphead)->next == NULL)
	{
		free(*pphead);  //释放plit指向的空间
		*pphead = NULL;  //将plist指针置空
	}

	//3.多个节点的情况
	else
	{
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
void SListPopFront(struct SListNode** pphead)
{
	struct SListNode* ps = *pphead;
	//1.单链表没有节点
	assert(*pphead);
	//2.单链表有节点
	*pphead = ps->next;
	free(ps);
	ps = NULL;
}


//查找链表函数的实现
struct SListNode* SListFind(struct SListNode* phead, SLTDataType x)
{
	struct SListNode* cur = phead;  //定义一个指针指向首节点
	while(cur)
	{
		if(cur->data == x)
		{
			return cur;  //找到了返回指向该节点的指针
		}
		cur = cur->next;
	}
	return NULL;  //找不到返回NULL
}


//在pos指针位置之前去插入一个节点函数的实现
void SListInsert(struct SListNode** pphead, struct SListNode* pos, SLTDataType x)
{
	struct SListNode* posPrev = *pphead; 
	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

	//2.将新节点进行插入
	  //pos指向首节点时
	if(pos == *pphead)
	{
		*pphead = newnode;
		newnode->next = pos;
	}
	  //pos指向首节点后面的节点时
	else
	{
		//找到指向pos前一个节点的指针posPrev
		while(posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		//此时posPrev是指向pos前一个节点的指针,将新节点进行插入
		posPrev->next = newnode;
		newnode->next = pos;
	}
}

//在pos指针位置之后去插入一个节点函数的实现
void SListInsertAfter(struct SListNode* pos, SLTDataType x)
{
	//1.创建一个新节点，需要扩容malloc
	struct SListNode* newnode = CreateListNode(x);  //创建节点函数

	//2.将新节点进行插入
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos指针指向的节点函数的实现
void SListErase(struct SListNode** pphead, struct SListNode* pos)
{
	struct SListNode* prev = *pphead;
	if(pos == *pphead)  //pos指针指向首节点时
	{
		*pphead = pos->next;
		free(pos);
	}

	else  //pos指针指向首节点后的节点时
	{
		while(prev->next != pos)
		{
			prev = prev->next;
		}
		//此时prev指针指向pos指针前一个节点
		prev->next = pos->next;
		free(pos);
	}
}

//删除pos指针指向的后一个节点函数的实现
void SListEraseAfter(struct SListNode* pos)
{
	assert(pos);
	assert(pos->next);  //pos指针后面有节点可以删

	struct SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//销毁链表函数的实现
void SListDestory(struct SListNode** pphead)
{
	assert(pphead);

	struct SListNode* pos = *pphead;
	struct SListNode* next = NULL;
	while(pos != NULL)
	{
		next = pos->next;  //保存pos指针后一个节点的地址
		free(pos);
		pos = next;
	}
	*pphead = NULL;
}
   
