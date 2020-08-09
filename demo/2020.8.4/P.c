#include <stdio.h>
#include <string.h>
int c;
void shuffle(char s1[105], char s2[105], char shufT[210])
{
    int k1 = 0,k2 = 0;
    for (int i = 0; i < 2 * c; i++)
    {
        if (i % 2 == 0)
            shufT[i] = s2[k1++];
        else
            shufT[i] = s1[k2++];
    }
    for (int i = 0; i < c; i++)
    {
        s1[i] = shufT[i];
        s2[i] = shufT[i + c];
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int t = 1; t <= N; t++)
    {

        char s1[105], s2[105], s1T[105], s2T[105], shuf[210];
        scanf("%d%s%s%s", &c, s1, s2, shuf);
        int count = 0;
        char shufT[210] = {'\0'};
        for (int i = 0; i <= c; i++)
        {
            s1T[i] = s1[i];
            s2T[i] = s2[i];
        }
        while (1)
        {
            count++;
            shuffle(s1, s2, shufT);
            if (strcmp(s1, s1T) == 0 && strcmp(s2, s2T) == 0)
            {
                printf("%d -1\n", t);
                break;
            }
            else if (strcmp(shufT, shuf) == 0)
            {
                printf("%d %d\n", t, count);
                break;
            }
        }
    }
    return 0;
}