#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int c, y;
} week[10001];
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &week[i].c, &week[i].y);
    __int64 res = 0;
    int min = 50000;
    for (int i = 0; i < n; i++)
    {
        min += s;
        if (min > week[i].c)
            min = week[i].c;
        res += week[i].y * min;
    }
    printf("%I64d\n", res);
    return 0;
}