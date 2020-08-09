#include <stdio.h>
#define INF 32767
#define SIZE 110
#define MIN(x, y) ((x) < (y)) ? (x) : (y);
int m, n; //m--酋长地位 n--物品总数
int w[SIZE][SIZE], dis[SIZE], flag[SIZE], level[SIZE];
// 对地位在 down~up 的人进行交易
int dijkstra(int down, int up)
{
    for (int i = 0; i <= n; i++)
        dis[i] = INF, flag[i] = 0;
    dis[0] = 0;
    flag[0] = 0;
    level[0] = m;
    for (int i = 1; i <= n; i++)
    {
        int min = INF;
        int index = -1;
        for (int j = 0; j <= n; j++)
            if (flag[j] == 0 && dis[j] < min)
                min = dis[j], index = j;
        flag[index] = 1;
        for (int j = 0; j <= n; j++)
            if (flag[j] == 0 && level[j] >= down && level[j] <= up)
                dis[j] = MIN(dis[j], dis[index] + w[index][j]);
    }
    return dis[1];
}
int main()
{

    scanf("%d%d", &m, &n);
    //初始化
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i != j)
                w[i][j] = INF;
    for (int i = 1; i <= n; i++)
    {
        int p, x;
        scanf("%d%d%d", &p, &level[i], &x);
        w[0][i] = MIN(w[0][i], p);
        while (x--)
        {
            int id, cost;
            scanf("%d%d", &id, &cost);
            w[id][i] = MIN(w[id][i], cost);
        }
    }
    int res = INF;
    for (int i = level[1] - m; i <= level[1]; i++)
        res = MIN(res, dijkstra(i, i + m));
    printf("%d\n", res);
    return 0;
}