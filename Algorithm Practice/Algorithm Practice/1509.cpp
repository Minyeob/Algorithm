#include <cstdio>
#include <cstring>
char input[2501];
int score[2501];

int main()
{
	scanf("%s", input);
	int len = strlen(input);
	score[0] = 1;
	for (int i = 0; i < 2501; i++)
		score[i] = i+1;

	for (int i = 1; i < len; i++)
	{
		score[i] = score[i - 1] + 1;
		bool check = true;
		for (int j = i-1; j >= 0; j--)
		{
			int start = j;
			int end = i;
			bool check = true;
			while (start < end)
			{
				if (input[start] != input[end])
				{
					check = false;
					break;
				}
				start = start + 1;
				end = end - 1;
			}
			if (check == true)
			{
				int count = 1;
				if (j > 0)
					count = score[j - 1] + 1;
				if (count < score[i])
					score[i] = count;
				//printf("%d score is %d\n", i, score[i]);
			}
		}
	}
	printf("%d", score[len-1]);
}