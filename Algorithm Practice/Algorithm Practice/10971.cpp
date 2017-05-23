#include <cstdio>
#include <algorithm>
using namespace std;

int cost[11][11];
bool check[11];
int order[11];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &cost[i][j]);
	}

	for (int i = 1; i <= n; i++)
		order[i] = i;
	
	int min = 20000000;
	int count = 0;

	do{
		int sum = 0;
		int count = 0;
		check[order[1]] = true;
		int loc = order[1];
		for (int i = 1; i < n; i++)
		{
			for (int j = 2; j <= n; j++)
			{
				if (cost[loc][order[j]] != 0 && check[order[j]] == false)
				{
					count++;
					sum += cost[loc][order[j]];
					loc = order[j];
					check[order[j]] = true;
					break;
				}
			}
		}
		if (cost[loc][order[1]] != 0)
		{
			count++;
			sum += cost[loc][order[1]];
		}
		if (sum < min && count==n)
			min = sum;
		for (int i = 1; i <= n; i++)
			check[i] = false;
	} while (next_permutation(order + 1, order + n + 1));
	printf("%d", min);
}