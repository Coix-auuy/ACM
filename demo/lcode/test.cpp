#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double t = 1;
    double res = 0;
    double one = 1;
    for (int i = 1; i <= 16; i++)
    {
        if (i <= 10)
            t *= pow(0.5, i);
        else
            t *= pow(0.5, 10);
    }
    one -= t;
    t = 1;
    for (int i = 1; i <= 16; i++)
    {

        if (i <= 10)
        {
            res += i * t * (one - pow(0.5, i));
            t *= pow(0.5, i);
        }
        else
        {
            res += i * t * (one - pow(0.5, 10));
            t *= pow(0.5, 10);
        }
    }

    printf("%lf", res);
    return 0;
}