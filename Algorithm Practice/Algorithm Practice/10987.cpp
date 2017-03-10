#include <cstdio>
char temp[101];

int main()
{
	scanf("%s", temp);
	int length = 0;
	for (int i = 0; i < 101; i++)
	{
		if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
		{
			length++;
		}
	}
	printf("%d", length);
}