#include <stdio.h>
typedef struct Student
{
    int r, k;
    double m;
    int p[51];//志愿列表
    int f; //录取标志，取p中下标，未录取为k+1
} stu;
typedef struct FDU
{
    int r, c;
} fdu;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        stu sArr[151];
        for(int i = 0; i < n; i++)
        {
            scanf("%d%lf%d",&sArr[i].r,&sArr[i].m,&sArr[i].k);
            for(int j = 0; j < sArr[i].k;j++)
                scanf("%d",&sArr[i].p[j]);
            sArr[i].f = -1;
        }
        fdu fArr[51];
        for(int i = 0;i<m;i++)
            scanf("%d%d",&fArr[i].r,&fArr[i].c);
        
        
    }
}