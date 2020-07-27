#include <stdio.h>
#include <string.h>
int main()
{
    char a[1005];
    int b;
    // scanf("%s",a);
    // scanf("%d",&b);
    while (scanf("%s", a) != EOF)
    {
        scanf("%d", &b);
        int res = 0;
        int len = strlen(a);
        for (int i = 0; i < len; i++)
        {
            res = (res * 10 + (a[i] - '0')) % b;
        }
        printf("%d\n",res);
    }
    return 0;
}