#include <cstdio>

long long p[101];

int main()
{
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	for (int i = 4; i < 101; i++)
	{
		p[i] = p[i - 3] + p[i - 2];
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		printf("%lld\n", p[t]);
	}
}