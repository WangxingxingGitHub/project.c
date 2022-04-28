//                                                    main.c
#include"seqList.h"


void test1()
{
	sL s1;  //定义一个顺序表s1，数据类型为顺序表结构体类型

	SeqListInit(&s1);  //初始化顺序表函数
	SeqListPrint(&s1);  //打印顺序表函数


	SeqListPushBack(&s1,1);  //尾插顺序表函数
	SeqListPushBack(&s1,2);
    SeqListPushBack(&s1,3);
	SeqListPushBack(&s1,4);
	SeqListPushBack(&s1,5);
	SeqListPrint(&s1);  //打印顺序表函数


	SeqListPopBack(&s1);  //尾删顺序表函数
	SeqListPrint(&s1);    //打印顺序表函数


	SeqListPushFront(&s1,10);  //头插顺序表函数
	SeqListPushFront(&s1,20);
	SeqListPushFront(&s1,30);
	SeqListPushFront(&s1,40);
	SeqListPushFront(&s1,50);
	SeqListPrint(&s1);  //打印顺序表函数


	SeqListPopFront(&s1);  //头删顺序表函数
	SeqListPrint(&s1);  //打印顺序表函数

	SeqListInsert(&s1,8,99);  //pos下标插入函数
	SeqListPrint(&s1);  //打印顺序表函数

	SeqListErase(&s1,8);//pos下标删除函数
	SeqListPrint(&s1);  //打印顺序表函数



	//SeqListPrint(&s1);  //销毁顺序表函数
}


void test2()
{
	int pos = 0;
	sL s1;  //定义一个顺序表s1，数据类型为顺序表结构体类型

	SeqListInit(&s1);  //初始化顺序表函数
	SeqListPrint(&s1);  //打印顺序表函数


	SeqListPushBack(&s1,1);  //尾插顺序表函数
	SeqListPushBack(&s1,2);
        SeqListPushBack(&s1,3);
	SeqListPushBack(&s1,4);
	SeqListPushBack(&s1,5);
	SeqListPrint(&s1);  //打印顺序表函数

	pos = SeqListFind(&s1,5);  //查找顺序表函数
	if(pos != -1)
	{
		SeqListErase(&s1,pos);  //pos下标删除函数
	}
	SeqListPrint(&s1);  //打印顺序表函数
}


int main()
{
	//test1();
	test2();

	return 0;
}

