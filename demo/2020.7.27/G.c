#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int N;
        scanf("%d", &N);
        int a[32769] = {0};
        int num = 0;
        for (int i = 2; i <= N; i++)
        {
            if (N % i == 0)
            {
                for (int j = i; j <= N; j += i)
                    a[j] = 1;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            if (a[i] == 0)
            {
                num++;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}