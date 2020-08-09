#include <stdio.h>
#include <string.h>
int main()
{
    char num[10002];
    int r[10002] = {0};
    while (1)
    {
        scanf("%s", num);
        if (strcmp(num, "0") == 0)
            break;
        int n[10002] = {0};
        int j = 0;
        for (int i = strlen(num) - 1; i >= 0; i--)
            n[j++] = num[i] - '0';
        for (int i = 0; i < 10002; i++)
        {
            int t = n[i] + r[i];
            if (t > 9)
            {
                r[i] = t - 10;
                r[i + 1]++;
            }
            else
                r[i] = t;
        }
    }
    int k = 0;
    for (int i = 10001; i >= 0; i--)
        if (r[i] != 0)
        {
            k = i;
            break;
        }
    for (int i = k; i >= 0; i--)
        printf("%d", r[i]);
    printf("\n");
    return 0;
}