#include <cstdio>
#include <algorithm>

struct meeting{
	int start;
	int end;

	bool operator < (const meeting &temp)
	{
		if (end == temp.end)
		{
			return start < temp.start;
		}
		else
			return end < temp.end;
	}
};

meeting m[100001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &m[i].start, &m[i].end);
	}
	std::sort(m, m + n);

	int count = 0;
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		if (now <= m[i].start)
		{
			now = m[i].end;
			count = count + 1;
		}
	}

	printf("%d", count);
}