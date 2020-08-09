#include <stdio.h>
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        int sum = 0;
        int time[13] = {0};
        int s = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &s, &time[i]);
            sum += s * (time[i] - time[i - 1]);
        }
        printf("%d miles\n", sum);
    }
    return 0;
}