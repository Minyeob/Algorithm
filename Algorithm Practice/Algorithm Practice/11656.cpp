#include <cstdio>
#include <cstring>

char input[1001];
char str[1001][1001];
int rank[1001];

int main()
{
	scanf("%s", input);
	int size = strlen(input);
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			str[i][j-i] = input[j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		char* pivot = str[i];
		int loc = 0;
		for (int j = 0; j < size; j++)
		{
			if (j == i)
				continue;
			if (strcmp(pivot, str[j])>0)
				loc++;
		}
		rank[loc] = i;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", str[rank[i]]);
	}
}