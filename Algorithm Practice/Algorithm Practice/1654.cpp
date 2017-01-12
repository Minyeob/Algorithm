#include <cstdio>
#include <math.h>
using namespace std;
long long line[10001];

long long binary_search(long long start,long long end,int k,int n)
{
	long long result=0;
	while (start <= end)
	{
		long long sum = 0;
		long long mid = (start + end) / 2;
		for (int i = 0; i < k; i++)
		{
			if (line[i]>=mid)
				sum = sum + line[i] / mid;
		}
		if (sum >= n)
			start = mid+1;
		else
			end = mid-1;
		if (sum == n)
			result = mid;
	}
	return end;
}

int main()
{
	int k, n;
	scanf("%d %d", &k, &n);

	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &line[i]);
	}

	long long max = pow(2.0, 31) - 1;
	long long length=binary_search(1, max, k, n);
	printf("%lld", length);
}