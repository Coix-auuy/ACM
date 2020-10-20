#include <cstdio>
using namespace std;
int main()
{
    while (true)
    {
        int n = 0, arr[6], a, b;
        int flag = 0;
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", &arr[i]);
            flag += arr[i];
        }
        if (flag == 0)
            break;
        n = arr[5] + arr[4] + arr[3] + (arr[2] + 3) / 4;
        int u[4] = {0, 5, 3, 1};
        b = 5 * arr[3] + u[arr[2] % 4];
        if (arr[1] > b)
            n += (arr[1] - b + 8) / 9;
        a = 36 * n -36*arr[5] -  25 * arr[4] - 16 * arr[3] - 9 * arr[2] - 4 * arr[1];
        if (arr[0] > a)
            n += ((arr[0] - a + 35) / 36);
        printf("%d\n", n);
    }
    return 0;
}