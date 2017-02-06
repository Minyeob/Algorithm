#include <cstdio>

char input[101];
int result[26];

int main()
{
	scanf("%s", input);

	for (int i = 0; i < 26; i++)
	{
		result[i] = -1;
	}

	for (int i = 0; i < 101; i++)
	{
		if (input[i] == '\0')
			break;
		else
		{
			int loc = input[i]-97;
			if (result[loc] == -1)
				result[loc] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", result[i]);
	}
}