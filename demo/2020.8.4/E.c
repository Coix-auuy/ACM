#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char arr[10000];
        int k = 0;
        int count = 0;
        int left[21];
        for (int i = 0; i < n; i++)
            scanf("%d", &left[i]);
        for (int i = 0; i < left[0]; i++)
        {
            arr[k++] = '(';
        }
        arr[k++] = ')';
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < left[i] - left[i - 1]; j++)
                arr[k++] = '(';
            arr[k++] = ')';
        }
        int res[10000];
        int q = 0;
        for (int i = 0; i < k; i++)
        {
            if (arr[i] == ')')
            {
                int count = 1;
                int flag = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    if (arr[j] == '(')
                    {
                        count--;
                        flag++;
                    }

                    else
                        count++;
                    if (count == 0)
                    {
                        res[q++] = flag;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < q - 1; i++)
            printf("%d ", res[i]);
        printf("%d\n", res[q - 1]);
    }
    return 0;
}