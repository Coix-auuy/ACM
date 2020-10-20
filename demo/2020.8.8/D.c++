#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
int dis[1009], w[1000009];
int v[1000009], u[1000009], i, n, j, k = 0, t, m;
int main()
{
    scanf("%d", &t);
    for (k = 1; k <= t; k++)
    {
        scanf("%d %d", &n, &m);
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
        }
        for (i = 1; i <= n; i++)
            dis[i] = 0;
        dis[1] = inf;
        for (i = 1; i <= n - 1; i++)
        {
            for (j = 1; j <= m; j++)
            {
                if (dis[v[j]] < min(dis[u[j]], w[j]))
                {
                    dis[v[j]] = min(dis[u[j]], w[j]);
                }
                if (dis[u[j]] < min(dis[v[j]], w[j]))
                {
                    dis[u[j]] = min(dis[v[j]], w[j]);
                }
            }
        }
        printf("Scenario #%d:\n%d\n\n", k, dis[n]);
    }
    return 0;
}