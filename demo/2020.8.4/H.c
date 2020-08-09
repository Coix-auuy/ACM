#include <stdio.h>
#include <string.h>
int m, ASM[12][12], square[50][50];          //square[][]用来存放结果符号映射，其中set[square[i][j]]即为i,j位置的符号
char set[] = {' ', '-', '|', 'O', 'H', 'H'}; //4代表游离H,5代表固定H
int valid(int i, int j)
{
    if (0 <= i && i < 4 * m - 3 && 0 <= j && j < 4 * m + 1)
        return 1;
    return 0;
}
void print()
{
    for (int i = 0; i < 4 * m + 3; i++)
        printf("*");
    printf("\n");
    for (int i = 0; i < 4 * m - 3; i++)
    {
        printf("*");
        for (int j = 0; j < 4 * m + 1; j++)
            printf("%c", set[square[i][j]]);
        printf("*\n");
    }
    for (int i = 0; i < 4 * m + 3; i++)
        printf("*");
    printf("\n");
}
void res()
{
    memset(square, 0, sizeof(square));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            square[4 * i][4 * j + 2] = 3;
            square[4 * i + 2][4 * j + 2] = 4;
            square[4 * i][4 * j + 4] = 4;
            if (j == 0)
                square[4 * i][4 * j] = 4;
            if (ASM[i][j] == 1)
            {
                square[4 * i][4 * j + 1] = square[4 * i][4 * j + 3] = 1;
                square[4 * i][4 * j] = square[4 * i][4 * j + 4] = 5;
            }
            else if (ASM[i][j] == -1)
            {
                square[4 * i - 1][4 * j + 2] = square[4 * i + 1][4 * j + 2] = 2;
                square[4 * i - 2][4 * j + 2] = square[4 * i + 2][4 * j + 2] = 5;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ASM[i][j] == 0)
            {
                if (square[4 * i][4 * j] != 5 && valid(4 * i, 4 * j))
                {
                    square[4 * i][4 * j + 1] = 1;
                    square[4 * i][4 * j] = 5;
                }
                else if (square[4 * i][4 * j + 4] != 5 && valid(4 * i, 4 * j + 4))
                {
                    square[4 * i][4 * j + 3] = 1;
                    square[4 * i][4 * j + 4] = 5;
                }
                if (square[4 * i - 2][4 * j + 2] != 5 && valid(4 * i - 2, 4 * j + 2))
                {
                    square[4 * i - 1][4 * j + 2] = 2;
                    square[4 * i - 2][4 * j + 2] = 5;
                }
                else if (square[4 * i + 2][4 * j + 2] != 5 && valid(4 * i + 2, 4 * j + 2))
                {
                    square[4 * i + 1][4 * j + 2] = 2;
                    square[4 * i + 2][4 * j + 2] = 5;
                }
            }
        }
    }
}
int main()
{
    int c = 0;
    while (scanf("%d", &m) && m != 0)
    {
        c++;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &ASM[i][j]);
        if (c != 1)
            printf("\n");
        printf("Case %d:\n\n", c);
        res();
        print();
    }
    return 0;
}