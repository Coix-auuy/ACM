#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    char code[100100] = {'0'};
    while (scanf("%s", code) && strcmp(code, "END") != 0)
    {
        int cnt[27] = {0};
        for (int i = 0; i < strlen(code); i++)
        {
            if (code[i] >= 'A' && code[i] <= 'Z')
                cnt[code[i] - 'A']++;
            else
                cnt[26]++;
        }
        int sum = 0;
        sort(cnt, cnt + 27);
        if (cnt[25] == 0)
        {
            printf("%d %d %.1lf\n", 8 * strlen(code), cnt[26], 8.0 * strlen(code) / cnt[26]);
            continue;
        }
        while (true)
        {
            sort(cnt, cnt + 27);
            if (cnt[25] == 0)
                break;
            for (int i = 0; i < 27; i++)
            {
                if (cnt[i] > 0)
                {
                    sum += cnt[i] + cnt[i + 1];
                    cnt[i + 1] = cnt[i] + cnt[i + 1];
                    cnt[i] = 0;
                    break;
                }
            }
        }
        printf("%d %d %.1lf\n",8 * strlen(code),sum,8.0 * strlen(code)/sum);
    }
    return 0;
}