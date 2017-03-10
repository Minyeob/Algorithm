#include <cstdio>
char temp[1001];

int main()
{
	scanf("%s", temp);
	int i = 0;
	while (temp[i] != 0)
	{
		char c = temp[i];
		char change = c - 3;
		if (change < 65)
		{
			change = change + 26;
		}
		printf("%c", change);
		i++;
	}
}