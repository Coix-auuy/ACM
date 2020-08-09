#include <stdio.h>
#include <math.h>
#include<stdlib.h>
typedef struct pixel
{
    int addr;                 //位置
    int v;                    //值
} Pixel;             
Pixel pix[10005]; //最多只有1000个连续的段
int arr[1005][2];             //arr[][0]--v,arr[][1]--num
int width;                    //图列数
int segCount, pCount; //连续段段数，总点数
int getV(int addr)            //求addr处的像素值
{
    int a = 0, i = 0;
    while (a < addr)
        a += arr[i++][1];
    return arr[i - 1][0];
}
int getNewV(int addr) //求addr处新值
{
    int v = getV(addr), res = 0;
    int row = (addr - 1) / width; //行
    int col = (addr - 1) % width; //列
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            int tAddr = i * width + j;
            if (i < 0 || j >= width || j < 0 || tAddr == addr - 1 || tAddr >= pCount)
                continue;
            int temp = getV(tAddr + 1);
            if (res < abs(temp - v))
                res = abs(temp - v);
        }
    }
    return res;
}
int cmp(const void *x,const void *y)
{
    return ((Pixel*)x)->addr - ((Pixel*)y)->addr;
}
int main()
{

    while (scanf("%d", &width) && width != 0)
    {
        
        int v, num; //像素值，连续个数
        segCount = pCount = 0;
        while (scanf("%d%d", &v, &num)&& (num > 0))
        {
            arr[segCount][0] = v;
            arr[segCount++][1] = num;
            pCount += num;
        }
        printf("%d\n", width);
        int addr = 1, k = 0;
        for (int f = 0; f <= segCount; f++)
        {
            int row = (addr - 1) / width; //行
            int col = (addr - 1) % width; //列
            //接下来考虑该段起始点周围每一个点
            for (int i = row - 1; i <= row + 1; i++)
            {
                for (int j = col - 1; j <= col + 1; j++)
                {
                    int tAddr = i * width + j;//此addr是从0算起的
                    if (i < 0 || j < 0 || j >= width || tAddr >= pCount) //越界
                        continue;
                    pix[k].addr = tAddr + 1;
                    pix[k++].v = getNewV(tAddr + 1);
                }
            }
            addr += arr[f][1]; //继续下一段
        }
        qsort(pix,k,sizeof(pix[0]),cmp); //按位置排序
        pix[k+1] = pix[0];
        for(int i = 0 ; i < k;i++)
        {
            if(pix[i].v == pix[k+1].v)
                continue;
            printf("%d %d\n",pix[k+1].v,pix[i].addr - pix[k+1].addr);
            pix[k+1] = pix[i];
        }
        printf("%d %d\n",pix[k+1].v,pCount-pix[k+1].addr + 1);
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}