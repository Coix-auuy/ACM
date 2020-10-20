#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int peop[1001] = {0};
        for (int i = 0; i < n; i++)
            scanf("%d", &peop[i]);
        sort(peop, peop + n);
        int sum = 0;
        while (n > 3)
        {
            int t1 = peop[1] + peop[0] + peop[n - 1] + peop[1];
            int t2 = peop[n - 1] + peop[0] + peop[n - 2] + peop[0];
            sum += min(t1, t2);
            n -= 2;
        }
        if (n == 1)
            sum += peop[0];
        else if (n == 2)
            sum += peop[1];
        else if (n == 3)
            for (int i = 0; i < n; i++)
                sum += peop[i];
        printf("%d\n", sum);
    }
    return 0;
}