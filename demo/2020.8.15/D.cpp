#include <cstdio>
#include <algorithm>
int main()
{
    int c = 0;
    int m, n;
    while (scanf("%d%d", &m, &n) && (m || n))
    {
        c++;
        int cnt[1001] = {0};
        int t;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &t);
            cnt[t] = 1;
        }
        t = 0;
        int res = 0;
        for(int i = n * m; i >= 1; i--)
        {
            if(cnt[i] == 1)
                t++;
            else
                t--;
            if(t > res)
                res = t;
        }
        printf("Case %d: %d\n", c, res);
    }
    return 0;
}