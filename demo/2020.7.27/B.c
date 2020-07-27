#include<stdio.h>
int main()
{
    int a1[105];
    int a2[105];
    int n,m;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n == 0 && m == 0)
            break;
        for(int i = 0; i < n; i++)
            scanf("%d",&a1[i]);
        for(int i = 0; i < m; i++)
            scanf("%d",&a2[i]);
        int res[105];
        int flag;
        int k = 0;
        for(int i = 0; i < n; i++)
        {
            flag = 1;
            for(int j = 0; j < m; j++)
            {
                if(a1[i] == a2[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                res[k++] = a1[i];
            }
        }
        if(k == 0)
        {
            printf("NULL\n");
            continue;
        }
        for(int i = 0; i < k - 1; i++)
        {
            int min = i;
            for(int j = i + 1; j < k; j++)
                if(res[j] < res[min])
                    min = j;
            int t = res[i];
            res[i] = res[min];
            res[min] = t;
        }
        for(int i = 0; i < k - 1; i++)
            printf("%d ",res[i]);
        printf("%d \n",res[k - 1]);
    }
    return 0;
}