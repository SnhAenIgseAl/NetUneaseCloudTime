#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "AddressBook.h"

/*
* ͨѶ¼����ϵͳ��������
*
* @Author SnhAenIgseAl
* @Date 2022.11.28
* @Test SnhAenIgseAl
*/

int main()
{
	struct Person person;
	struct PersonNode* P = initPerson();

	char name[MAX_NAME_LEN];		//����
	char sex[3];					//�Ա�
	int age;						//����
	char phone[15];					//�绰
	char address[MAX_NAME_LEN];		//סַ
	int choose;						//����ѡ��

	//������ĺõļ�����
	person = { "��ˮˮ", "Ů", 24, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "����", "Ů", 21, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "��ǰ", "Ů", 17, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "PDD", "Ů", 19, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "����", "Ů", 18, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "����", "Ů", 17, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "����", "Ů", 18, "��֪��", "��֪��" };
	addPerson(P, person);
	person = { "����", "Ů", 19, "��֪��", "��֪��" };
	addPerson(P, person);

	printf("--------------------------------------SnhAenIgseAl��ͨѶ¼--------------------------------------\n");
	printPersonList(P);
	do
	{
		printf("���������ѡ�\n");
		printf("1.�����Ϣ\n");
		printf("2.������ɾ����Ϣ\n");
		printf("3.������������Ϣ\n");
		printf("4.��������ѯ��Ϣ\n");
		printf("5.��ӡͨѶ¼�б�\n");
		printf("6.ɾ��������ϵ�ˣ�\n");
		printf("7.�˳�\n");
		line();

		scanf_s("%d", &choose);

		switch (choose)
		{
			case 1:
				printf("�������������Ա����䡢�绰��סַ��\n");
				scanf_s("%s %s %d %s %s", person.name, MAX_NAME_LEN, person.sex, 3, &person.age, person.phone, 12, person.address, MAX_NAME_LEN);
				addPerson(P, person);
				printPersonList(P);
				break;

			case 2:
				printf("������Ҫɾ������Ϣ��������");
				scanf_s("%s", name, MAX_NAME_LEN);
				deletePersonByName(P, name);
				break;

			case 3:
				printf("������Ҫ���ĺ���������Ա����䡢�绰��סַ��\n");
				scanf_s("%s %s %d %s %s", name, MAX_NAME_LEN, sex, 3, &age, phone, 12, address, MAX_NAME_LEN);
				changePersonByName(P, name, sex, age, phone, address);
				break;

			case 4:
				printf("������Ҫ���ҵ���Ϣ��������");
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
				printf("����Ĳ���ѡ�����\n");
				line();
				printf("\n");
				break;
		}
	} while (choose != NULL);

	system("pause");
	return 0;
}