#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
    double l, r;
    bool operator<(const node &t) const
    {
        return r < t.r;
    }
} is[1010];
int main()
{
    int n;
    double d;
    int c = 0;
    while (scanf("%d%lf", &n, &d) && (n || d))
    {
        c++;
        int flag = 0;
        double x, y;
        for (int i = 0; i < n; i++)
        {

            scanf("%lf%lf", &x, &y);
            if (flag)
                continue;
            if (y > d)
            {
                flag = 1;
                continue;
            }
            double temp = sqrt(d * d - y * y);
            is[i].l = x - temp;
            is[i].r = x + temp;
        }
        if (flag)
        {
            printf("Case %d: -1\n", c);
            continue;
        }
        sort(is, is + n);
        int res = 1;
        double r =  is[0].r;
        for (int i = 1; i < n; i++)
        {
            if (is[i].l > r)
            {
                res++;
                r = is[i].r;
            }
        }
        printf("Case %d: %d\n", c, res);
    }
    return 0;
}