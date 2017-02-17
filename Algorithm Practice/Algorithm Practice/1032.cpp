#include <cstdio>

char final[51];
char temp[51];

int main()
{
	int n;
	scanf("%d", &n);

	scanf("%s", final);
	for (int i = 1; i < n; i++)
	{
		scanf("%s", temp);
		for (int i = 0; i < 51; i++)
		{
			if (final[i] != temp[i])
				final[i] = '?';
		}
	}
	printf("%s", final);
}
