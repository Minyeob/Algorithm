#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int input[100001];
map<int, int>check;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
		check[input[i]] = 1;
	}
	sort(input, input + n);
	int min = 100000000;
	for (int i = 0; i < n - 1; i++)
	{
		int temp = input[i + 1] - input[i];
		if (temp < min)
			min = temp;
	}

	int result = 0;
	while (min > 0)
	{
		printf("min is %d\n", min);
		int start = input[0];
		int end = input[n - 1];
		int exist = 0;
		int none = 0;
		while (start <= end)
		{
			if (check[start])
				exist++;
			else
				none++;
			start = start + min;
		}
		if (exist == n)
		{
			result = none;
			break;
		}
		else
			min--;
	}
	printf("%d", result);

	return 0;
}