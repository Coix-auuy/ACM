#include <stdio.h>
#define INF 1000000
struct edge
{
    int a, b;
    double t;
} e[5500];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, w; //田,田与田之间的关系数,虫洞数
        scanf("%d%d%d", &n, &m, &w);
        int k = 1;
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            double t;
            scanf("%d%d%lf", &a, &b, &t);
            e[k].a = a;
            e[k].b = b;
            e[k].t = t;
            k++;
            e[k].a = b;
            e[k].b = a;
            e[k].t = t;
            k++;
        }
        for (int i = 1; i <= w; i++)
        {
            int a, b;
            double t;
            scanf("%d%d%lf", &a, &b, &t);
            int j;
            for (j = 1; j < k; j++)
            {
                if (e[j].a == a && e[j].b == b)
                    e[j].t = -t;
                continue;
            }
            e[k].a = a;
            e[k].b = b;
            e[k].t = -t;
            k++;
        }

        //Bellman-ford
        double time[5500] = {0};
        for (int i = 1; i <= n; i++)
            time[i] = INF;
        time[1] = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j < k; j++)
                if (time[e[j].b] > time[e[j].a] + e[j].t)
                    time[e[j].b] = time[e[j].a] + e[j].t;
        }
        int flag = 0;
        for (int i = 1; i < k; i++)
        {
            if (time[e[i].b] > time[e[i].a] + e[i].t)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}