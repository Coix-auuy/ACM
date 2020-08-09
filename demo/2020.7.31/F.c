#include <stdio.h>
int main()
{
    int arr[10001] = {0};
    for (int i = 1; i <= 10000; i++)
    {
        int t = i;
        int sum = t;
        while (t)
        {
            sum += t % 10;
            t /= 10;
        }
        if(sum <= 10000)
            arr[sum] = 1;
    }
    for(int i = 1; i <= 10000; i++)
        if(arr[i] != 1)
            printf("%d\n",i);
    return 0;
}
