#include <stdio.h>
#include <string.h>
int main(void)
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		char text[10001];
		gets(text);
		int count = 0;
		for (int i = 0; i < strlen(text); i++)
		{
			count++;
			if (text[i] != text[i + 1])
			{
				if (count == 1)
					printf("%c", text[i]);
				else
					printf("%d%c", count, text[i]);
				count = 0;
			}
		}
		printf("\n");
	}
	return 0;
}