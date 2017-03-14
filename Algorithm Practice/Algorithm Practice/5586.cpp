#include <cstdio>
#include <cstring>

char input[10001];

int main()
{
	scanf("%s", input);
	int n = strlen(input);
	int j_length = 0;
	int i_length = 0;
	for (int i = 0; i < n; i++)
	{
		if (input[i] == 'J')
		{
			if (input[i + 1] == 'O' && input[i + 2] == 'I')
				j_length++;
		}
		if (input[i] == 'I')
		{
			if (input[i + 1] == 'O' && input[i + 2] == 'I')
				i_length++;
		}
	}
	printf("%d\n%d", j_length, i_length);
}