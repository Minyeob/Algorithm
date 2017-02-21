#include <cstdio>
#include <cmath>

char a[10];
char b[10];
char big[10];
char small[10];

int main()
{
	scanf("%s %s", a, b);
	int n = 0;
	while (a[n] != '\0')
	{
		if (a[n] == '5')
		{
			big[n] = '6';
			small[n] = '5';
		}
		else if (a[n] == '6')
		{
			small[n] = '5';
			big[n] = '6';
		}
		else
		{
			big[n] = a[n];
			small[n] = a[n];
		}
		n++;
	}

	int big_sum = 0;
	int small_sum = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		big_sum = big_sum + (big[i]-'0') * pow(10, n - 1 - i);
		small_sum = small_sum + (small[i]-'0') * pow(10, n - 1 - i);
	}

	n = 0;
	while (b[n] != '\0')
	{
		if (b[n] == '5')
		{
			big[n] = '6';
			small[n] = '5';
		}
		else if (b[n] == '6')
		{
			small[n] = '5';
			big[n] = '6';
		}
		else
		{
			big[n] = b[n];
			small[n] = b[n];
		}
		n++;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		big_sum = big_sum + (big[i]-'0') * pow(10, n - 1 - i);
		small_sum = small_sum + (small[i]-'0') * pow(10, n - 1 - i);
	}

	printf("%d %d", small_sum, big_sum);


}