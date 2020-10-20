#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    __int64 d, p;
    int i;
    bool operator<(node a)
    {
        return p > a.p;
    }
} s[1010];
struct wei
{
    int j;
    __int64 w;
    bool operator<(wei a)
    {
        return w > a.w;
    }
} w[1010];
int main()
{
    __int64 n, t;
    scanf("%I64d%I64d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i].w), w[i].j = i;
    for (int i = 0; i < n; i++)
        scanf("%I64d", &s[i].d);
    for (int i = 0; i < n; i++)
    {
        scanf("%I64d", &s[i].p);
        s[i].p = s[i].p - s[i].d * t; //这个村庄每公斤猪肉纯利润
        s[i].i = i;
    }
    int ans[1010] = {0};
    sort(s, s + n);
    sort(w, w + n);
    for (int i = 0; i < n; i++)
    {
        ans[s[i].i] = w[i].j;
    }
    for (int i = 0; i < n - 1; i++)
        printf("%d ", ans[i] + 1);
    printf("%d\n", ans[n - 1] + 1);
    return 0;
}