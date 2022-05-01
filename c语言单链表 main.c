#include"SList.h"


void test1()
{
	struct SListNode* plist = NULL;  //初始化链表，将指针置空
	SListPushback(plist, 1);  //尾插链表函数
	SListPushback(plist, 2);
	SListPushback(plist, 3);
	SListPushback(plist, 4);
}

int main()
{
	test1();

	return 0;
}

