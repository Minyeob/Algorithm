#include <cstdio>

char s[101];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int a = s[i] - 48;
		sum = sum + a;
	}
	printf("%d", sum);
}