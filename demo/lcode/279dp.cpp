#include<cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	// 得到小于等于 n 的所有完全平方数 
	int arr[1000] = {0};
	for(int i = 1; i * i <= n; i++)
		arr[i] = i * i;
	int dp[10000];
	dp[0] = {0};
	for(int i = 1; i <= n; i++)
	{
			int min = 6;
			for(int j = 1; j * j <= i; j++)
			{
				if(min > dp[i - arr[j]] + 1)
					min = dp[i - arr[j]] + 1;
			}
			dp[i] = min;
		
	}
//	for(int i = 1; i * i <= n; i++)
//		printf("%d   ",arr[i - 1]);
	printf("%d",dp[n]);
	return 0;
}
