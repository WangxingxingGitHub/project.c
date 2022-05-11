#include"stack.h"

void test1()
{
	ST stack;

	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);

	printf("%d ",StackTop(&stack));
	StackPop(&stack);

	StackPush(&stack, 3);
	StackPush(&stack, 4);

	while(!StackEmpty(&stack))
	{
		printf("%d ",StackTop(&stack));
		StackPop(&stack);
	}

	StackDestroy(&stack);
}

int main()
{
	test1();

	return 0;
}
