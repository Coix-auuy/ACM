#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int size = 1005;
int n; //总点数
struct Point
{
    double x, y;
    Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    Point operator-(const Point p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+(const Point p)
    {
        return Point(x + p.x, y + p.y);
    }
} p[size], stack[size];
double dot(const Point p1, const Point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
double cross(const Point p1, const Point p2)
{
    return p1.x * p2.y - p2.x * p1.y;
}
double disSquare(const Point p1, const Point p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
bool cmp(Point p1, Point p2)
{
    double x = cross(p1 - p[0], p2 - p[0]); //如果叉积为正说明p[0]p1在p[0]p2的顺时针方向
    if (x > 0)
        return true;
    //如果叉积等于零说明两线重合，此时按照距离从小到大排列
    if (x == 0 && disSquare(p1, p[0]) < disSquare(p2, p[0]))
        return true;
    return false;
}
double mutil(Point p1, Point p2, Point p3)
{
    return cross(p2 - p1, p3 - p1);
}
//返回凸包顶点数
int graham_scan()
{
    int index = 0;
    //找到p0--左下点
    for (int i = 1; i < n; i++)
    {
        if (p[index].y > p[i].y || (p[index].y == p[i].y && p[index].x > p[i].x))
            index = i;
    }
    swap<Point>(p[0], p[index]);
    //按照极坐标逆时针排序
    sort(p, p + n, cmp);
    stack[0] = p[0];
    stack[1] = p[1];
    int t = 1; //栈顶
    for (int i = 2; i < n; i++)
    {
        // 发现在栈里边一个顶点处没有向左转时，就把该顶点移除出去
        while (t >= 1 && mutil(stack[t - 1], stack[t], p[i]) <= 0)
            t--;
        stack[++t] = p[i];
    }
    return t + 1;
}
int main()
{
    double l;
    scanf("%d%lf", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    int t = graham_scan();
    double girth = 0.0; //凸包周长
    for (int i = 0; i < t; i++)
    {
        girth += sqrt(disSquare(stack[i], stack[(i + 1) % t]));
    }
    printf("%.0lf", girth + 2 * 3.14159265358979323846 * l);
    return 0;
}