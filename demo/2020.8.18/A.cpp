#include <cstdio>
#include <cstring>
using namespace std;
int col[41], sizeArr[11]; //col[i]记录第i列被填充个数，sizeArr[i]记录i边长的蛋糕个数
int s, n;                 //盒子尺寸，蛋糕个数
bool DFS(int fillNum)     //fillNum 已装入蛋糕个数
{
    if (fillNum == n)
        return true;
    //寻找格子数被填充最少的列，靠左优先
    int min = 50;
    int prow;
    for (int i = 1; i <= s; i++)
    {
        if (min > col[i])
        {
            min = col[i];
            prow = i;
        }
    }
    //枚举各种尺寸的蛋糕，自下而上的放入盒子
    for (int size = 10; size >= 1; size--)
    {
        if (!sizeArr[size])
            continue;
        int flag = 1;
        //检查尺寸为 size 的蛋糕放入盒子纵向或横向是否越界
        if (s - col[prow] >= size && s - prow + 1 >= size)
        {
            //检查 prow 到 prow + size - 1 的所有列中纵向所剩下的空间是否符合蛋糕尺寸
            for (int i = prow + 1; i <= prow + size - 1; i++)
            {
                if (col[i] > col[prow])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                //放入蛋糕
                sizeArr[size]--;
                for (int i = prow; i <= prow + size - 1; i++)
                    col[i] += size;
                //继续处理下一个蛋糕
                if (DFS(fillNum + 1))
                    return true;
                //回溯
                sizeArr[size]++;
                for (int i = prow; i <= prow + size - 1; i++)
                    col[i] -= size;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        memset(col, 0, sizeof(col));
        memset(sizeArr, 0, sizeof(sizeArr));
        scanf("%d %d", &s, &n);
        int cnt = 0; //size > s / 2
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int size;
            scanf("%d", &size);
            area += size * size;
            sizeArr[size]++;
            if (size > s / 2)
                cnt++;
        }
        if (cnt > 1 || area != s * s)
        {
            printf("HUTUTU!\n");
            continue;
        }
        if (DFS(0))
            printf("KHOOOOB!\n");
        else
            printf("HUTUTU!\n");
    }
    return 0;
}