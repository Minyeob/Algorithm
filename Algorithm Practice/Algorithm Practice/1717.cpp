#include <cstdio>
int parent[1000005];

int find(int n)
{
	if (n == parent[n])
		return n;
	else
	{
		int y = find(parent[n]);
		parent[n] = y;
		return y;
	}
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	parent[b] = a;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0)
		{
			uni(b, c);
		}
		else if (a == 1)
		{
			int result_b = find(b);
			int result_c = find(c);
			if (result_b == result_c)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}