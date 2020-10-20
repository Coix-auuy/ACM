#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool sushu(int x)
{
	int i;
	for(i = 2; i <= sqrt(x); i++)
		if(x % i == 0)
			return false;
	return true;
}
int arr[10000];
int cnt = 0;
void huiwen()
{
	for(int i = 1; i <= 9; i += 2)
	{
		if(sushu(i * 10 + i))	
			arr[cnt++] = i * 10 + i;
		if(i != 5)
			for(int j = 0; j <= 9; j++)
			{
				if(sushu(i * 100 + j * 10 + i)) 	
					arr[cnt++] = i * 100 + j * 10 + i;
				for(int k = 0; k<= 9; k++)
				{
					if(sushu(i * 10000 + j * 1000 +  k * 100 + j * 10 + i))
						arr[cnt++] = i * 10000 + j * 1000  + k * 100 + j * 10 + i;
					for(int l = 0; l <= 9; l++)
						if(sushu(i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i))
							arr[cnt++] = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
				}
					
			}
	}
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	huiwen();
	arr[cnt++] = 5, arr[cnt++] = 7;
	sort(arr,arr + cnt);
	for(int i = 0; i <= cnt; i++)
	{
		if(arr[i] >= m && arr[i] <= n)
			printf("%d\n", arr[i]);
	}
	return 0;
}
