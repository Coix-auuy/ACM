#include<stdio.h>
int prime[1000001] = {0};
int main()
{
    for(int i = 2; i < 1000001 ;i++)
    {
        prime[i] = 1;
    }
    for(int i = 2; i <1000001;i++)
    {
        for(int j = 2 *i;j <1000001;j+=i)
            prime[j] = 0;
    }
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        int flag = 1;
        for(int i = 3;i < n; i+=2 )
        {
            if(prime[i]&&prime[n-i])
            {
                printf("%d = %d + %d\n",n,i,n-i);
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}