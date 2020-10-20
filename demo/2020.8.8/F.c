#include <stdio.h>
#include <string.h>
struct Node
{
    int a, b;
    double r;
} node[1010];
int main()
{
    int n; //货币种类
    int k = 0;
    while (scanf("%d", &n) && n)
    {
        k++;
        char arr[31][100];
        for (int i = 1; i <= n; i++)
            scanf("%s", arr[i]);
        int m; //兑换方式
        scanf("%d",&m);
        for (int i = 1; i <= m; i++)
        {
            char a[100], b[100];
            scanf("%s %lf %s", a,&node[i].r, b);
            for (int j = 1; j <= n; j++)
            {
                if (strcmp(a, arr[j]) == 0)
                    node[i].a = j;
                if (strcmp(b, arr[j]) == 0)
                    node[i].b = j;
            }
        }
        double dis[31] = {0};
        dis[1] = 10; //假设一开始有1号货币10块钱
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                double w = dis[node[j].a] * node[j].r;
                if (w > dis[node[j].b])
                    dis[node[j].b] = w;
            }
        }
        int flag = 0;
        for (int i = 1; i <= m; i++)
        {
            double w = dis[node[i].a] * node[i].r;
            if (dis[node[i].b] < w)
            {
                flag = 1;
                break;
            }
        }
        
        if (flag)
            printf("Case %d: Yes\n",k);
        else
            printf("Case %d: No\n",k);
        
    }
    return 0;
}
