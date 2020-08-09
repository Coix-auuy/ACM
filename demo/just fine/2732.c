#include<stdio.h>
int main()
{
    double n;
    scanf("%lf",&n);
    double e = 1.0;
    for(int i = n; i >= 1; i--)
    {
        double k = 1;
        for(int j = 1; j <= i; j++)
        {
            k *= j;
        }
        e += 1/k;
    }
    printf("%.15lf",e);
    return 0;
}