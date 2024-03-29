#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//定义一个栈的结构体类型
typedef int STDateType;
typedef struct Stack
{
	STDateType* a;  //指针指向开辟的一段空间
	int top;
	int capacity;
}ST;

//函数的声明
void StackInit(ST* ps);  //初始化函数

void StackPush(ST* ps, STDateType x);  //入栈函数

STDateType StackTop(ST* ps);  //读栈顶数据

void StackPop(ST* ps);  //删除栈顶数据

bool StackEmpty(ST* ps);  //判断栈是否为空

void StackDestroy(ST* ps);  //销毁栈


