#include <cstdio>

char s[105];

int main()
{
	scanf("%s", s);
	int loc = 0;
	for (int i = 0; i < 101; i++)
	{
		if (s[i] == '\0')
		{
			loc = i;
			break;
		}
	}
	printf("loc is %d\n", loc);

	int start = 0;
	while (start < loc)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("%c", s[i]);
			//printf("start+i is %d\n", start + i);
			if (start + i == loc - 1)
				break;
		}
		printf("\n");
		for (int i = 0; i < loc; i++)
		{
			s[i] = s[i + 10];
		}
		start = start + 10;
	}
}