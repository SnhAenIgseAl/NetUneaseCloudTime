#include <stdio.h>
#include <math.h>
#include <Windows.h>

/*
 * ��ѧCʱд��I love you����׼�������ã��ܿ�ϧ���Ǵ����
 * @Author SnhAenIgseAl
 * @Date 2022.10.28 ��д
 */

int main()
{
	char ILOVEYOU[] = { "I Love You."};
	int space;		//�ո�
	int m = 3;		//���ƴ�ӡ����
	int n = 21;		//��������ַ�

	//��һ��
	printf("\n\n\n");
	for (int i = 1; i <= 2; i++)
	{
		for (space = 1; space <= 5; space++)
		{
			printf(" ");
		}
		for (int j = 0; j <= 5; j++)
		{
			printf("%c", ILOVEYOU[j % 11]);
		}
	}
	printf("\n");

	//�ڶ���
	for (int i = 1; i <= 2; i++)
	{
		for (space = 1; space <= 3; space++)
		{
			printf(" ");
		}
		for (int j = 0; j <= 8; j++)
		{
			printf("%c", ILOVEYOU[j % 11]);
		}
	}
	printf("\n");

	//����������
	for (int i = 1; i <= 3; i++)
	{
		for (space = 2; space <= 2 + abs(i - 2); space++)
		{
			printf(" ");
		}
		for (int j = 0; j <= -2 * abs(i - 2) + 24; j++)
		{
			printf("%c", ILOVEYOU[j % 11]);
		}
		printf("\n");
	}

	//ʣ������ʮһ��
	for (int i = 1; i <= 6; i++)
	{
		for (space = 1; space <= m; space++)
		{
			printf(" ");
		}
		for (int j = 0; j < n; j++)
		{
			printf("%c", ILOVEYOU[j % 11]);
		}
		printf("\n");

		m += 2;
		n -= 4;
	}
	printf("\n\n\n");

	system("pause");
	return 0;
}