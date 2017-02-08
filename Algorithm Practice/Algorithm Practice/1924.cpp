#include <cstdio>

int main()
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int x, y;
	scanf("%d %d", &x, &y);
	int sum = 0;
	for (int i = 0; i < x - 1; i++)
	{
		sum = sum + month[i];
	}
	sum = sum + y;
	int div = sum % 7;
	if (div == 1)
		printf("MON");
	else if (div == 2)
		printf("TUE");
	else if (div == 3)
		printf("WED");
	else if (div == 4)
		printf("THU");
	else if (div == 5)
		printf("FRI");
	else if (div == 6)
		printf("SAT");
	else if (div == 0)
		printf("SUN");
}