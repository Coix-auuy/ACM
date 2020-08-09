#include <stdio.h>
int main()
{
    int day;
    while (1)
    {
        scanf("%d", &day);
        if (day == 0)
            break;
        printf("%d", day);
        int t = 1;
        int sum = 0;
        int i = 0;
        while (day--)
        {
            i++;
            sum += t;
            if (i == t)
            {
                t++;
                i = 0;
            }
            
        }
        printf(" %d\n", sum);
    }
    return 0;
}