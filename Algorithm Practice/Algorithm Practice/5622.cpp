#include <cstdio>
#include <cstring>
char input[16];

int main()
{
	scanf("%s", input);
	int n = strlen(input);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		char temp = input[i] - 'A';
		if (temp < 18)
			temp = temp / 3 + 2;
		else if (temp>= 18 && temp<25)
			temp = (temp - 1) / 3 + 2;
		else
			temp = (temp - 2) / 3 + 2;
		sum = sum + temp+1;
	}
	printf("%d", sum);
}