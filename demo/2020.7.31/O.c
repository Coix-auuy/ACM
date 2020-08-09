#include <stdio.h>
#include <string.h>
int main()
{
    char text[256];
    while (1)
    {
        gets(text);
        if (strcmp(text, "#") == 0)
            break;
        int sum = 0;
        for (int i = 0; i < strlen(text); i++)
        {
            if (text[i] == 32)
                sum += 0;
            else
                sum += ((i + 1) * (text[i] - 'A' + 1));
        }
        printf("%d\n", sum);
    }
    return 0;
}