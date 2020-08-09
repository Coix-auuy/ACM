#include<stdio.h>
int main()
{
    while(1)
    {
        
        int res = 0;
        int i = 0;
        while(1)
        {
            
            double arr[16];
            scanf("%lf",&arr[i]);
            if(arr[i] == 0) 
            {
                i = 0;
                break;
            }
                
            if(arr[i] == -1)
                return 0;
            for(int j = 0; j < i; j++)
            {
                if(arr[i] / 2 == arr[j] || arr[j] / 2 == arr[i] )
                    res++;
            }
            i++;
        }
        printf("%d\n",res);
    }
}