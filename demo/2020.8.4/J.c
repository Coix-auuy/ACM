#include <stdio.h>
int main()
{
    int r, c, s;
    while (scanf("%d%d%d", &r, &c, &s) && (r || c || s))
    {

        char arr[100][11] = {'\0'};
        for (int i = 0; i < r; i++)
        {
            getchar();
            for (int j = 0; j < c; j++)
                scanf("%c", &arr[i][j]);
        }
        int did[111] = {0};
        int i = 0, j = s - 1, k = 0;
        while (1)
        {
            did[k++] = i*c + j + 1;
            switch (arr[i][j])
            {
            case 'N':
                i--;
                break;
            case 'S':
                i++;
                break;
            case 'E':
                j++;
                break;
            case 'W':
                j--;
                break;
            default:
                break;
            }
            // printf("%d\n",k);
            // for(int q = 0; q < k; q++)
            //     printf("%d ",did[q]);
            // printf("\n");
            if (i < 0 || j < 0 || i >= r || j >= c)
            {
                printf("%d step(s) to exit\n",k);
                break;
            }
            else
            {
                int flag = 0;
                for(int q = 0; q < k; q++)
                {
                    for(int p = q+1; p < k; p++)
                    {
                        if(did[q] == did[p])
                        {
                            printf("%d step(s) before a loop of %d step(s)\n",q,p - q);
                            flag = 1;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                if(flag)
                    break;    
            }
            
        }
    }
    return 0;
}