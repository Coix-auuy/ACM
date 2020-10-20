#include<cstdio>
#include<cstdlib>
bool bo[1001][1001];
bool flag[1001][1001];
int dl[1000001][2];
int dx[5] = {0,1,0,-1,0}, dy[5] = {0,0,1,0,-1};
void bfs(int x, int y)
{
	int h = 0, t = 1;
	dl[1][0] = x; dl[1][1] = y;
	flag[x][y] = true;
	int x1 = x, y1 = y, x2 = x, y2 = y;//×óÉÏ¡¢ÓÒÏÂ 
	while(h != t)// bfs
	{
		h++;
		for(int i = 1; i <= 4; i++)
		{
			int  xx = dl[h][0] + dx[i], yy = dl[h][1] + dy[i];
			if(bo[xx][yy] && !flag[xx][yy])
			{
				if(xx < x1) x1 = xx;
				if(xx > x2) x2 = xx;
				if(yy < y1) y1 = yy;
				if(yy > y2) y2 = yy;
				flag[xx][yy] = true;
				t++;
				dl[t][0] = xx;
				dl[t][1] = yy;
			}
		}
	}
	for(int i = x1; i <= x2; i++)
		for(int j = y1; j<= y2; j++)
			if(!bo[i][j])
			{
				printf("Bad placement.");
				exit(0);
			}
}
int main()
{
	int r, c;
	scanf("%d %d", &r, &c);
	char s[1010];
	for(int i = 1; i <= r; i++)
	{
		scanf("%s", s);
		for(int j = 1; j <= c; j++)
		{
			flag[i][j] = false;
			if(s[j - 1] == '.')
				bo[i][j] = false;
			else
				bo[i][j] = true;
		}
			
	}
	int cnt = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			if(bo[i][j] && !flag[i][j])
				bfs(i, j), cnt++;
	printf("There are %d ships.", cnt);
	return 0;
}
