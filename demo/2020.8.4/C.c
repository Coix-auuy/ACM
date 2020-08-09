#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void iterative(char num[], char res[])
{
    for (int i = 0; i < 81; i++)
        res[i] = '\0';
    int temp[10] = {0};
    for (int i = 0; i < strlen(num); i++)
        temp[num[i] - '0']++;

    for (int i = 0; i < 10; i++)
    {
        if (temp[i] != 0)
        {
            char str[81] = {'\0'};
            itoa(temp[i], str, 10);
            strcat(res, str);
            itoa(i, str, 10);
            strcat(res, str);
        }
    }
}
int main()
{
    char num[81] = {'\0'};
    while (scanf("%s", &num) && strcmp(num, "-1") != 0)
    {
        char res[16][81] = {'\0'};
        for (int i = 0; i < 81; i++)
            res[0][i] = num[i];
        int flag = 1;
        for (int i = 1; i < 16; i++)
        {
            iterative(res[i - 1], res[i]);
            if (strcmp(res[i - 1], res[i]) == 0 && i == 1)
            {
                printf("%s is self-inventorying\n", num);
                flag = 0;
                break;
            }
            else if (strcmp(res[i - 1], res[i]) == 0 && i > 1)
            {
                printf("%s is self-inventorying after %d steps\n", num, i - 1);
                flag = 0;
                break;
            }
            // else if (strcmp(num, res[i]) == 0 && i > 1)
            // {
            //     printf("%s enters an inventory loop of length %d\n", num, i + 1);
            //     flag = 0;
            //     break;
            // }
        }
        if (flag)
        {
            for(int i = 1; i < 16; i++)
            {
                for(int j = i + 1;j < 16; j++)
                {
                    if(strcmp(res[i],res[j]) == 0)
                    {
                        printf("%s enters an inventory loop of length %d\n", num, j - i);
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0)
                    break;
            }
            if(flag)
                printf("%s can not be classified after 15 iterations\n", num);
        }
    }
    return 0;
}