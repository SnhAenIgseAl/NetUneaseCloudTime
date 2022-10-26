#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX 10

/*
 * 计数排序
 * 但这个排序只限用于数字是唯一的且是正数，图一乐
 * 
 * @Author SnhAenIgseAl
 * @Date 2022.10.26
 */

int main()
{
	int arr_src[MAX] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int arr_dst[MAX];

	for (int i = 0; i < MAX; i++)
	{
		//It's so wonderful
		arr_dst[arr_src[i]] = arr_src[i];		
	}

	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr_dst[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}