#include <stdio.h>
#include <windows.h>

/*
 * �������а����ͨл����˹��������
 * 
 * @Author SnhAenIseAl
 * @Date 2022.4.10
 */

int main()
{
    int row;                //��ӡ����
    int column;             //��ӡ����
    int space;              //�ո���
    int line;               //�û��Զ����ӡ����
    unsigned long long n;   //����ֵ

    printf("�������ӡл����˹�������ε�������");
    scanf_s("%d", &line);
    printf("\n");

    for (space = 1; space <= line; space++)
    {
        printf(" ");
    }
    printf("A\n");

    for (row = 2; row <= line; row++)
    {
        n = 1;
        for (space = 1; space <= line - row; space++)
        {
            printf(" ");
        }
        printf(" A");
        for (column = 1; column <= row - 2; column++)
        {
            n = (row - column) * n / column;
            //��������ֵ����ż�ж��Ƿ��ӡ" A"
            if ((n & 1) == 1)
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