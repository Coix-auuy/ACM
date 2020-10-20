#include <cstdio>
using namespace std;
const int SIZE = 100;
const int INF = 1000009;
struct edge
{
    int x, y;
    int w;
};

struct graph
{
    edge E[SIZE];
    int V[SIZE]; //鐐瑰埌璧风偣鐨勮窛绂?
    int vNum;
    int eNum;
};

bool bellmanFord(graph &g, int s) //s-璧风偣
{
    for (int i = 0; i < g.vNum; i++)
        g.V[i] = INF;
    g.V[s] = 0;
    for (int i = 1; i <= g.vNum - 1; i++)
    {
        for (int j = 0; j < g.eNum; j++)
        {
            if (g.V[g.E[j].y] > g.V[g.E[j].x] + g.E[j].w)
                g.V[g.E[j].y] = g.V[g.E[j].x] + g.E[j].w;
        }
    }
    for (int j = 0; j < g.eNum; j++)
    {
        if (g.V[g.E[j].y] > g.V[g.E[j].x] + g.E[j].w)
            return false;
    }
    return true;
}

int main()
{
    graph g;
    int s;
    scanf("%d%d%d", &g.vNum, &g.eNum, &s);
    for (int i = 0; i < g.eNum; i++)
    {
        scanf("%d%d%d", &g.E[i].x, &g.E[i].y, &g.E[i].w);
    }
    if(!bellmanFord(g, s))
    {
        printf("含有负权环！！！\n");
        return 1;
    }
    for (int i = 0; i < g.vNum; i++)
    {
        printf("%d ", g.V[i]);
    }
    return 0;
}