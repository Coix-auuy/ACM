#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int size = 100;
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
    Point operator*(double a) { return Point(a * x, a * y); }
    Point operator/(double a) { return Point(x / a, y / a); }
} p[size][size];
typedef Point Vector;
double cross(const Point p1, const Point p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
double dot(const Point p1, const Point p2)
{
    return p1.x * p2.x + p1.y * p2.y;
}
struct Line
{
    Point p1, p2;
    Line() {}
    Line(Point _a, Point _b) : p1(_a), p2(_b) {}
} l[size];
//获得交点
Point getCrossPoint(Line l1, Line l2)
{
    Vector base = l2.p2 - l2.p1;
    double d1 = fabs(cross(base, l1.p1 - l2.p1));
    double d2 = fabs(cross(base, l1.p2 - l2.p1));
    double t = d1 / (d1 + d2);
    return l1.p1 + (l1.p2 - l1.p1) * t;
}
//四个点成逆时针
double area(Point p1, Point p2, Point p3, Point p4)
{
    Point arr[4];
    arr[0] = p1;
    arr[1] = p2;
    arr[2] = p3;
    arr[3] = p4;
    double res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = res + cross(arr[i], arr[(i + 1) % 4]);
    }
    return fabs(res / 2);
}
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        //四个顶角
        p[0][0].x = p[0][0].y = 0;
        p[0][n + 1].x = 0;
        p[0][n + 1].y = 1;
        p[n + 1][n + 1].x = p[n + 1][n + 1].y = 1;
        p[n + 1][0].x = 1;
        p[n + 1][0].y = 0;
        for (int i = 1; i <= n; i++)
        {
            p[i][0].y = 0;
            scanf("%lf", &p[i][0].x);
        }
        for (int i = 1; i <= n; i++)
        {
            p[i][n + 1].y = 1;
            scanf("%lf", &p[i][n + 1].x);
        }
        for (int i = 1; i <= n; i++)
        {
            p[0][i].x = 0;
            scanf("%lf", &p[0][i].y);
        }
        for (int i = 1; i <= n; i++)
        {
            p[n + 1][i].x = 1;
            scanf("%lf", &p[n + 1][i].y);
        }
        //求交点
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                p[i][j] = getCrossPoint(Line(p[i][0], p[i][n + 1]), Line(p[0][j], p[n + 1][j]));
        }
        //求面积
        double max = -1;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                double a = area(p[i][j], p[i + 1][j], p[i + 1][j + 1], p[i][j + 1]);
                if (a > max)
                    max = a;
            }
        }
        printf("%lf\n",max);
    }
    return 0;
}