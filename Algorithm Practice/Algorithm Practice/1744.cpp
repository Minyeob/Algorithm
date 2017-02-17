#include <cstdio>
#include <algorithm>
#include <cmath>

long long plus[10001];
long long minus[10001];
long long plus_remain[10001];
long long minus_remain[10001];
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

	std::sort(plus, plus + plus_loc);
	std::sort(minus, minus + minus_loc);

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

	//printf("sum is %d\n", sum);
	long long new_sum = sum;
	long long max = pow(2, 31)-1;
	//printf("max is %d\n", max);
	int plus_remain_loc = 0;
	if (plus_loc == 0)
	{
		plus_remain[plus_remain_loc] = plus[plus_loc];
		plus_remain_loc = plus_remain_loc + 1;
	}

	while (plus_loc > 0)
	{
		long long big = plus[plus_loc];
		long long small = plus[plus_loc - 1];
		//printf("plus loc is %d big is %d small is %d\n", plus_loc, big, small);
		new_sum = sum - big - small + big*small;
		if (new_sum <= max && new_sum>sum)
		{
			sum = new_sum;
			//printf("new sum is %d\n", sum);
			plus_loc = plus_loc - 2;
			if (plus_loc == 0)
			{
				plus_remain[plus_remain_loc] = plus[plus_loc];
				plus_remain_loc = plus_remain_loc + 1;
			}
		}
		else
		{
			plus_remain[plus_remain_loc] = plus[plus_loc];
			plus_loc = plus_loc - 1;
			plus_remain_loc = plus_remain_loc + 1;
			if (plus_loc == 0)
			{
				plus_remain[plus_remain_loc] = plus[plus_loc];
				plus_remain_loc = plus_remain_loc + 1;
			}
		}
	}

	int loc = 0;
	int minus_remain_loc = 0;
	if (minus_loc == 0)
	{
		minus_remain[minus_remain_loc] = minus[loc];
		minus_remain_loc = minus_remain_loc + 1;
	}
	while (loc < minus_loc)
	{
		long long big = minus[loc];
		long long small = minus[loc+1];
		new_sum = sum - big - small + big*small;
		if (new_sum <= max && new_sum>sum)
		{
			sum = new_sum;
			loc = loc+2;
			if (loc == minus_loc)
			{
				minus_remain[minus_remain_loc] = minus[loc];
				minus_remain_loc = minus_remain_loc + 1;
			}
		}
		else
		{
			minus_remain[minus_remain_loc] = minus[loc];
			loc = loc + 1;
			minus_remain_loc = minus_remain_loc + 1;
			if (loc == minus_loc)
			{
				minus_remain[minus_remain_loc] = minus[loc];
				minus_remain_loc = minus_remain_loc + 1;
			}
		}
	}

	std::sort(plus_remain, plus_remain + plus_remain_loc);
	std::sort(minus_remain, minus_remain + minus_remain_loc);
	int small = plus_remain_loc;
	if (minus_remain_loc < plus_remain_loc)
		small = minus_remain_loc;

	for (int i = 0; i < small; i++)
	{
		new_sum = sum - plus_remain[i] - minus_remain[i] + plus_remain[i] * minus_remain[i];
		if (new_sum <= max && new_sum>sum)
		{
			sum = new_sum;
		}
	}

	printf("%lld", sum);
}
