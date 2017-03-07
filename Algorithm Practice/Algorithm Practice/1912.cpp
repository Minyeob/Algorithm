#include <cstdio>
#include <vector>
using namespace std;
int input[100001];
int sum[100001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}

	sum[0] = input[0];
	int cont = input[0];
	for (int i = 1; i < n; i++)
	{
		if (input[i] >= 0)
		{
			if (sum[i - 1] >= 0)
				sum[i] = sum[i - 1] + input[i];
			else
				sum[i] = input[i];
			if (cont >= 0)
				cont = cont + input[i];
			else
				cont = input[i];
		}
		else
		{
			if (sum[i - 1] < cont)
				sum[i - 1] = cont;
			sum[i] = sum[i - 1] + input[i];
			if (cont >= 0)
				cont = 0;
			else if (cont < input[i])
				cont = input[i];
		}
	}
	if (sum[n - 1] < cont)
		sum[n - 1] = cont;

	int final = sum[0];
	for (int i = 1; i < n; i++)
	{
		if (sum[i] > final)
			final = sum[i];
	}
	printf("%d", final);
}