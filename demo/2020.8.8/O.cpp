#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(a * x, a * y); }
    Point operator/(double a) { return Point(x / a, y / a); }

} p[50005];
double dot(const Point &p1, const Point &p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
double cross(const Point &p1, const Point &p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
double squaredDis(const Point &p1, const Point &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
bool cmp(Point p1, Point p2)
{
    double x = cross(p1 - p[0], p2 - p[0]);
    if (x > 0)
        return true; //叉积大于0说明p1在p2的顺时钟方向
    if (x == 0 && squaredDis(p1, p[0]) < squaredDis(p2, p[0]))
        return true;
    return false;
}
double multi(Point p1, Point p2, Point p3)
{
    return cross(p2 - p1, p3 - p1);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    //Graham-scan begin
    //1.找到最左下方的点
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))
            k = i;
    }
    swap<Point>(p[k], p[0]);
    sort(p, p + n, cmp);
    Point s[50005]; //栈
    s[0] = p[0];
    s[1] = p[1];
    int t = 1;
    for (int i = 2; i < n; i++)
    {
        // 发现在栈里边一个顶点处没有向左转时，就把该顶点移除出去
        while (t >= 1 && multi(s[t - 1], s[t], p[i]) <= 0)
            t--;
        s[++t] = p[i];
    }
    //Gramham-scan end
    double max = -1;
    for (int i = 0; i <= t; i++)
    {
        for (int j = i + 1; j <= t; j++)
        {
            if (squaredDis(s[i], s[j]) > max)
                max = squaredDis(s[i], s[j]);
        }
    }
    printf("%.0lf\n", max);
    return 0;
}