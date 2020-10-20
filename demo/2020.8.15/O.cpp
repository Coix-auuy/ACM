/*
    每次都选择攻击，如果hp <= 0 回溯，回到可以获得最大生命值那个回合（治愈，或者躲避），因此使用优先
    队列每次把y 、Ai中的最大值加入优先队列。另外使用 MAX 记录在所有回合中能够造成的最大输出，如果失
    败，则输出 MAX * x；
*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n, x, y, h1, h2;
    scanf("%d%d%d%d%d", &n, &x, &y, &h1, &h2);
    int arr[100100] = {0};
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int cnt = 0, MAX = -1, i;
    priority_queue<int> q;
    for (i = 0; i < n; i++)
    {
        cnt++;
        if (h2 <= cnt * x)
            break;
        MAX = max(MAX, cnt);
        h1 -= arr[i];
        q.push(max(arr[i], y));
        if (h1 <= 0 && !q.empty())
        {
            h1 += q.top();
            q.pop();
            cnt--;
        }
    }
    if (i < n)
    {
        printf("Win\n%d", i + 1);
    }
    else
    {
        printf("Lose\n%I64d", (__int64)MAX * x);
    }
    return 0;
}