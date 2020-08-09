#include <stdio.h>
int prime(int n)
{
    int i;
    if(n<2)
        return 0;
    else
    {
        for(i=2;i*i<=n;++i)
        {
            if(n%i==0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int a, b, n;
    while (1)
    {
        scanf("%d%d%d", &a, &b, &n);
        if (a == 0 && b == 0 && n == 0)
            break;
        int count = 0;
        for (int i = a;; i+=b)
        {
            if (prime(i))
                count++;
            if (count == n)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}