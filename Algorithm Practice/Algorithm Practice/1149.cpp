#include <cstdio>
#include <algorithm>
using namespace std;

int color[3];
int result[1001][3];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &color[j]);

		if (i == 0)
		{
			result[0][0] = color[0];
			result[0][1] = color[1];
			result[0][2] = color[2];
		}

		else
		{
			result[i][0] = min(result[i - 1][1] + color[0], result[i - 1][2] + color[0]);
			result[i][1] = min(result[i - 1][0] + color[1], result[i - 1][2] + color[1]);
			result[i][2] = min(result[i - 1][0] + color[2], result[i - 1][1] + color[2]);
		}
	}
	
	int final = min(result[n - 1][0], result[n - 1][1]);
	int final2 = min(final, result[n - 1][2]);

	printf("%d", final2);
}