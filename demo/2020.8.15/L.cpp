/*
    每经过一个加油站则把此加油站可加油量加入优先队列，如果发现到不了下一个加油站，则从优先队列
    中取出当前最大可加的油量，把终点也看成一个加油站只不过可加油量为0，这样每次加油的时候都是因
    为走不下去了，而且每次加的油都是当前可加的最大油量，所以保证了最少的加油次数。如果发现还没有
    到达目的地，而优先队列已经为空了，说明奶牛们无法到达目的地。；

*/
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct node
{
    int p; //可加油量
    int d; //以车辆为起点的距离
    bool operator<(node a)
    {
        return d < a.d;
    }
} s[10001];
int main()
{
    int n; //加油站数量
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &s[i].d, &s[i].p);
    int l, p; //车辆距目的地距离，当前可用油量
    scanf("%d%d", &l, &p);
    s[n].p = 0;
    s[n].d = l;//终点
    for (int i = 0; i < n; i++)
        s[i].d = l - s[i].d;
    sort(s, s + n);
    priority_queue<int> queue; //c++中优先队列默认为大顶堆
    int ans = 0, dis = 0;      //加油次数，当前距离
    for (int i = 0; i <= n; i++)
    {
        int d = s[i].d - dis;
        while (p - d < 0)
        {
            if (queue.empty())
            {
                puts("-1");
                return 0;
            }
            else
            {
                p += queue.top();
                queue.pop();
                ans++;
            }
        }
        p -= d;
        dis = s[i].d;
        queue.push(s[i].p);
    }
    printf("%d\n", ans);
    return 0;
}