#include <cstdio>
#include <cstring>

char input[30001];
char password[30001];

int main()
{
	scanf("%[^\n]s", input);
	scanf("%s", password);

	int max = strlen(input);
	int len = strlen(password);
	int loc = 0;

	for (int i = 0; i < max; i++)
	{
		if (input[i] == ' ')
			printf(" ");
		else
		{
			int key = password[loc] - 'a' + 1;
			char temp = input[i] - key;
			if (temp < 'a')
				temp = temp + 26;
			printf("%c", temp);
		}
		loc = loc + 1;
		if (loc == len)
			loc = 0;
	}
}