//思路比较简单，就是找出一个点的两个临界圆的圆心位置，然后就是简单的比较了，应该算是贪心题吧
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 1000
using namespace std;

struct island
{
    double l, r;
    bool operator<(const island &t) const
    {
        return r < t.r;
    }
} lnd[N];
int main()
{
    int n, i, cs = 1, flag, ans;
    double d, x, y, r, tmp, dd;
    while (cin >> n >> d, n || d)
    {
        dd = d * d;
        flag = 0;
        for (i = 0; i < n; i++)
        {
            cin >> x >> y;
            if (y > d)
                flag = 1;
            tmp = sqrt(dd - y * y);
            lnd[i].l = x - tmp;
            lnd[i].r = x + tmp;
        }
        cout << "Case " << cs++ << ": ";
        if (flag == 1)
        {
            cout << -1 << endl;
            continue;
        }

        sort(lnd, lnd + n);
        for (i = ans = 1, r = lnd[0].r; i < n; i++)
        {
            if (lnd[i].l > r)
            {
                ans++;
                r = lnd[i].r;
            }
        }
        cout << ans << endl;
    }
    return 0;
}