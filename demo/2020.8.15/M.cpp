#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        int arr[13] = {0};
        for (int i = 0; i <= n; i++)
            scanf("%d", &arr[i]);
        int max = -1; //找到需要颜料的最大值
        for (int i = 0; i < n; i++)
            if (max < arr[i])
                max = arr[i];
        int cnt = ceil(1.0 * max / 50); //最大值对应的套数
        for (int i = 0; i < n; i++)
            arr[i] = cnt * 50 - arr[i]; //剩余的各颜料数量
        while (true)
        {
            while (true)
            {
                sort(arr, arr + n, cmp);
                if (arr[2] == 0)
                    break;
                arr[n]--;
                arr[0]--;
                arr[1]--;
                arr[2]--;
            }
            if (arr[n] <= 0)
                break;
            else
            {
                cnt++;
                for (int i = 0; i < n; i++)
                    arr[i] += 50;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}