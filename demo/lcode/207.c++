#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int numCourse;
    scanf("%d", &numCourse);
    int arr[100] = {0};
    int g[100][100] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
        arr[y]++;
    }
    vector<int> v(100);
    stack<int> s;
    priority_queue<int> q;
    for (int i = 0; i < numCourse; i++)
        if (arr[i] == 0)
        {
            q.push(i);
            arr[i] = -1;
        }
    while (!q.empty())
    {
        int y = q.top();
        q.pop();
        for (int i = 0; i < numCourse; i++)
            if (g[y][i])
            {
                arr[i]--;
            }
        for (int i = 0; i < numCourse; i++)
            if (arr[i] == 0)
            {
                q.push(i);
                arr[i] = -1;
            }
    }
    for (int i = 0; i < numCourse; i++)
        if (arr[i] != -1)
        {
            printf("flase\n");
            return 0;
        }
    printf("true\n");
    return 0;
}