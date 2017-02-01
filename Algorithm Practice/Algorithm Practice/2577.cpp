#include <iostream>
using namespace std;
int cp[10];

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int number = a*b*c;
	while (number != 0)
	{
		int remain = number % 10;
		if (remain == 0)
			cp[0] = cp[0] + 1;
		else if (remain == 1)
			cp[1] = cp[1] + 1;
		else if (remain == 2)
			cp[2] = cp[2] + 1;
		else if (remain == 3)
			cp[3] = cp[3] + 1;
		else if (remain == 4)
			cp[4] = cp[4] + 1;
		else if (remain == 5)
			cp[5] = cp[5] + 1;
		else if (remain == 6)
			cp[6] = cp[6] + 1;
		else if (remain == 7)
			cp[7] = cp[7] + 1;
		else if (remain == 8)
			cp[8] = cp[8] + 1;
		else if (remain == 9)
			cp[9] = cp[9] + 1;
		number = number / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", cp[i]);
	}
}