#include"SList.h"


void test1()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	SListPrint(plist);  //打印链表函数

	SListPushBack(&plist, 1);  //尾插链表函数
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);  //打印链表函数

	SListPushFront(&plist, 1);  //头插链表函数
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);  //打印链表函数

	SListPopBack(&plist);  //尾删链表函数的声明
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);  //打印链表函数

	SListPopFront(&plist);  //头删链表函数
    SListPopFront(&plist);
    SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);  //打印链表函数
}

void test2()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	SListPushFront(&plist, 1);  //头插链表函数
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);  //打印链表函数

	SListPopBack(&plist);  //尾删链表函数的声明
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);  //打印链表函数
}

void test3()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	SListPushFront(&plist, 1);  //头插链表函数
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);  //打印链表函数

	SListPopFront(&plist);  //头删链表函数
    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);  //打印链表函数
}

void test4()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空
	struct SListNode* pos = NULL;
	int i = 1;

	SListPushFront(&plist, 1);  //头插链表函数
    SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 4);
	SListPrint(plist);  //打印链表函数

	//1.查找
	pos = SListFind(plist, 4);  //查找链表函数
	while(pos != NULL)
	{
		printf("%d的第%d个地址是：%p\n",4,i++,pos);
		pos = SListFind(pos->next, 4);  //从pos指向的下一个节点开始查找
	}
	//2.修改
	pos = SListFind(plist, 3);  //查找链表函数
	while(pos != NULL)
	{
		pos->data = 99;  //将单链表中3修改成99
		pos = SListFind(pos->next, 3);  //从pos指向的下一个节点开始查找
	}
	SListPrint(plist);  //打印链表函数

}

void test5()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	struct SListNode* pos = NULL;
	SListPushFront(&plist, 1);  //头插链表函数
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);  //打印链表函数

	pos = SListFind(plist, 3);  //查找链表函数
	if(pos != NULL)
	{
		SListInsert(&plist,pos,888);
	}
	SListPrint(plist);  //打印链表函数
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}
 
