//                                                    contact.h 
#include<stdio.h>
#include<string.h>


#define MAX 1000  //通讯录数组的元素个数
#define MAX_name 20     
#define MAX_sex 5
#define MAX_tele 12
#define MAX_addr 30

//通讯录好友的信息
struct Peoinfo
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
	char addr[MAX_addr];
};


//创建一个通讯录类型
struct Contact       
{
	struct Peoinfo arr[MAX];  //通讯录好友信息数组，包含MAX个通讯录好友的信息
	int size;  //记录通讯录当前的好友个数
};

