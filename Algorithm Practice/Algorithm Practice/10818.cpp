#include <cstdio>
int s[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	int min = s[0];
	int max = s[0];

	for (int i = 1; i < n; i++)
	{
		if (s[i] < min)
			min = s[i];
		if (s[i] > max)
			max = s[i];
	}

	printf("%d %d", min, max);
}