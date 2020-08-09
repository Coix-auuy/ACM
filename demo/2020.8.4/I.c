#include <stdio.h>
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        printf("%d %d ",n,m);
        if(n > m)
            n^=m^=n^=m;
        int max = -1;
        for(int i = n; i <= m; i++)
        {
            int t = i;
            int count = 1;
            while(t != 1)
            {
                if(t % 2 != 0)
                    t = 3 * t + 1;
                else
                    t = t / 2;
                count++;
            }
            if(max < count)
                max = count;
        }
        printf("%d\n",max);
    }
    return 0;
}