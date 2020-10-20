#include<cstdio>
using namespace std;
int arr[20] = {1,4,9,16,25,36,49,64,81,121,144,169};
int fun(int n)
{
	int flag = 0;
	for(int i = 0; i <13; i++ )
		if(n == arr[i])
		{
			flag = 1;
			break;
		}
	if(flag)
		return 1;
	int min = 10000;
	for(int i = 0; i < 13; i++)
	{
		if(arr[i] > n)
			break;
		int t = fun(n - arr[i]) + 1;
		if(min > t)
			min = t;
	}
	return min;
}
int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n\n",fun(n));
	}
	return 0;
}
