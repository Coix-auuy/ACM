#include <stdio.h>
#include <string.h>
char left[3][10], right[3][10], arr[3][5];
int light(int x)
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == 'u' && strchr(right[i], x + 'A') == NULL)
            return 0;
        if (arr[i][0] == 'e' && (strchr(right[i], x + 'A') != NULL || strchr(left[i], x + 'A') != NULL))
            return 0;
        if (arr[i][0] == 'd' && strchr(left[i], x + 'A') == NULL)
            return 0;
    }
    return 1;
}
int heavy(int x)
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == 'u' && strchr(left[i], x + 'A') == NULL)
            return 0;
        if (arr[i][0] == 'e' && (strchr(right[i], x + 'A') != NULL || strchr(left[i], x + 'A') != NULL))
            return 0;
        if (arr[i][0] == 'd' && strchr(right[i], x + 'A') == NULL)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        for (int i = 0; i < 3; i++)
            scanf("%s%s%s", left[i], right[i], arr[i]);
        for (int i = 0; i < 12; i++)
        {
            if (light(i))
            {
                printf("%c is the counterfeit coin and it is light.\n", i + 'A');
                break;
            }

            if (heavy(i))
            {
                printf("%c is the counterfeit coin and it is heavy.\n", i + 'A');
                break;
            }
        }
    }
    return 0;
}