#include <stdio.h>
int main()
{
	FILE *fpt;
	char s[80];
	int x = 42;

	for (int i = 0; i < 5; i++)
	{
		printf("i=%d ", i);
		fflush(stdout);

	}
	return 0;
}