//                                                    main.c
#include"contact.h"


void menu()
{
	printf("\n");
	printf("*************************************\n");
	printf("*************************************\n");
	printf("*****    1.add         2.del    *****\n");
	printf("*****    3.search      4.modify *****\n");
	printf("*****    5.show        6.sort   *****\n");
	printf("*****    0.exit                 *****\n");
	printf("*************************************\n");
	printf("*************************************\n");
}

int main()
{
	int input = 0;

	struct Contact con;  //con就是通讯录，包含MAX个好友的信息和已存的好友个数

    InitContact(&con);  //初始化通讯录函数

	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
		case ADD:
			AddContact(&con);  //增加好友信息函数
			break;

		case DEL:
			DleContact(&con);  //删除好友信息函数
			break;

		case SEARCH:
			SearchContact(&con);  //查找好友信息函数
			break;

        case MODIFIY:
			ModifiyContact(&con);  //修改好友信息函数
			break;
			
		case SHOW:
			ShowContact(&con);  //显示好友信息函数
			break;

		case SORT:
			break;

		case EXIT:
			printf("退出通讯录\n");
			break;

		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	}while(input);
	return 0;
}
