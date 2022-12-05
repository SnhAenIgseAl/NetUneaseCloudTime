#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 50
#define MAXSIZE 1000

/*
 * 通讯录管理系统头文件
 * 所有函数操作均以通讯录姓名为主键
 *
 * @Author SnhAenIgseAl
 * @Date 2022.10.22
 * @Test SnhAenIgseAl
 * @version 0.1.0 on 2022.10.22
 *		完成增删改查
 *
 * @version 0.1.1 on 2022.10.23
 *		优化图书信息输出对齐格式
 *
 * @version 0.2.0 on 2022.10.24
 *		添加借书和还书功能
 *		添加了一个彩蛋
 *		添加了几本我比较喜欢的书
 *		修复已知BUG
 *		已摆烂
 *
 * @version 0.3.0 on 2022.11.28
 *		已换皮成通讯录管理系统
 */

//通讯录信息结构
struct Person
{
	char name[MAX_NAME_LEN];	//姓名
	char sex[3];			//性别
	int age;			//年龄
	char phone[12];			//电话
	char address[MAX_NAME_LEN];	//住址
};

//PersonNode结点
struct PersonNode
{
	struct Person data;		//通讯录数据
	struct PersonNode* next;	//指向下一个PersonNode结点
};

/*
 * 分割线
 */
void line()
{
	printf("------------------------------------------------------------------------------------------------\n");
}

/*
 * 通讯录列表格式输出规范
 */
void standardPersonTap()
{
	printf("\n");
	line();
	printf("%-15s", "姓名");
	printf("%-10s", "性别");
	printf("%-10s", "年龄");
	printf("%-20s", "电话");
	printf("%-30s\n", "住址");
	line();
}

/*
 * 通讯录信息格式输出规范
 * 
 * @param PookNode* 目标链表
 */
void standardPrint(struct PersonNode* P)
{
	printf("%-15s", P->data.name);
	printf("%-10s", P->data.sex);
	printf("%-10d", P->data.age);
	printf("%-20s", P->data.phone);
	printf("%-30s\n", P->data.address);
}

/*
 * 打印通讯录信息列表
 * 
 * @param PersonNode* 目标链表
 */
void printPersonList(struct PersonNode* P)
{
	//跳过头结点
	P = P->next;

	standardPersonTap();
	while (P != NULL)
	{
		standardPrint(P);
		P = P->next;
	}
	line();
	printf("\n");
}

/*
 * 初始化头结点，头结点的信息作为彩蛋
 * 
 * @return PersonNode* 结点
 */
struct PersonNode* initPerson()
{
	struct PersonNode* person = (struct PersonNode*)malloc(sizeof(struct PersonNode));

	if (person == NULL)
	{
		printf("结点内存分配失败\n");
		exit(0);
	}

	strcpy_s(person->data.name, "SnhAenIgseAl");
	strcpy_s(person->data.sex, "男");
	person->data.age = 21;
	strcpy_s(person->data.phone, "62040472881");
	strcpy_s(person->data.address, "没地方住哪里都随便");
	person->next = NULL;

	return person;
}

/*
 * 创建PersonNode结点
 * 
 * @return PersonNode* 结点
 */
struct PersonNode* createPersonNode(struct Person data)
{
	struct PersonNode* newNode = (struct PersonNode*)malloc(sizeof(struct PersonNode));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

/*
 * 暴力遍历查找信息是否存在
 * 
 * @param PersonNode* 目标链表
 * @param char[] 姓名
 * @return PersonNode* 存在
 * @return NULL 不存在
 */
struct PersonNode* isFindPerson(struct PersonNode* P, char name[])
{
	while (P != NULL)
	{
		if (strcmp(P->data.name, name) == 0)
		{
			return P;
			break;
		}
		else
		{
			P = P->next;
		}
	}

	return NULL;
}

/*
 * 尾插法添加信息
 * 
 * @param PersonNode* 目标链表
 * @param Person* 数据
 */
void addPerson(struct PersonNode* P, struct Person data)
{
	struct PersonNode* p = P;

	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = createPersonNode(data);
}

/*
 * 根据姓名删除通讯录信息
 * 现在是，网抑时间：
 *	𝅘𝅥 就放手吧，别想她 𝅘𝅥
 *	𝅘𝅥 是否值得你这样牵挂 𝅘𝅥
 *	𝅘𝅥 就放手吧，别想她 𝅘𝅥
 *	𝅘𝅥 爱过就好何必要苦苦挣扎 𝅘𝅥
 *	𝅘𝅥 就放手吧，别想她 𝅘𝅥
 *	𝅘𝅥 把所有一切就当成是一个笑话 𝅘𝅥 
 * 
 * @param PersonNode* 目标链表
 * @param char[] 姓名
 */
void deletePersonByName(struct PersonNode* P, char name[])
{
	struct PersonNode* p = P;
	struct PersonNode* last = P;

	if (strcmp(name, "SnhAenIgseAl") == 0)
	{
		int SnhAenIgseAl[] = { 63416, 54487, 45744, 50106 };	//What's this?
		int len = sizeof(SnhAenIgseAl) / sizeof(SnhAenIgseAl[0]);
		int* p = SnhAenIgseAl;

		for (int i = 0; i < len; i++)
		{
			printf("%s", p);
			p++;
		}
		printf("\n\n");
	}
	else
	{
		if (isFindPerson(p, name))
		{
			while (p != NULL)
			{
				if (strcmp(p->data.name, name) == 0)
				{
					last->next = p->next;
					delete p;
					p = NULL;
					printf("删除成功\n");
					printPersonList(P);
					printf("\n");
					break;
				}
				else
				{
					last = p;		//记录上一个结点的地址
					p = p->next;
				}
			}
		}
		else
		{
			printf("删除失败，信息不存在\n\n");
		}
	}
}

/*
 * 删除所有联系人信息
 * 口罩一戴，谁都不爱
 * 
 * @param PersonNode* 目标链表
 */
void deleteAllPerson(struct PersonNode* P)
{
	struct PersonNode* p;
	struct PersonNode* q;

	p = P->next;		//已经跳过了头结点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	P->next = NULL;

	printf("全部删除成功\n");
	printPersonList(P);
	printf("\n");
}


/*
 * 根据姓名更改通讯录信息
 * 
 * @param PersonNode* 目标链表
 * @param char[] 姓名
 * @param char[] 性别
 * @param int 年龄
 * @param char[] 电话
 * @param char[] 家庭住址
 */
void changePersonByName(struct PersonNode* P, char name[], char sex[], int age, char phone[], char address[])
{
	//跳过头结点
	P = P->next;

	if (P = isFindPerson(P, name))
	{
		strcpy_s(P->data.name, name);
		strcpy_s(P->data.sex, sex);
		P->data.age = age;
		strcpy_s(P->data.phone, phone);
		strcpy_s(P->data.address, address);
		printf("更改成功\n");
		standardPersonTap();
		standardPrint(P);
		line();
		printf("\n");
	}
	else
	{
		printf("更改失败，信息不存在\n\n");
	}
}

/*
 * 根据姓名查询通讯录信息
 * 
 * @param PookNode* 目标链表
 * @param char[] 姓名
 */
void selectPersonByName(struct PersonNode* P, char name[])
{
	if (P = isFindPerson(P, name))
	{
		printf("查找成功\n");
		standardPersonTap();
		standardPrint(P);
		line();
		printf("\n");
	}
	else
	{
		printf("查找失败，信息不存在\n\n");
	}
}
