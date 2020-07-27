#include<stdio.h>
#include<math.h>
int res[500005];
int main()
{
    for(int i = 1; i<= 250000;i++)
    {
        for(int j = i + i; j <500005;j+=i)
            res[j]+=i;
    }
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int num;
        scanf("%d",&num);
        printf("%d\n",res[num]);
    }
    return 0;
}