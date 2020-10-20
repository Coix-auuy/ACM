#include <iostream>
#include <cstdio>
#include <cmath>
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
    double dot(const Point &p1, const Point &p2)
    {
        return p1.x * p2.x + p1.y * p2.y;
    }
    double cross(const Point &p1, const Point &p2)
    {
        return p1.x * p2.y - p1.y * p2.x;
    }
};
struct line
{
    Point p1, p2;
    line() {}
    line(Point a, Point b) : p1(a), p2(b) {}
} l[100005];
int res[100005];
bool base(line l1, line l2)
{
    //如果l2的两点在l1的两侧，则以l1的方程f(x,y) = 0;f(l2.p1) * f(l2.p2) <= 0;等于0说明在l1上
    // f(x,y) = (y-y1)(x2-x1) - (x-x1)(y2-y1) = 0;两点式
    double f1 = (l2.p1.y - l1.p1.y) * (l1.p2.x - l1.p1.x) - (l2.p1.x - l1.p1.x) * (l1.p2.y - l1.p1.y);
    double f2 = (l2.p2.y - l1.p1.y) * (l1.p2.x - l1.p1.x) - (l2.p2.x - l1.p1.x) * (l1.p2.y - l1.p1.y);
    // printf("%lf %lf",f1,f2);
    if (f1 * f2 > 0)
        return false;
    return true;
}
bool intersect(line l1,line l2)
{
    if(!base(l1,l2))
        return false;
    if(!base(l2,l1))
        return false;
    return true;
}
int main()
{
    int n;
    // line a(Point(2,3),Point(3,1)),b((Point(1,-2.0)),Point(8,4));
    // printf("%d",intersect(a,b));
    while (scanf("%d", &n) && n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            l[i] = line(Point(x1, y1), Point(x2, y2));
        }
        for (int i = 0; i < n; i++)
        {
            int j;
            for (j = i + 1; j < n; j++)
            {
                if (intersect(l[i], l[j]))
                    break;
            }
            if (j >= n)
                res[count++] = i + 1;
        }
        printf("Top sticks: ");
        for (int i = 0; i < count - 1; i++)
            printf("%d, ", res[i]);
        printf("%d.\n", res[count - 1]);
    }
    return 0;
}
