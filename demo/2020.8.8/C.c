#include <stdio.h>
#define INF 214748364
#define MIN(x, y) ((x) < (y) ? (x) : (y))
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int map[105][105] = {0};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    map[i][j] = INF;
        for (int i = 1; i <= n; i++)
        {
            int m;
            scanf("%d", &m);
            int a;
            while (m--)
            {
                scanf("%d", &a);
                scanf("%d", &map[i][a]);
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    map[i][j] = MIN(map[i][j], map[i][k] + map[k][j]);
        int res = INF;
        int index;
        for (int i = 1; i <= n; i++)
        {
            int max = 0;
            for (int j = 1; j <= n; j++)
            {
                if (i != j && max < map[i][j])
                    max = map[i][j];
            }
            if (res > max)
            {
                res = max;
                index = i;
            }
        }

        if (res == INF)
            printf("disjoint\n");
        else
            printf("%d %d\n", index, res);
    }
    return 0;
}