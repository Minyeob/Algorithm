#include <cstdio>

int input[1001];
int size[1001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < n; i++)
	{
		size[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[j]<input[i] && size[j] + 1>size[i])
				size[i] = size[j] + 1;
		}
	}
}