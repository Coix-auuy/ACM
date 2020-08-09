#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char Haab[19][10] = {{"pop"}, {"no"}, {"zip"}, {"zotz"}, {"tzec"}, {"xul"}, {"yoxkin"}, {"mol"}, {"chen"}, {"yax"}, {"zac"}, {"ceh"}, {"mac"}, {"kankin"}, {"muan"}, {"pax"}, {"koyab"}, {"cumhu"}, {"uayet"}};
    char Tzolkin[20][10] = {{"imix"}, {"ik"}, {"akbal"}, {"kan"}, {"chicchan"}, {"cimi"}, {"manik"}, {"lamat"}, {"muluk"}, {"ok"}, {"chuen"}, {"eb"}, {"ben"}, {"ix"}, {"mem"}, {"cib"}, {"caban"}, {"eznab"}, {"canac"}, {"ahau"}};
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    while (n--)
    {
        int hDay, tDay, hYear, tYear;
        char hMouth[10];
        scanf("%d", &hDay);
        getchar();
        scanf("%s", hMouth);
        scanf("%d", &hYear);
        int count = 1; //记月数
        for (int i = 0; i < 19; i++)
        {
            if (strcmp(hMouth, Haab[i]) == 0)
                break;
            count++;
        }
        int sum = hYear * 365 + (count - 1) * 20 + hDay + 1;
        tYear = sum / 260;
        int num = sum % 260;
        if (num == 0)
        {
            tYear--;
            num += 260;
        }
        // 其实不分啥天，月了，把这两都看成是在一年中不断循环的就行。
        int tMouth = num % 20;
        if(tMouth == 0)
            tMouth = 20;

        tDay = num % 13;
        if (tDay == 0)
            tDay = 13;
        printf("%d %s %d\n",tDay,Tzolkin[tMouth - 1],tYear);
    }
   
    return 0;
}