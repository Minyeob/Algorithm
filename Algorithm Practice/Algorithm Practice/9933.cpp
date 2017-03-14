#include <cstdio>
#include <cstring>

char input[101][15];
char temp[15];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", input[i]);
	}
	
	int loc = 9999;
	for (int i = 0; i < n; i++)
	{
		int len = strlen(input[i]);
		bool check = false;
		for (int j = 0; j < len; j++)
		{
			temp[j] = input[i][len - 1 - j];
		}
		for (int j = 0; j < n; j++)
		{
			if (strcmp(temp, input[j]) == 0)
			{
				loc = i;
				check = true;
				break;
			}
		}
		if (check == true)
			break;
	}
	int length = strlen(input[loc]);
	printf("%d %c", length, input[loc][length / 2]);
}