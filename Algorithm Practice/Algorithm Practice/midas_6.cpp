#include <cstdio>

int price[301];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &price[i]);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			int temp = price[j] + price[i - j];
			if (temp > price[i])
				price[i] = temp;
		}
	}
	printf("%d", price[n]);
}