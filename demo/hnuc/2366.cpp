#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int v[4] = {75, 90, 150, 200};
	int c[4] = {34, 50, 90, 100};
	while(scanf("%d", &n) != EOF)
	{
		int dp[100001] = {0};
		for(int i = 0; i < 4; i++)
		{
			for(int j = c[i]; j <= n; j++)
			{
				dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
			}
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
