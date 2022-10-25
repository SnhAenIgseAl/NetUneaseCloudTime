#include <stdio.h>
#include <windows.h>

/*
 * 杨辉三角邪道速通谢尔宾斯基三角形
 * 
 * @Author SnhAenIseAl
 * @Date 2022.4.10
 */

int main()
{
    int row;                //打印行数
    int column;             //打印列数
    int space;              //空格数
    int line;               //用户自定义打印行数
    unsigned long long n;   //项数值

    printf("请输入打印谢尔宾斯基三角形的行数：");
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
            //根据项数值的奇偶判断是否打印" A"
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