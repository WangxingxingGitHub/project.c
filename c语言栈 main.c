#include"stack.h"

void test1()
{
	ST stack;

	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	Stackprint(&stack);

	StackPop(&stack);
	StackPop(&stack);
	StackPop(&stack);
	Stackprint(&stack);
}

int main()
{
	test1();

	return 0;
}
