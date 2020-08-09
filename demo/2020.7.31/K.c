#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        char address[33];
        scanf("%s", address);
        int sum = 0;
        int t = 128;
        for (int i = 0; i < 32; i++)
        {
            if (address[i] == '1')
                sum += t;
            t /= 2;
            if ((i + 1) % 8 == 0 && i != 31)
            {
                printf("%d.",sum);
                sum = 0;
                t = 128;
            }
            if(i == 31)
            {
                printf("%d\n",sum);
            }
            
        }
    }
    return 0;
}