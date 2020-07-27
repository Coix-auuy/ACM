#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n == -1)
            break;
        printf("%lld\n",(long long int)(1/sqrt(5))*(pow(((1+sqrt(5))/2),n)-pow(((1-sqrt(5))/2),n)));
    }
    return 0;
}