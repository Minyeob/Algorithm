#include <cstdio>
#define base 10000000;

int card_set[20000001];
int result[20000001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		int loc = a + base;
		card_set[loc] = 1;
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		int loc = a + base;
		if (card_set[loc] == 1)
			result[i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d ", result[i]);
	}
}