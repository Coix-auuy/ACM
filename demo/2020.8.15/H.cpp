#include <cstdio>
#include <cstring>
bool div(int digInt[1010], int b, int &len)
{
    int x = 0;
    int res[1010] = {0};
    for (int i = 0; i < len; i++)
    {
        res[i] = (x * 10 + digInt[i]) / b;
        x = (x * 10 + digInt[i]) % b;
    }
    int k = 0;
    for (int i = 0; i < len; i++)
        if (res[i] != 0)
        {
            k = i;
            break;
        }
    for (int i = k, j = 0; i < len; i++, j++)
        digInt[j] = res[i];
    len = len - k; //res长度
    if (x == 0)
        return true;
    return false;
}
int main()
{
    char dig[1010] = {'0'};
    int b;
    while (scanf("%s", dig) && strcmp(dig, "-1") != 0)
    {
        int len = strlen(dig);
        int digInt[1010] = {0};
        for (int i = 0; i < len; i++)
            digInt[i] = dig[i] - '0';
        if (len == 1)
        {
            printf("1%d\n", digInt[0]);
            continue;
        }
        int ans[1010] = {0};
        int k = 0;
        int flag = 1;
        while (true)
        {
            if (len == 1)
            {
                ans[k++] = digInt[0];
                break;
            }
            int i;
            for (i = 9; i >= 2; i--)
            {
            	int temp[1010],tlen = len;
            	for(int j = 0; j < len; j++)
            		temp[j] = digInt[j];
                if (div(digInt, i, len))
                {
                    ans[k++] = i;
                    break;
                }
                else
                {
                	for(int j = 0; j < tlen; j++)
            			digInt[j] = temp[j];
            		len = tlen;
				}
            }
            if (i == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (int i = k - 1; i >= 0; i--)
                printf("%d", ans[i]);
            printf("\n");
        }
        else
            printf("There is no such number.\n");
    }
    return 0;
}