#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);//n的因子个数是偶数还是奇数->n如果是完全平方数则因子数是奇数->小于等于n的数中完全平方数的个数为根号n
        printf("%d\n",(int)sqrt(n));
    }
    return 0;
}