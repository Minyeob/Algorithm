#include <cstdio>
int count[26];
char s[101];

int main()
{
	scanf("%s", s);

	int n = 0;
	while (s[n] != '\0')
	{
		int t = s[n] - 'a';
		count[t]++;
		n++;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%d ", count[i]);
	}
}