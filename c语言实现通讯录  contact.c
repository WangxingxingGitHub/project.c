//                                                    contact.c
#include"contact.h"


//初始化通讯录函数的实现
void InitContact(struct Contact* ps)  //ps是指向通讯录con的指针
{
	memset(ps->arr,0,sizeof(ps->arr));  //初始化通讯录好友信息数组
	ps->size = 0;  //初始化当前的好友个数
}

//增加好友信息函数的实现
void AddContact(struct Contact* ps)
{
	if(ps->size == MAX)  //判断通讯录是否存满
	{
		printf("通讯录已满，无法增加好友信息\n");
	}
	else
	{
		printf("请输入你要增加好友的名字：");
		scanf("%s",ps->arr[ps->size].name);  //name是数组名，其本身就是一个地址，不用加&

		printf("请输入你要增加好友的年龄：");
		scanf("%d",&(ps->arr[ps->size].age));  //age是一个整型变量，要加&

		printf("请输入你要增加好友的性别：");
		scanf("%s",ps->arr[ps->size].sex);

		printf("请输入你要增加好友的电话：");
		scanf("%s",ps->arr[ps->size].tele);

		printf("请输入你要增加好友的住址：");
		scanf("%s",ps->arr[ps->size].addr);

		ps->size++;
		printf("添加好友信息成功\n");
	}
}

//显示好友信息函数的实现
void ShowContact(const struct Contact* ps)
{
	if(ps->size==0)  //判断通讯录是否有好友信息
	{
		printf("通讯录为空，没有好友信息\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");
		for(i=0;i<(ps->size);i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->arr[i].name,
				ps->arr[i].age,
				ps->arr[i].sex,
				ps->arr[i].tele,
				ps->arr[i].addr);
		}
	}
}
