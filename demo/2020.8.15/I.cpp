#include <cstdio>
#include <algorithm>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, t, m;
        scanf("%d%d%d", &n, &t, &m);
        int time[1444] = {0};
        for (int i = 0; i < m; i++)
            scanf("%d", &time[i]);
        //1.最后一辆车过河后的时间
        //2.这个时间里渡轮的最少往还次数
        int sum = 0;
        if (m % n == 0)
        {
            for (int i = 0; i < m; i += n)
            {
                if (sum >= time[i + n - 1])
                    sum += 2 * t;
                else
                    sum = time[i + n - 1] + 2 * t;
            }
            printf("%d %d\n", sum - t, m / n);
        }
        else
        {
            sum = time[m % n - 1] + 2 * t;
            for (int i = m % n; i < m; i += n)
            {
                if (sum >= time[i + n - 1])
                    sum += 2 * t;
                else
                    sum = time[i + n - 1] + 2 * t;
            }
            printf("%d %d\n", sum - t, m / n + 1);
        }
    }
    return 0;
}