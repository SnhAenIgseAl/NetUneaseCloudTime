#include <stdio.h>
#include <math.h>
#include <windows.h>

/*
 * ��������Ҿ��ú�����˼����ݹ�ṹ�뺺ŵ���ǳ�����
 * ת������������ �� 1 2 1 4 1 2 1 8 1 2 1 4 1 2 1 ... �� ��һ������
 * 
 * @Author SnhAenIgseAl
 * @Date 2022.10.27
 */

void Func(int n, int p, int q);

int main()
{
    Func(5, 0, 0);
    printf("\n");

    system("pause");
    return 0;
}

void Func(int n, int p, int q)
{
    int m = (p + q) / 2;
    if (n > 0)
    {
        Func(n - 1, p, m);
        printf("%.0lf ", pow(2, n - 1));
        Func(n - 1, m, q);
    }
}