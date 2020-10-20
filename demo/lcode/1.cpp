#include<cstdio>
using namespace std;
int rev(int x)
{
	int res = 0;
	while(x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}
int main()
{
	for (int i = 1; i < 10; i+=2)
	{
		int r1 = i;
		printf("%d\n", r1);
		int r2 = i * 10 + i;
		printf("%d\n", r2);
	}
	for (int i = 10; i < 100; i++)
	{
		int r = i * 100 + rev(i);
		printf("%d\n", r);
	}
	for (int i = 100; i < 1000; i++)
	{
		int r = i * 100 + rev(i / 10);
		printf("%d\n", r);
	}
	for (int i = 1000; i < 10000; i++)
	{
		int r = i * 1000 + rev(i / 10);
		printf("%d\n", r);
	}
	for (int i = 10000; i < 100000; i++)
	{
		int r = i * 10000 + rev(i / 10);
		printf("%d\n", r);
	}
}

