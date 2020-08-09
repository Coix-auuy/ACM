#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define INF 214748364
#define MIN(x, y) ((x) > (y) ? (y) : (x))
struct Node
{
    int m; //交叉口号
    int t; //此交叉口到火灾交叉口的时间
    int p; //path长度
    int path[21];
} node[21];
struct Dij
{
    int flag; //标记是否已经加入子树
    int t;    //从这一点到起点的距离
    int pre;
} dij[21];
int cmp(const void *x, const void *y)
{
    return (*(struct Node *)x).t - (*(struct Node *)y).t;
}
int min(int N)
{
    int index;
    int min = INF;
    for (int i = 1; i <= N; i++)
    {
        if (dij[i].flag == 0 && min > dij[i].t)
            min = dij[i].t, index = i;
    }
    return index;
}
int main()
{
    int N; //交叉口数<20
    scanf("%d", &N);
    int map[21][21];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1)
                map[i][j] = INF;
        }

    int n; //火灾最近交叉口  终点
    scanf("%d", &n);
    int m; //距离消防站最近的交叉口  起点
    int k = -1;

    while (cin >> m)
    {
        k++;
        node[k].m = m;
        if (m == n)
        {
            node[k].p = 1;
            node[k].path[0] = n;
            node[k].t = 0;
            continue;
        }
        //初始化
        for (int i = 1; i <= N; i++)
        {
            dij[i].flag = 0;
            dij[i].t = map[m][i];
            if (dij[i].t != INF)
                dij[i].pre = m;
        }
        dij[m].flag = 1; //标记起点
        dij[m].t = 0;
        for (int i = 1; i <= N - 1; i++) //还有N - 1个点要确定
        {
            int u = min(N);  //找到当前距离起点最近的点
            dij[u].flag = 1; //标记
            for (int j = 1; j <= N; j++)
                if (dij[j].flag == 0)
                    if (dij[j].t > dij[u].t + map[u][j])
                    {
                        dij[j].t = dij[u].t + map[u][j];
                        dij[j].pre = u;
                    }
            if (u == n) //已经到达终点
                break;
        }
        node[k].t = dij[n].t; //到达终点时间
        //回溯路径
        int i = n;
        node[k].p = 0;
        while (i != m)
        {
            node[k].path[node[k].p++] = i;
            i = dij[i].pre;
        }
        node[k].path[node[k].p++] = m;
    }

    //输出结果
    qsort(node, k + 1, sizeof(struct Node), cmp); //按时间从小到大
    printf("Org\tDest\tTime\tPath\n");
    for (int i = 0; i <= k; i++)
    {
        printf("%d\t%d\t%d\t", node[i].m, n, node[i].t);
        for (int j = node[i].p - 1; j > 0; j--)
            printf("%d\t", node[i].path[j]);
        printf("%d\n", node[i].path[0]);
    }
    return 0;
}