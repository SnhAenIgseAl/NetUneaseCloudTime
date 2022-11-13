#include <stdio.h>
#define MAXSIZE 1000

/*
 * ά����������ļ��������
 * @Author SnhAenIgseAl
 * @Date 2022.11.12
 */

/*
 * �ָ���
 */
void line()
{
	printf("-----------------------------------------\n");
}

/*
 * �����㷨
 * @param char Դ�ַ���
 * @param char ��Կ
 */
void encode(char src[], char key[])
{
	int srcLength = strlen(src);
	int keyLength = strlen(key);
	char dst[MAXSIZE];

	//����Կȫ��תΪСд
	for (int i = 0; i < keyLength; i++)
	{
		if (isupper(key[i]))
		{
			key[i] += 32;
		}
	}

	for (int i = 0; i < srcLength; i++)
	{
		//ѭ����Կ
		int j = i % keyLength;

		if (src[i] >= 'a' && src[i] <= 'z')
		{
			dst[i] = ((src[i] - 'a') + (key[j] - 'a')) % 26 + 'a';
		}
		else if (src[i] >= 'A' && src[i] <= 'Z')
		{
			dst[i] = ((src[i] - 'A') + (key[j] - 'a')) % 26 + 'A';
		}
		//�����ַ�����
		else
		{
			dst[i] = src[i];
		}
	}

	dst[srcLength] = '\0';

	printf("���ܺ�Ľ����");
	printf("%s\n", dst);
	line();
}

/*
 * �����㷨
 * @param char Դ�ַ���
 * @param char ��Կ
 */
void decode(char src[], char key[])
{
	int srcLength = strlen(src);
	int keyLength = strlen(key);
	char dst[MAXSIZE];

	//����Կȫ��תΪСд
	for (int i = 0; i < keyLength; i++)
	{
		if (isupper(key[i]))
		{
			key[i] += 32;
		}
	}

	for (int i = 0; i < srcLength; i++)
	{
		//ѭ����Կ
		int j = i % keyLength;

		if (src[i] >= 'a' && src[i] <= 'z')
		{
			dst[i] = (src[i] - key[j] + 26) % 26 + 'a';
		}
		else if (src[i] >= 'A' && src[i] <= 'Z')
		{
			dst[i] = ((src[i] + 32) - key[j] + 26) % 26 + 'A';
		}
		//�����ַ�����
		else
		{
			dst[i] = src[i];
		}
	}

	dst[srcLength] = '\0';

	printf("���ܺ�Ľ����");
	printf("%s\n", dst);
	line();
}