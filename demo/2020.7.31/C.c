#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int num;
        scanf("%d", &num);
        int arr[31];
        for (int i = 0; i < num; i++)
            scanf("%d", &arr[i]);

        if (num % 2 != 0)
            printf("YES\n");
        else
        {
            int even = 0, odd = 0;
            for (int i = 0; i < num; i++)
            {
                if (arr[i] == 1)
                {
                    if ((i + 1) % 2 == 0)
                        even++;
                    else
                        odd++;
                }
            }
            if(fabs(even - odd) <= 1)
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
    return 0;
}