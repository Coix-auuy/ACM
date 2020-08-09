#include <algorithm>
#include <stdio.h>
using namespace std;
#define INF 0x3f3f3f3f
int main()
{

    int n;
    while (scanf("%d", &n) && n)
    {

        int map[106][106];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = INF;
            }

        for (int i = 1; i <= n; i++)
        {
            int m;
            scanf("%d", &m);
            while (m--)
            {
                int a, b;
                scanf("%d%d", &a, &b);
                map[i][a] = b;
            }
        }

        //floyd
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (k == i || k == j || i == j)
                        continue;

                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
        //index下标
        int index = 0;
        //maxx最小的时间
        int maxx = INF;
        for (int i = 1; i <= n; i++)
        {

            int ma = 0;

            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;

                if (ma < map[i][j])
                {
                    ma = map[i][j];
                }
            }
            //最小
            if (maxx > ma)
            {
                maxx = ma;
                index = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (map[i][j] == INF)
                    printf(" INF ");
                else
                    printf("%5d", map[i][j]);
            }

            putchar('\n');
        }
        //无解
        if (maxx == INF)
            printf("disjoint\n");
        else
            printf("%d %d\n", index, maxx);
    }
}