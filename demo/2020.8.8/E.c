#include <stdio.h>
struct Node
{
    int a, b;
    double r, c;

} node[205];
int main()
{
    int n, m, s; //N--货币种类数 M--城市兑换点数 S--nick拥有的货币类型
    double v;    //V--货币量
    scanf("%d%d%d%lf", &n, &m, &s, &v);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        double r1, c1, r2, c2;
        scanf("%d%d%lf%lf%lf%lf", &a, &b, &r1, &c1, &r2, &c2);
        node[i].a = a;
        node[i].b = b;
        node[i].r = r1;
        node[i].c = c1;
        node[i + m].a = b;
        node[i + m].b = a;
        node[i + m].r = r2;
        node[i + m].c = c2;
    }
    double dis[105];
    for (int i = 1; i <= n; i++)
        dis[i] = 0;
    dis[s] = v; //一开始拥有v个s货币
    //对每条边进行松弛操作
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= 2 * m; j++)
        {
            double w = (dis[node[j].a] - node[j].c) * node[j].r;
            if (dis[node[j].b] < w)
                dis[node[j].b] = w;
        }
    }
    int flag = 0;
    for (int i = 1; i <= 2 * m; i++)
    {
        double w = (dis[node[i].a] - node[i].c) * node[i].r;
        if (dis[node[i].b] < w)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}