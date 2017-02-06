#include <cstdio>

char s[21];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int r;
		scanf("%d %s", &r, s);
		for (int j = 0; j < 21; j++)
		{
			if (s[j] == '\0')
				break;
			else
			{
				for (int k = 0; k < r; k++)
					printf("%c", s[j]);
			}
		}
		printf("\n");
	}
}