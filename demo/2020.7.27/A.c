#include<stdio.h>
int main()
{
    int n;
    int a[1000];
    int sum;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sum = a[0] * 6 + 5;
        for(int i = 1; i < n; i++)
        {
            if(a[i] > a[i - 1])
                sum += (a[i] - a[i - 1]) * 6 + 5;
            else
            {
                sum += (a[i - 1] - a[i]) * 4 + 5;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}