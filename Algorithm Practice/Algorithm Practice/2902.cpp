#include <cstdio>

char s[101];
char final[101];

int main()
{
	scanf("%s", s);

	final[0] = s[0];
	int loc = 1;
	int n = 1;
	while (s[n] != '\0')
	{
		if (s[n] == '-')
		{
			final[loc] = s[n + 1];
			n = n + 2;
			loc++;
		}
		else
			n++;
	}
	printf("%s", final);
}