#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int l, r;
} cow[25005];
int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &cow[i].l, &cow[i].r);
    //贪心策略，结束时间最晚的牛
    int begin = 1;
    int ans = 0;
    while (begin <= t)
    {
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            if (cow[i].l <= begin && cow[i].r >= begin)
                end = max(end, cow[i].r);
        }
        if (end == 0)
        {
            printf("-1\n");
            return 0;
        }
        begin = end + 1;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}