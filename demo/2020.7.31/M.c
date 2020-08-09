#include <stdio.h>
int prime[10001] = {0};
int main()
{
    for (int i = 2; i < 10001; i++)
    {
        prime[i] = 1;
    }
    for (int i = 2; i < 10001; i++)
    {
        for (int j = 2 * i; j < 10001; j += i)
            prime[j] = 0;
    }

    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        int start = 2;
        int count = 0;
        while (start <= n)
        {
            int sum = 0;
            if (prime[start])
            {
                for (int i = start;; i++)
                {
                    if (prime[i])
                        sum += i;
                    if (sum > n)
                        break;
                    if (sum == n)
                    {
                        count++;
                        break;
                    }
                }
            }
            start++;
        }
        printf("%d\n", count);
    }
    return 0;
}