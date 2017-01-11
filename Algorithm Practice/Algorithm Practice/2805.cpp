#include <cstdio>
#include <vector>
using namespace std;
vector<long long> tree;
#define max_height 2000000000;

long long find(long long min,long long max,long long goal)
{
	long long mid = (min + max) / 2;
	printf("mid is %lld\n", mid);
	printf("max is %lld\n", max);
	long long length = 0;

	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i]>mid)
		{
			length = length + (tree[i] - mid);
		}
	}
	printf("length is %lld \n", length);
	if (length > goal)
	{
		find(mid, max, goal);
	}
	else if (length == goal)
	{
		return mid;
	}
	else
	{
		find(min, mid, goal);
	}
}

long long max_find(long long min, long long max, long long goal)
{
	if (min == max)
		return min;

	long long mid = (min + max) / 2;
	long long length = 0;
	for (int i = 0; i < tree.size(); i++)
	{
		if (tree[i]>mid)
			length = length + (tree[i] - mid);
	}
	if (length == goal)
	{
		find(mid, max, goal);
	}

	else
	{
		find(min, mid, goal);
	}
}

int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		long long a;
		scanf("%lld", &a);
		tree.push_back(a);
	}

	long long min = 0;
	long long max = 2000000000LL;
	
	long long height = find(min, max, m);
	
	min = height;

	long long final_hieght = max_find(min, max, m);

	printf("%lld", final_hieght);
}