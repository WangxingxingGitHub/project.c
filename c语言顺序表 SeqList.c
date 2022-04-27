//                                                    SeqList.c
#include"seqList.h"


//检查空间容量函数的实现
static void SeqListCheckCapacity(sL* ps)  //static修饰，不希望函数在外部使用
{
	//判断是否有内存空间或内存空间满了,没有或者满了就扩容
	if(ps->size == ps->capacity)
	{
		int newcapacity = (ps->capacity == 0 ? 4 :(ps->capacity)*2); 

		SLDataType* tem = (SLDataType*)realloc(ps->p,newcapacity*sizeof(SLDataType));

		if(tem == NULL)  //扩容失败
		{
			printf("扩容失败\n");
		    exit(-1);  //异常退出		
		}

		ps->p = tem;  // 扩容成功
		ps->capacity = newcapacity;
	}
}



//接口函数的实现
//初始化顺序表函数的实现
void SeqListInit(sL* ps)  
{
	ps->p = NULL;  //指针置空
	ps->size = 0;
	ps->capacity = 0;  
}

//打印顺序表函数的实现
void SeqListPrint(sL* ps)
{
	if(ps->size == 0)  //顺序表没有存储元素
	{
		printf("没有要打印的内容\n");
	}
	else  //顺序表存有元素
	{
		int i = 0;
		for(i=0;i<(ps->size);i++)
		{
			printf("%d  ",ps->p[i]);
		}
		printf("\n");
	}
}

//销毁顺序表函数的实现
void SeqListDestory(sL* ps)
{
	free(ps->p);  //释放指针指向的内存空间
	ps->capacity = 0;
	ps->size = 0;
}

//尾插顺序表函数的实现
void SeqListPushBack(sL* ps,SLDataType x)  
{
	//检查内存空间容量
	SeqListCheckCapacity(ps);
	//有内存空间并且没满就尾插
	ps->p[ps->size] = x;
	ps->size++;
}

//尾删顺序表函数的实现
void SeqListPopBack(sL* ps)  
{
	if(ps->size > 0)  //确保有数据可删，防止越界访问
	{
		ps->p[ps->size-1] = 0;
		ps->size--;
	}
}

//头插顺序表函数的实现
void SeqListPushFront(sL* ps,SLDataType x)  
{
	int i = 0;
	for(i=(ps->size);i>=0;i--)
	{
		ps->p[i+1] = ps->p[i];
	}
	ps->p[0] = x;
	ps->size++;
}

//头删顺序表函数的实现
void SeqListPopFront(sL* ps)  
{
	if(ps->size > 0)
	{
		int i = 0;
		for(i=0;i<ps->size-1;i++)
		{
			ps->p[i] = ps->p[i+1];
		}
		ps->size--;
	}
}

