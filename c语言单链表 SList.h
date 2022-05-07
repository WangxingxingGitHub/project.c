#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//创建一个单链表节点结构体类型
typedef int SLTDataType;  //SLTDataType是存储数据的数据类型

struct SListNode
{
	SLTDataType data;  //data是存储的数据
	struct SListNode* next;  //一个单链表节点结构体类型的指针，指向下一个节点
};



//函数的声明
//打印链表函数的声明
void SListPrint(struct SListNode* phead);  

//尾插链表函数的声明
void SListPushBack(struct SListNode** pphead, SLTDataType x); 

//头插链表函数的声明
void SListPushFront(struct SListNode** pphead, SLTDataType x);  

//尾删链表函数的声明
void SListPopBack(struct SListNode** pphead);  

//头删链表函数的声明
void SListPopFront(struct SListNode** pphead);  

//查找链表函数的声明
struct SListNode* SListFind(struct SListNode* phead, SLTDataType x);  

//在pos指针位置之前去插入一个节点函数的声明
void SListInsert(struct SListNode** pphead,struct SListNode* pos, SLTDataType x);

//在pos指针位置之后去插入一个节点函数的声明
void SListInsertAfter(struct SListNode* pos, SLTDataType x);

//删除pos指针指向的节点函数的声明
void SListErase(struct SListNode** pphead, struct SListNode* pos);

//删除pos指针指向的后一个节点函数的声明
void SListEraseAfter(struct SListNode* pos);

//销毁链表函数的声明
void SListDestory(struct SListNode** pphead);
  
  
