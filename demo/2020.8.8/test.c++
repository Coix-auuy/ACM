#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	Point operator+(const Point &p)
	{
		return Point(p.x + x, p.y + y);
	}
	Point operator-(const Point &p)
	{
		return Point(x - p.x, y - p.y);
	}
};
int main()
{
	Point p1(1,1),p2(-1,-1);
	p1 = p1-p2;
	printf("%lf %lf",p1.x,p1.y);
}