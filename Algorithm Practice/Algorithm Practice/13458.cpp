#include <cstdio>
int room[1000001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &room[i]);
	}

	int b, c;
	scanf("%d %d", &b, &c);

	long long count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
		int now = room[i] - b;
		if (now > 0)
		{
			int check = now / c;
			count = count + check;
			if (now%c > 0)
				count++;
		}
	}
	printf("%lld", count);
}