#include <stdio.h>
#include <math.h>
#include <Windows.h>

/*
 * 初学C时写的I love you，还准备撩下妹，很可惜还是错过了
 * @Author SnhAenIgseAl
 * @Date 2022.10.28 重写
 */

int main()
{
	char ILOVEYOU[] = { "I Love You."};
	int space;		//空格
	int m = 3;		//控制打印行数
	int n = 21;		//控制输出字符

	//第一行
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

	//第二行
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

	//第三到五行
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

	//剩下六到十一行
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