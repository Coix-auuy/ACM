#include <iostream>
#include <cstdio>
using namespace std;
const double eqs = 1e-8;
const double INF = 1e12;
int n;
struct Point
{
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator-(const Point p)
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+(const Point p)
    {
        return Point(x + p.x, y + p.y);
    }
} u[41], d[41];
struct Line
{
    Point p1, p2;
    Line(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
};
double cross(const Point p1, const Point p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
double solve()
{

    return 0;
}
int main()
{
    while (scanf("%d", &n) && n)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &u[i].x, &u[i].y);
            d[i].x = u[i].x;
            d[i].y = u[i].y - 1;
        }
        double res = solve();
        if (flag)
            printf("Through all the pipe.\n");
        else
            printf("%.2lf\n", res);
    }
    return 0;
}