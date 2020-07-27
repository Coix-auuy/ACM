#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int s = 0; s < n; s++)
    {
        int z;
        scanf("%d",&z);
        printf("%d\n",z*(2*z-1)+1);
    }
    return 0;
}