#include <cstdio>

char record[101];

int main()
{
	int n;
	scanf("%d", &n);
	for (int k = 0; k < 101; k++)
	{
		record[k] = 'W';
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", record);
		int j = 0;
		int score = 0;
		int sum = 0;
		while (record[j] != 'W')
		{
			//printf("%c", record[j]);
			if (record[j] == 'O')
			{
				score = score + 1;
				sum = sum + score;
			}
			else if (record[j] == 'X')
			{
				score = 0;
			}
			j++;
		}
		printf("%d\n", sum,j);
		for (int k = 0; k < 101; k++)
		{
			record[k] = 'W';
		}
	}
}
