#include <cstdio>
#include <cmath>
using namespace std;
struct Point
{
    double x, y;
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
    Point operator-(Point p)
    {
        return Point(x - p.x, y - p.y);
    }
} p[1100];
double cross(Point p1, Point p2)
{
    return p1.x * p2.y - p2.x * p1.y;
}
double area(int m)
{
    double res = 0;
    for (int i = 1; i < m - 1; i++)
        res += cross(p[i] - p[0], p[i + 1] - p[0]);
    return fabs(res / 2);
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int cnt = 1; cnt <= t; cnt++)
    {
        int m;
        scanf("%d", &m);
        p[0].x = p[0].y = 0;
        int e = 0;
        for (int i = 1; i <= m; i++)
        {
            int r, u;
            scanf("%d%d", &r, &u);
            p[i].x = p[i - 1].x + r;
            p[i].y = p[i - 1].y + u;
            r = abs(r), u = abs(u);
            if (u > r)
            {
                int t = r;
                r = u;
                u = t;
            }
            while (u != 0)
            {
                int t = r % u;
                r = u;
                u = t;
            }
            e += r;
        }
        double a = area(m);
        printf("Scenario #%d:\n%d %d %.1f\n\n", cnt, (int)(a + 1 - e / 2), e, a);
    }
    return 0;
}