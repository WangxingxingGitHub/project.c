#include"SList.h"


void test1()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	SListPushback(&plist, 1);  //尾插链表函数
	SListPushback(&plist, 2);
	SListPushback(&plist, 3);
	SListPushback(&plist, 4);
	SListPrint(plist);  //打印链表函数

	SListPushfront(&plist, 1);  //头插链表函数
	SListPushfront(&plist, 2);
	SListPushfront(&plist, 3);
	SListPushfront(&plist, 4);
	SListPrint(plist);  //打印链表函数
}

void test2()
{
	struct SListNode* plist = NULL;  //初始化链表，将plist指针置空

	SListPushfront(&plist, 1);  //头插链表函数
	SListPushfront(&plist, 2);
	SListPushfront(&plist, 3);
	SListPushfront(&plist, 4);
	SListPrint(plist);  //打印链表函数
}


int main()
{
	//test1();
	test2();

	return 0;
}
 
