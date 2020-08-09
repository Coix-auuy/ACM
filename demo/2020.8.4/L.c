#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        int arr[51][51] = {0};
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &arr[i][j]);
        int res = 0, duoI = 0, duoJ = 0;
        while (k > 0)
        {
            int max = 0, maxI, maxJ;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (max < arr[i][j])
                    {
                        max = arr[i][j];
                        maxI = i;
                        maxJ = j;
                    }
            if (max == 0)
                break;
            if (duoI == 0)
                duoJ = maxJ;
            if (1 + maxI + abs(maxI - duoI) + abs(maxJ - duoJ) <= k)
            {
                k -= 1 + abs(maxI - duoI) + abs(maxJ - duoJ);
                duoI = maxI;
                duoJ = maxJ;
                res += arr[maxI][maxJ];
                arr[maxI][maxJ] = 0;
            }
            else
                break;
        }
        printf("%d\n", res);
    }
}