#include <stdio.h>
#define MAXSIZE 1000

/*
 * 维吉尼亚密码的加密与解密
 * @Author SnhAenIgseAl
 * @Date 2022.11.12
 */

/*
 * 分割线
 */
void line()
{
	printf("-----------------------------------------\n");
}

/*
 * 加密算法
 * @param char 源字符串
 * @param char 密钥
 */
void encode(char src[], char key[])
{
	int srcLength = strlen(src);
	int keyLength = strlen(key);
	char dst[MAXSIZE];

	//将密钥全部转为小写
	for (int i = 0; i < keyLength; i++)
	{
		if (isupper(key[i]))
		{
			key[i] += 32;
		}
	}

	for (int i = 0; i < srcLength; i++)
	{
		//循环密钥
		int j = i % keyLength;

		if (src[i] >= 'a' && src[i] <= 'z')
		{
			dst[i] = ((src[i] - 'a') + (key[j] - 'a')) % 26 + 'a';
		}
		else if (src[i] >= 'A' && src[i] <= 'Z')
		{
			dst[i] = ((src[i] - 'A') + (key[j] - 'a')) % 26 + 'A';
		}
		//其他字符不变
		else
		{
			dst[i] = src[i];
		}
	}

	dst[srcLength] = '\0';

	printf("加密后的结果：");
	printf("%s\n", dst);
	line();
}

/*
 * 解密算法
 * @param char 源字符串
 * @param char 密钥
 */
void decode(char src[], char key[])
{
	int srcLength = strlen(src);
	int keyLength = strlen(key);
	char dst[MAXSIZE];

	//将密钥全部转为小写
	for (int i = 0; i < keyLength; i++)
	{
		if (isupper(key[i]))
		{
			key[i] += 32;
		}
	}

	for (int i = 0; i < srcLength; i++)
	{
		//循环密钥
		int j = i % keyLength;

		if (src[i] >= 'a' && src[i] <= 'z')
		{
			dst[i] = (src[i] - key[j] + 26) % 26 + 'a';
		}
		else if (src[i] >= 'A' && src[i] <= 'Z')
		{
			dst[i] = ((src[i] + 32) - key[j] + 26) % 26 + 'A';
		}
		//其他字符不变
		else
		{
			dst[i] = src[i];
		}
	}

	dst[srcLength] = '\0';

	printf("解密后的结果：");
	printf("%s\n", dst);
	line();
}