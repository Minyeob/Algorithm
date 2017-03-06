#include <cstdio>

int input[1001];
int size[1001];

int find(int start, int end)
{
	int length = 1;
	int pivot = input[start];
	for (int i = start+1; i <= end; i++)
	{
		if (pivot < input[i])
		{
			int new_length = find(i, end);
			if (length < new_length + 1)
				length = new_length + 1;
		}
	}

	return length;
}

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
		int length = 1;
		for (int j = 0; j < i; j++)
		{
			if (input[j] < input[i] && length < size[j] + 1)
			{
				length = size[j] + 1;
			}
		}
		size[i] = length;
	}

	int final = 0;
	for (int i = 0; i < n; i++)
	{
		if (size[i] > final)
			final = size[i];
	}

	printf("%d", final);

}