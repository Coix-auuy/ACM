#include <stdio.h>
#include <math.h>
typedef struct Color
{
    int r, g, b;
} color;
int main()
{
    color arr[16];
    for (int i = 0; i < 16; i++)
        scanf("%d%d%d", &arr[i].r, &arr[i].g, &arr[i].b);
    int r, g, b;
    while (1)
    {
        scanf("%d%d%d", &r, &g, &b);
        if (r == -1 && g == -1 && b == -1)
            break;
        int index = 0;
        double min = sqrt(pow(arr[0].r - r, 2) + pow(arr[0].g - g, 2) + pow(arr[0].b - b, 2));
        for (int i = 1; i < 16; i++)
        {
            double temp = sqrt(pow(arr[i].r - r, 2) + pow(arr[i].g - g, 2) + pow(arr[i].b - b, 2));
            if (min > temp)
            {
                min = temp;
                index = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, arr[index].r, arr[index].g, arr[index].b);
    }
    return 0;
}