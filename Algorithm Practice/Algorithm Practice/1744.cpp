#include <cstdio>
#include <algorithm>

long long plus[10001];
long long minus[10001];

int main()
{
	int n;
	scanf("%d", &n);
	int plus_loc = 0;
	int minus_loc = 0;
	for (int i = 0; i < n; i++)
	{
		long long a;
		scanf("%lld", &a);
		if (a >= 0)
		{
			plus[plus_loc] = a;
			plus_loc++;
		}
		else
		{
			minus[minus_loc] = a;
			minus_loc++;
		}
	}
	plus_loc = plus_loc - 1;
	minus_loc = minus_loc - 1;

	long long sum = 0;

	for (int i = 0; i <= plus_loc; i++)
	{
		sum = sum + plus[i];
	}
	for (int i = 0; i <= minus_loc; i++)
	{
		sum = sum + minus[i];
	}

	while (plus_loc < 0)
	{

	}
}
