#include <stdio.h>
#include <stdlib.h>
#define INF 214748364
struct Node
{
    int t, m;
} node[21];
int path[21][21];
int cmp(const void *x, const void *y)
{
    return (*(struct Node *)x).t - (*(struct Node *)y).t;
}
void floyd(int map[21][21],int N)
{
    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
            if(map[i][j] > map[i][k] + map[k][j])
            {
                map[i][j] = map[i][k] + map[k][j];
                path[i][j] = path[i][k];
            }
                
}
int main()
{
    int N; //交叉口数<20
    scanf("%d", &N);
    int map[21][21];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            path[i][j] = j;
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1)
                map[i][j] = INF;
        }
    floyd(map,N);
    int n; //火灾最近交叉口  终点
    scanf("%d", &n);
    int m; //距离消防站最近的交叉口  起点
    int k = 0;
    while (scanf("%d",&m)!=EOF)
    {
        node[k].t = map[m][n];
        node[k++].m = m;
    }
    qsort(node, k, sizeof(struct Node), cmp); //按时间从小到大
    printf("Org\tDest\tTime\tPath\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\t", node[i].m, n, node[i].t);
        int start = node[i].m;
        while(start != n)
        {
            printf("%d\t",start);
            start = path[start][n];
        }
        printf("%d\n",n);
    }
    return 0;
}
