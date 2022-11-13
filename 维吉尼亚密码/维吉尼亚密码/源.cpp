#include <stdio.h>
#include <windows.h>
#include "VigenèreCipher.h"

/*
 * 维吉尼亚密码的加密与解密交互界面
 * @Author SnhAenIgseAl
 * @Date 2022.11.12
 */

int main()
{
	char src[MAXSIZE];		//密文或明文
	char key[MAXSIZE];		//密钥
	int choose;			//操作选项

	do
	{
		printf("请输入密文或明文：");
		scanf_s("%s", src, MAXSIZE);
		printf("请输入密钥：");
		scanf_s("%s", key, MAXSIZE);
		printf("请输入操作选项：\n1.加密\t2.解密\t3.退出\n");
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
				printf("操作选项不存在\n");
				break;
		}
	} while (choose != 3);

	system("pause");
	return 0;
}
