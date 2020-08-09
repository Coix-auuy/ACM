#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int year, mouth, day;
        scanf("%d%d%d", &year, &mouth, &day);
        if ((day + mouth) % 2 == 0 || (mouth == 9 && day == 30) || (mouth == 11 && day == 31))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}