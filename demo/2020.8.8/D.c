#include <stdio.h>
#define INF 0x3f3f3f3f
int MIN(int x, int y)
{
    if (x < y)
        return x;
    return y;
}
int dis[10100], w[1010000], u[1010000], v[1010000];
int main()
{
    int scenario;
    scanf("%d", &scenario);
    for (int t = 1; t <= scenario; t++)
    {
        int n, m; //点，边
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int a, b, p;
            scanf("%d%d%d", &a, &b, &p);
            u[i] = a;
            u[i + m] = b;
            v[i] = b;
            v[i + m] = a;
            w[i] = w[i + m] = p;
        }

        for (int i = 1; i <= n; i++)
            dis[i] = 0;
        dis[1] = INF;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= 2 * m; j++)
            {
                if (dis[v[j]] < MIN(dis[u[j]], w[j]))
                    dis[v[j]] = MIN(dis[u[j]], w[j]);
            }
        }
        printf("Scenario #%d:\n", t);
        printf("%d\n\n", dis[n]);
    }
    return 0;
}