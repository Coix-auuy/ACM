#include <stdio.h>
#include <stdlib.h>
int cmp(const void *x, const void *y)
{
    return *(double *)x - *(double *)y;
}
int main()
{
    int n, m, c = 0;
    while (scanf("%d%d", &n, &m) && (n || m))
    {
        c++;
        double arr[1010] = {0};
        for (int i = 0; i < n * m; i++)
            scanf("%lf", &arr[i]);
        double w = 0;
        scanf("%lf", &w);
        qsort(arr, n * m, sizeof(double), cmp);
        if (w == 0.0)
        {
            printf("Region %d\n", c);
            printf("Water level is %.2lf meters.\n", arr[0]);
            printf("%.2lf percent of the region is under water.\n", 0.0);
            continue;
        }
        int i = 1;
        while (i < n * m)
        {
            if (w - i * (arr[i] - arr[i - 1]) * 100 <= 0)
                break;
            w -= i * (arr[i] - arr[i - 1]) * 100;
            i++;
        }
        double h = 0;
        h = (double)w / (100 * i) + arr[i - 1];
        printf("Region %d\n", c);
        printf("Water level is %.2lf meters.\n", h);
        printf("%.2lf percent of the region is under water.\n", (double)100 * i / (n * m));
    }
    return 0;
}