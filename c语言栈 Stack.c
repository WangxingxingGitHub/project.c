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

void StackPop(ST* ps)  //删除栈顶数据
{
	assert(ps);
	assert(ps->top > 0);  //确保栈内有数据可删

	ps->a[ps->top-1] = 0;
	ps->top--;
}

void Stackprint(ST* ps)  //打印函数
{
	int i = 0;
	assert(ps);

	for(i=0;i<ps->top;i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}
