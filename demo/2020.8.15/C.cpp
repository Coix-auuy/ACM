#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int sx, sy, ex, ey;
} s[105];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int arr[105] = {0};
        int n, k;
        scanf("%d%d", &n, &k);
        int e = -1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &s[i].sx, &s[i].sy, &s[i].ex, &s[i].ey);
            if (s[i].sx > s[i].ex)
                swap(s[i].sx, s[i].ex);
            if (e < s[i].ex)
                e = s[i].ex;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = s[i].sx; j <= s[i].ex; j++)
                arr[j]++;
        }
        int cnt = 0;
        for (int i = 0; i <= e; i++)
        {
            if (arr[i] > k)
            {
                int index = -1, max = 0;
                for (int j = 0; j < n; j++)
                {
                    if (s[j].sx <= i && s[j].ex >= i)
                    {
                        if (s[j].ex - i + 1 > max)
                            max = s[j].ex - i + 1, index = j;
                    }
                }
                for (int j = s[index].sx; j <= s[index].ex; j++)
                    arr[j]--;
                cnt++;
                swap<node>(s[index], s[n - 1]);
                n--;
                i--;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}