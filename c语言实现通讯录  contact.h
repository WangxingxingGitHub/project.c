//                                                    contact.h 
#include<stdio.h>
#include<string.h>


//创建一个通讯录类型
#define MAX 1000  //通讯录好友信息数组的元素个数
#define MAX_name 20     
#define MAX_sex 5
#define MAX_tele 12
#define MAX_addr 30

struct Peoinfo  //通讯录好友信息结构体类型
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
	char addr[MAX_addr];
};

struct Contact  //创建通讯录类型    
{
	struct Peoinfo arr[MAX];  //通讯录好友信息数组，包含MAX个好友，数组元素数据类型为通讯录好友信息结构体类型
	int size;  //记录通讯录已存的好友个数
};


//创建一个枚举常量
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFIY,
	SHOW,
	SORT
};


//函数的声明
void InitContact(struct Contact* ps);  //初始化通讯录函数的声明

void AddContact(struct Contact* ps);  //增加好友信息函数的声明

void ShowContact(const struct Contact* ps);  //显示好友信息函数的声明  //const有保护作用，不希望被修改

void DleContact(struct Contact* ps);  //删除好友信息函数的声明

void SearchContact(const struct Contact* ps);  //查找好友信息函数的声明

void ModifiyContact(struct Contact* ps);  //修改好友信息函数的声明
