#include <stdio.h>
#include <math.h>
double map[1010][1010], x[1010], y[1010];
double max(double x, double y)
{
    if (x > y)
        return x;
    return y;
}
int main()
{
    int n;
    int t = 0;
    while (scanf("%d", &n) && n)
    {
        t++;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        //floyd
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (map[i][j] > max(map[i][k], map[k][j]))
                        map[i][j] = max(map[i][k], map[k][j]);
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", t, map[1][2]);
    }
    return 0;
}