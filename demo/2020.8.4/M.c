#include <stdio.h>
struct robot
{
    int d;
} ro[105];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {

        int row, col, n, m;
        scanf("%d%d%d%d", &col, &row, &n, &m);
        int area[105][105] = {0};
        for (int i = 1; i <= n; i++)
        {
            int roI, roJ;
            scanf("%d%d", &roJ, &roI);
            getchar();
            scanf("%c", &ro[i].d);
            area[row - roI][roJ - 1] = i;
        }
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //         printf("%2d", area[i][j]);
        //     printf("\n");
        // }
        int idArr[105] = {0};
        char acArr[105] = {'0'};
        int repArr[105] = {0};
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &idArr[i]);
            getchar();
            scanf("%c", &acArr[i]);
            scanf("%d", &repArr[i]);
        }
        // for(int i = 0; i < m; i++)
        //     printf("%d %c %d\n",idArr[i],acArr[i],repArr[i]);
        int flag = 0;
        int r1, r2;
        for (int i = 0; i < m && flag == 0; i++)
        {
            int id = idArr[i];
            char ac = acArr[i];
            int rep = repArr[i];
            int flag1 = 1;
            for (int j = 0; j < row && flag1 == 1; j++)
                for (int k = 0; k < col && flag1 == 1; k++)
                {
                    if (area[j][k] == id)
                    {
                        flag1 = 0;
                        switch (ac)
                        {
                        case 'L':
                            while (rep--)
                            {
                                if (ro[id].d == 'N')
                                    ro[id].d = 'W';
                                else if (ro[id].d == 'W')
                                    ro[id].d = 'S';
                                else if (ro[id].d == 'S')
                                    ro[id].d = 'E';
                                else if (ro[id].d == 'E')
                                    ro[id].d = 'N';
                            }
                            break;
                        case 'R':
                            while (rep--)
                            {
                                if (ro[id].d == 'N')
                                    ro[id].d = 'E';
                                else if (ro[id].d == 'E')
                                    ro[id].d = 'S';
                                else if (ro[id].d == 'S')
                                    ro[id].d = 'W';
                                else if (ro[id].d == 'W')
                                    ro[id].d = 'N';
                            }
                            break;
                        case 'F':
                            while (rep-- && flag == 0)
                            {
                                if (ro[id].d == 'N')
                                {
                                    if (j == 0)
                                    {
                                        flag = 1;
                                        r1 = id;
                                    }
                                    else if (area[j - 1][k] != 0)
                                    {
                                        flag = 2;
                                        r1 = id;
                                        r2 = area[j - 1][k];
                                    }
                                    else
                                    {
                                        area[j - 1][k] = id;
                                        area[j][k] = 0;
                                        j--;
                                    }
                                }
                                else if (ro[id].d == 'E')
                                {
                                    if (k == col - 1)
                                    {
                                        flag = 1;
                                        r1 = id;
                                    }
                                    else if (area[j][k + 1] != 0)
                                    {
                                        flag = 2;
                                        r1 = id;
                                        r2 = area[j][k + 1];
                                    }
                                    else
                                    {
                                        area[j][k + 1] = id;
                                        area[j][k] = 0;
                                        k++;
                                    }
                                }
                                else if (ro[id].d == 'S')
                                {
                                    if (j == row - 1)
                                    {
                                        flag = 1;
                                        r1 = id;
                                    }
                                    else if (area[j + 1][k] != 0)
                                    {
                                        flag = 2;
                                        r1 = id;
                                        r2 = area[j + 1][k];
                                    }
                                    else
                                    {
                                        area[j + 1][k] = id;
                                        area[j][k] = 0;
                                        j++;
                                    }
                                }
                                else if (ro[id].d == 'W')
                                {
                                    if (k == 0)
                                    {
                                        flag = 1;
                                        r1 = id;
                                    }
                                    else if (area[j][k - 1] != 0)
                                    {
                                        flag = 2;
                                        r1 = id;
                                        r2 = area[j][k - 1];
                                    }
                                    else
                                    {
                                        area[j][k - 1] = id;
                                        area[j][k] = 0;
                                        k--;
                                    }
                                }
                            }
                            break;
                        default:
                            break;
                        }
                    }
                }
        }
        if (flag == 0)
        {
            printf("OK\n");
        }
        else if (flag == 1)
        {
            printf("Robot %d crashes into the wall\n", r1);
        }
        else
        {
            printf("Robot %d crashes into robot %d\n", r1, r2);
        }
    }
    return 0;
}