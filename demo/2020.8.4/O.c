#include <stdio.h>
int main()
{
    char map[18][34] = {'\0'};
    char w[6] = {'K', 'Q', 'R', 'B', 'N', 'P'}, b[6] = {'k', 'q', 'r', 'b', 'n', 'p'};
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= 17; i++)
    {
        for (int j = 1; j <= 33; j++)
        {
            scanf("%c", &map[i][j]);
            if (map[i][j] == 'P')
                s1++;
            else if (map[i][j] == 'p')
                s2++;
        }

        getchar();
    }
    // printf("\n\n");
    // for (int i = 1; i <= 17; i++)
    // {
    //     for (int j = 1; j <= 33; j++)
    //         printf("%c", map[i][j]);
    //     putchar('\n');
    // }
    printf("White: ");
    for (int k = 0; k < 6; k++)
    {
        for (int i = 17; i >= 1; i--)
        {
            for (int j = 1; j <= 33; j++)
            {
                if (i % 2 == 0 && j % 4 == 3 && k < 5)
                {
                    if (map[i][j] == w[k])
                    {
                        printf("%c%c%d,", w[k], 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                    }
                }
                else if (i % 2 == 0 && j % 4 == 3 && k == 5)
                {
                    if (map[i][j] == w[k])
                    {
                        s1--;
                        if (s1 == 0)
                            printf("%c%d\n", 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                        else
                            printf("%c%d,", 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                    }
                }
            }
        }
    }
    printf("Black: ");
    for (int k = 0; k < 6; k++)
    {
        for (int i = 1; i <= 17; i++)
        {
            for (int j = 1; j <= 33; j++)
            {
                if (i % 2 == 0 && j % 4 == 3 && k < 5)
                {
                    if (map[i][j] == b[k])
                    {
                        printf("%c%c%d,", w[k], 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                    }
                }
                else if (i % 2 == 0 && j % 4 == 3 && k == 5)
                {
                    if (map[i][j] == b[k])
                    {
                        s2--;
                        if (s2 == 0)
                            printf("%c%d\n", 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                        else
                            printf("%c%d,", 'a' + (j + 1) / 4 - 1, 9 - i / 2);
                    }
                }
            }
        }
    }
    return 0;
}