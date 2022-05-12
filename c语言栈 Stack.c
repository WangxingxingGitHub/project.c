#include"stack.h"

//函数的实现
void StackInit(ST* ps)  //初始化函数
{
	assert(ps);

	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void StackPush(ST* ps, STDateType x)  //入栈函数
{
	assert(ps);

	if(ps->capacity == ps->top)  //说明栈空间用完或者没有空间
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		STDateType* tmp = (STDateType*)realloc(ps->a,sizeof(STDateType)*newcapacity);
		if(tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		//扩容成功
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

STDateType StackTop(ST* ps)  //读栈顶数据
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top-1];
}

void StackPop(ST* ps)  //删除栈顶数据
{
	assert(ps);
	assert(ps->top > 0);  //确保栈内有数据可删

	ps->a[ps->top-1] = 0;
	ps->top--;
}

bool StackEmpty(ST* ps)  //判断栈是否为空
{
	assert(ps);

	if(ps->top == 0)
		return true;  //栈为空返回逻辑真
	else
		return false;  //栈不为返回逻辑假
}

void StackDestroy(ST* ps)  //销毁栈
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
