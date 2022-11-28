#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "AddressBook.h"

/*
* 通讯录管理系统交互界面
*
* @Author SnhAenIgseAl
* @Date 2022.11.28
* @Test SnhAenIgseAl
*/

int main()
{
	struct Person person;
	struct PersonNode* P = initPerson();

	char name[MAX_NAME_LEN];		//姓名
	char sex[3];					//性别
	int age;						//年龄
	char phone[15];					//电话
	char address[MAX_NAME_LEN];		//住址
	int choose;						//操作选项

	//高中玩的好的家人们
	person = { "冯水水", "女", 24, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿游", "女", 21, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿前", "女", 17, "不知道", "不知道" };
	addPerson(P, person);
	person = { "PDD", "女", 19, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿蛇", "女", 18, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿田", "女", 17, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿豪", "女", 18, "不知道", "不知道" };
	addPerson(P, person);
	person = { "阿鹏", "女", 19, "不知道", "不知道" };
	addPerson(P, person);

	printf("--------------------------------------SnhAenIgseAl的通讯录--------------------------------------\n");
	printPersonList(P);
	do
	{
		printf("请输入操作选项：\n");
		printf("1.添加信息\n");
		printf("2.按姓名删除信息\n");
		printf("3.按姓名更改信息\n");
		printf("4.按姓名查询信息\n");
		printf("5.打印通讯录列表：\n");
		printf("6.删除所有联系人：\n");
		printf("7.退出\n");
		line();

		scanf_s("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("请输入姓名、性别、年龄、电话、住址：\n");
				scanf_s("%s %s %d %s %s", person.name, MAX_NAME_LEN, person.sex, 3, &person.age, person.phone, 12, person.address, MAX_NAME_LEN);
				addPerson(P, person);
				printPersonList(P);
				break;

			case 2:
				printf("请输入要删除的信息的姓名：");
				scanf_s("%s", name, MAX_NAME_LEN);
				deletePersonByName(P, name);
				break;

			case 3:
				printf("请输入要更改后的姓名、性别、年龄、电话、住址：\n");
				scanf_s("%s %s %d %s %s", name, MAX_NAME_LEN, sex, 3, &age, phone, 12, address, MAX_NAME_LEN);
				changePersonByName(P, name, sex, age, phone, address);
				break;

			case 4:
				printf("请输入要查找的信息的姓名：");
				scanf_s("%s", name, MAX_NAME_LEN);
				selectPersonByName(P, name);
				break;

			case 5:
				printPersonList(P);
				break;

			case 6:
				deleteAllPerson(P);
				break;

			case 7:
				exit(0);
				break;

			default:
				printf("输入的操作选项不存在\n");
				line();
				printf("\n");
				break;
		}
	} while (choose != NULL);

	system("pause");
	return 0;
}