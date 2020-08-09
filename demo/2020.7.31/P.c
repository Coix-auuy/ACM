#include <stdio.h>
#include <math.h>
typedef struct Node
{
    double t, d, h;
} node;
int main()
{
    while (1)
    {
        node n;
        n.t = n.d = n.h = 101;
        char op;
        scanf("%c", &op);
        switch (op)
        {
        case 'T':
            scanf("%lf", &n.t);
            break;
        case 'D':
            scanf("%lf", &n.d);
            break;
        case 'H':
            scanf("%lf", &n.h);
            break;
        case 'E':
            return 0;
        }
        getchar();
        scanf("%c", &op);
        switch (op)
        {
        case 'T':
            scanf("%lf", &n.t);
            break;
        case 'D':
            scanf("%lf", &n.d);
            break;
        case 'H':
            scanf("%lf", &n.h);
            break;
        }
        getchar();
        if (n.t == 101)
        {
            double e = 6.11 * pow(2.718281828, (5417.7530 * ((1 / 273.16) - (1 / (n.d + 273.16)))));
            double h = (0.5555) * (e - 10.0);
            n.t = n.h - h;
        }
        if (n.d == 101)
        {
            double h = n.h - n.t;
            double e = h/0.5555 + 10;
            double temp = -1/273.16 + log(e/6.11)/5417.7530;
            n.d = (-1 - 273.16 * temp) / temp;
        }
        if(n.h == 101)
        {
            double e = 6.11 * pow(2.718281828, (5417.7530 * ((1 / 273.16) - (1 / (n.d + 273.16)))));
            double h = (0.5555) * (e - 10.0);
            n.h = n.t + h;
        }
        printf("T %.1f D %.1f H %.1f\n",n.t,n.d,n.h);
    }
    return 0;
}