#include <cstdio>
#include <algorithm>

int input[100001];
int max[100001];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}
	std::sort(input, input + n);
	int min = input[n - 1];
	max[n - 1] = input[n - 1];
	int count = 0;
	if (min != 0)
		count = 1;

	for (int i = n - 2; i >= 0; i--)
	{
		if (min>=input[i])
		{
			if (input[i] * (count + 1) >= max[i + 1])
			{
				max[i] = input[i] * (count + 1);
				min = input[i];
				count = count + 1;
			}
			else
				max[i] = max[i + 1];
		}
		else
		{
			max[i] = min*(count + 1);
			count = count + 1;
		}
	}
	printf("%d", max[0]);
	//printf("min is %d  max is %d   count is %d", min,max[0],count);
}