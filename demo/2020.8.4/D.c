#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d", &t);
    char arr[30][10] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}, {"..--"}, {"---."}, {".-.-"}, {"----"}};
    for (int q = 1; q <= t; q++)
    {
        char text[105] = {0}, code[1005] = {'\0'};
        int number[105] = {0};
        scanf("%s", text);
        for (int i = 0; i < strlen(text); i++)
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                number[i] = strlen(arr[text[i] - 'A']);
                strcat(code, arr[text[i] - 'A']);
            }
            else
            {
                number[i] = 4;
                switch (text[i])
                {
                case '_':
                    strcat(code, "..--");
                    break;
                case '.':
                    strcat(code, "---.");
                    break;
                case ',':
                    strcat(code, ".-.-");
                    break;
                case '?':
                    strcat(code, "----");
                    break;
                default:
                    break;
                }
            }
        }
        int revNum[105] = {0};
        int k = 0;
        for (int i = strlen(text) - 1; i >= 0; i--)
            revNum[k++] = number[i];
        int start = 0;
        char res[105] = {'\0'}, temp[10] = {'\0'};
        for (int i = 0; i < strlen(text); i++)
        {
            k = 0;
            for (int j = start; j < start + revNum[i]; j++)
            {
                temp[k++] = code[j];
            }
            temp[k] = '\0';
            for (int j = 0; j < 30; j++)
            {
                if (strcmp(temp, arr[j]) == 0)
                {
                    if (j >= 0 && j < 26)
                    {
                        char t[2];
                        t[0] = j + 'A';
                        t[1] = '\0';
                        strcat(res, t);
                    }

                    else
                    {
                        switch (j)
                        {
                        case 26:
                            strcat(res, "_");
                            break;
                        case 27:
                            strcat(res, ".");
                            break;
                        case 28:
                            strcat(res, ",");
                            break;
                        case 29:
                            strcat(res, "?");
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
            start += revNum[i];
        }
        printf("%d: %s\n", q, res);
    }
    return 0;
}