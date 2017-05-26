#include <cstdio>

int count[10001];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if(temp<10001)
			count[temp] += 1;
		for (int j = temp + 1; j < 10001; j++)
			count[j] += count[j - temp];
	}
	printf("%d", count[k]);
}