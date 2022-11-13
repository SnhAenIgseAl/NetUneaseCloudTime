#include <stdio.h>
#include <windows.h>
#include "Vigen��reCipher.h"

/*
 * ά����������ļ�������ܽ�������
 * @Author SnhAenIgseAl
 * @Date 2022.11.12
 */

int main()
{
	char src[MAXSIZE];		//���Ļ�����
	char key[MAXSIZE];		//��Կ
	int choose;				//����ѡ��

	do
	{
		printf("���������Ļ����ģ�");
		scanf_s("%s", src, MAXSIZE);
		printf("��������Կ��");
		scanf_s("%s", key, MAXSIZE);
		printf("���������ѡ�\n1.����\t2.����\t3.�˳�\n");
		scanf_s("%d", &choose);

		switch (choose)
		{
			case 1:
				encode(src, key);
				break;

			case 2:
				decode(src, key);
				break;

			default:
				printf("����ѡ�����\n");
				break;
		}
	} while (choose != 3);

	system("pause");
	return 0;
}