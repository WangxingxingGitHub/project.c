//                                                    contact.c
#include"contact.h"


//查找函数的实现
static int Findbyname(const struct Contact* ps,char name[MAX_name])  //static修饰，不希望函数在外部被使用
{
	int i = 0;
	for(i=0;i<(ps->size);i++)
	{
		if(strcmp(name,ps->arr[i].name)==0)  //在通讯录中找到了该好友
		{
		      return i;  //返回此时该好友的下标值i
		}
	}
	return -1;  //在通讯录中找不到该好友，返回-1
}


//接口函数的实现
//初始化通讯录函数的实现
void InitContact(struct Contact* ps)  //ps是指向通讯录con的指针
{
	memset(ps->arr,0,sizeof(ps->arr));  //初始化通讯录好友信息数组
	ps->size = 0;  //初始化当前的好友个数
}

//增加好友信息函数的实现
void AddContact(struct Contact* ps)
{  
	//判断通讯录是否存满
	if(ps->size == MAX)  //满了
	{
		printf("通讯录已满，无法增加好友信息\n");
	}
	else  //没满
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
	//判断通讯录是否有好友信息
	if(ps->size==0)  //没有好友信息  
	{
		printf("通讯录为空，没有好友信息\n");
	}
	else  //有好友信息
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n",
			   "名字","年龄","性别","电话","地址");  //标题格式
		for(i=0;i<(ps->size);i++)  //显示信息
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

//删除好友信息函数的实现
void DleContact(struct Contact* ps)
{
	int ret = 0;
	char name[MAX_name] = {0};
	printf("请输入你要删除好友的名字：");
	scanf("%s",name);

	//1.在通讯录中查找要删除的好友
	ret = Findbyname(ps,name);

	//2.判断查找函数查找后的结果
	if(ret == -1)  //说明通讯录中没有该好友
	{
		printf("通讯录中没有要删除的好友的信息，无法删除\n");
	}
	else  //说明通讯录中有该好友，进行删除
	{
		int j = 0;
		for(j=ret;j<=ps->size-2;j++)
		{
			ps->arr[j]=ps->arr[j+1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

//查找好友信息函数的实现
void SearchContact(const struct Contact* ps)
{
	int ret = 0;
	char name[MAX_name] = {0};
	printf("请输入你要查找好友的名字：");
	scanf("%s",name);

	//1.在通讯录中查找要查询的好友
	ret = Findbyname(ps,name);

	//2.判断查找函数查找后的结果
	if(ret == -1)  //说明通讯录中没有该好友
	{
		printf("通讯录中没有该好友的信息\n");
	}
	else  //说明通讯录中有该好友,进行打印
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");  //标题格式
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",  //显示信息
				ps->arr[ret].name,
				ps->arr[ret].age,
				ps->arr[ret].sex,
				ps->arr[ret].tele,
				ps->arr[ret].addr);
	}
}

//修改好友信息函数的实现
void ModifiyContact(struct Contact* ps)
{
	int ret = 0;
	char name[MAX_name] = {0};
	printf("请输入你要修改好友的名字：");
	scanf("%s",name);

	//1.在通讯录中查找要查询的好友
	ret = Findbyname(ps,name);

	//2.判断查找函数查找后的结果
	if(ret == -1)  //说明通讯录中没有该好友
	{
		printf("通讯录中没有要修改好友的信息，无法进行修改\n");
	}
	else
	{
		printf("请输入修改后的名字");
		scanf("%s",ps->arr[ret].name);

		printf("请输入修改后的年龄");
		scanf("%d",&(ps->arr[ret].age));

		printf("请输入修改后的性别");
		scanf("%s",ps->arr[ret].sex);

		printf("请输入修改后的电话");
		scanf("%s",ps->arr[ret].tele);

		printf("请输入修改后的住址");
		scanf("%s",ps->arr[ret].addr);

		printf("修改好友信息成功\n");
	}
}


