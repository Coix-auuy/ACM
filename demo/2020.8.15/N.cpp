#include <cstdio>
#include <algorithm>
using namespace std;
int l, n, m; //起点到终点的距离，起点到终点中间的石块数量 ，可移除石块数量
int arr[50010];
bool c(int d)
{
    int last = 0;
    int crt;
    for (int i = 1; i < n - m; i++)
    {
        crt = last + 1;
        while (crt < n && arr[crt] - arr[last] < d)
            crt++;
        if (crt == n)
            return false;
        last = crt;
    }
    return true;
}
int main()
{

    scanf("%d%d%d", &l, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    arr[0] = 0;
    arr[n + 1] = l;
    n += 2;
    sort(arr, arr + n);
    int lb = 0, ub = 2 * l;
    while (ub - lb > 1)
    {
        int mid = (ub + lb) / 2;
        if (c(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", lb);
    return 0;
}