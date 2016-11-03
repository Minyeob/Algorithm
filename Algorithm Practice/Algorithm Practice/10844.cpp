#include <stdio.h>
#include <iostream>
using namespace std;

long long int next(int z, long long int count, int loc,int number)
{
	loc = loc + 1;
	if (loc > number)
		return count;
	int a = z + 1;
	int b = z - 1;

	if (a == 0 || a == 9)
		count = count + 1;
	else
		count = count + 2;
	if (b == 0 || b == 9)
		count = count + 1;
	else
		count = count + 2;

	next(a, count);
	next(b, count);
}

int main()
{
	int n;
	scanf("%d", &n);
	long long int count = 0;
	int loc = 1;
	for (int i = 1; i < 10; i++)
	{
		next(i, count, loc, n);
	}

	printf("%ld", count);
}