//                                                    SeqList.h
#include<stdio.h>
#include<string.h>
#include<assert.h>


////      静态顺序表
////创建一个顺序表结构体类型
//#define MAX 1000  //数组arr元素个数
//typedef int SLDataType;  //将数组元素的类型改名为SLDataType
//
//typedef struct SeqList  //结构体类型sL
//{
//	SLDataType arr[MAX];
//	int size;  //表示数组已存的元素个数
//}sL;
//静态顺序表特点：数组大小固定，存满数据后不能继续存储数据，不能扩容



//      动态顺序表
//创建一个顺序表结构体类型,包括一个指针，已存元素个数，空间容量大小
typedef int SLDataType;  //将数组元素的类型改名为SLDataType

typedef struct SeqList
{
	 SLDataType * p;  //指针指向动态开辟的一个内存空间
	 int size;  //表示数组已存的元素个数
	 int capacity;  //表示数组实际能存的元素个数
}sL;



//接口函数的声明
void SeqListInit(sL* ps);  //初始化顺序表函数的声明

void SeqListPrint(sL* ps);  //打印顺序表函数的声明

void SeqListDestory(sL* ps);  //销毁顺序表函数的声明

void SeqListPushBack(sL* ps,SLDataType x);  //尾插顺序表函数的声明

void SeqListPopBack(sL* ps);  //尾删顺序表函数的声明

void SeqListPushFront(sL* ps,SLDataType x);  //头插顺序表函数的声明

void SeqListPopFront(sL* ps);  //头删顺序表函数的声明

void SeqListInsert(sL* ps,int pos,SLDataType x);  //pos下标插入函数的声明

void SeqListErase(sL* ps,int pos);  //pos下标删除函数的声明

int SeqListFind(sL* ps,SLDataType x);  //查找顺序表函数的声明

