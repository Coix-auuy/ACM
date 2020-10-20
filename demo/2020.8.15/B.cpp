#include <cstdio>
#include <algorithm>
using namespace std;
struct stick
{
    int l, w, d;
} s[5005];
bool cmp(stick x, stick y)
{
    if (x.l < y.l)
        return true;
    else if (x.l == y.l && x.w < y.w)
        return true;
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &s[i].l, &s[i].w), s[i].d = 0;
        sort(s, s + n, cmp);
        int sum = 0;
        for (int i = 0; i < n;)
        {
            sum++;
            int l = 0, w = 0;
            for (int j = 0; j < n; j++)
            {
                if (!s[j].d)
                {
                    if (s[j].l >= l && s[j].w >= w)
                        i++, s[j].d = 1, l = s[j].l, w = s[j].w;
                }
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}