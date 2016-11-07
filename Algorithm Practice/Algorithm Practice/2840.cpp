#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
char array[25];
char result[25];

int main()
{
	int n, m;
	cin >> n >> m;
	int count;
	char temp;
	int sum = 0;
	int last = n - 1;
	int loc = last;
	cin >> count >> temp;
	array[last] = temp;
	sum = sum + count;

	for (int i = 0; i < m-1; i++)
	{
		cin >> count >> temp;
		if (loc - count >= 0)
		{
			array[loc - count] = temp;
			loc = loc - count;
		}
		else
		{
			array[n + loc - count] = temp;
			loc = n + loc - count;
		}
		sum = sum + count;
	}

	sum = sum%n;
	printf("sum is %d\n", sum);
	for (int i = 0; i < n; i++)
	{
		if (sum + i-1 <= last)
			result[i] = array[sum + i-1];
		else
			result[i] = array[sum + i - n-1];
	}

	printf("%s", result);
}