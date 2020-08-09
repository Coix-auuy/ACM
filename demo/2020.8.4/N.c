#include <stdio.h>
#include <string.h>
int main()
{
    char map[20][36] =
        {
            {""},
            {" +---+---+---+---+---+---+---+---+"},
            {" |...|:::|...|:::|...|:::|...|:::|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |:::|...|:::|...|:::|...|:::|...|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |...|:::|...|:::|...|:::|...|:::|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |:::|...|:::|...|:::|...|:::|...|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |...|:::|...|:::|...|:::|...|:::|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |:::|...|:::|...|:::|...|:::|...|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |...|:::|...|:::|...|:::|...|:::|"},
            {" +---+---+---+---+---+---+---+---+"},
            {" |:::|...|:::|...|:::|...|:::|...|"},
            {" +---+---+---+---+---+---+---+---+"}};
    char w[200] = {'\0'}, b[200] = {'\0'};
    gets(w);
    gets(b);
    int wIndex[200] = {0}, bIndex[200] = {0}, k1 = 0, k2 = 0;
    for (int i = 7; i < strlen(w); i++)
        if (w[i] >= 'a' && w[i] <= 'z')
            wIndex[k1++] = i;
    for (int i = 7; i < strlen(b); i++)
        if (b[i] >= 'a' && b[i] <= 'z')
            bIndex[k2++] = i;
    for (int i = 1; i <= 17; i++)
    {
        for (int j = 1; j <= 33; j++)
        {
            if (i % 2 == 0 && j % 4 == 3)
            {
                for (int k = 0; k < k1; k++)
                {
                    if (w[wIndex[k]] - 'a' + 1 == (j + 1) / 4 && w[wIndex[k] + 1] - '0' == 9 - i / 2)
                    {
                        if (w[wIndex[k] - 1] != ',')
                            map[i][j] = w[wIndex[k] - 1];
                        else
                            map[i][j] = 'P';
                    }
                }
                for (int k = 0; k < k2; k++)
                {
                    if (b[bIndex[k]] - 'a' + 1 == (j + 1) / 4 && b[bIndex[k] + 1] - '0' == 9 - i / 2)
                    {
                        if (b[bIndex[k] - 1] != ',')
                            map[i][j] = b[bIndex[k] - 1] - 'A' + 'a';
                        else
                            map[i][j] = 'p';
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 17; i++)
        {
            for (int j = 1; j <= 33; j++)
                printf("%c", map[i][j]);
            putchar('\n');
        }
    return 0;
}