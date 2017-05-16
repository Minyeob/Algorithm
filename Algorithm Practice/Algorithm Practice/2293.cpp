#include <cstdio>
#include <iostream>
using namespace std;
int num[10001];
int coin[101];

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}

	num[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j ++)
		{
			num[j]+=num[j-coin[i]];
		}
	}

	printf("%d", num[k]);
}