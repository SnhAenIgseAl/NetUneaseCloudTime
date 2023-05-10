#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
#define MAX 256

int main()
{
	int arr[MAX][MAX] = { 0 };
	int space;
	int line;

	printf("请输入打印谢尔宾斯基三角形的行数：");
	scanf("%d", &line);

	printf("\n");

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			arr[i][j] = 1;
		}
	}

	//第一行和第二行
	for (space = 1; space <= line; space++)
	{
		printf(" ");
	}
	printf(" A\n");
	for (space = 1; space < line; space++)
	{
		printf(" ");
	}
	printf(" A A\n");

	for (int i = 2; i < line; i++)
	{
		for (space = 1; space <= line - i; space++)
		{
			printf(" ");
		}
		printf(" A");

		for (int j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

			if (arr[i][j] % 2)
			{
				printf(" A");
			}
			else
			{
				printf("  ");
			}
		}
		printf(" A\n");
	}

	system("pause");
	return 0;
}