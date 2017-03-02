#include <cstdio>
#include <cmath>
#include <algorithm>

int input[10001];
int point[10001];
int length[10001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]);
	}

	point[1] = input[1];
	point[2] = input[1] + input[2];
	length[1] = 1;
	length[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		int first = point[i - 3] + input[i - 2] + input[i - 1];
		if (length[i - 3] > 0)
			first = first - point[i - 3] + point[i - 4];
		int second = point[i - 3] + input[i - 2] + input[i];
		if (length[i - 3] > 1)
		{
			int min = input[i - 4];
			if (min > input[i - 3])
				min = input[i - 3];
			second = second - min;
		}
		int third = point[i - 3] + input[i - 1] + input[i];
		
		//printf("first is %d second is %d third is %d \n", first, second, third);
		int top = std::max(first, second);
		top = std::max(top, third);
		//printf("top is %d\n", top);
		
		if (top == first)
		{
			point[i] = first;
			length[i] = 0;
		}
		else if (top == second)
		{
			point[i] = second;
			length[i] = 1;
		}
		else if (top == third)
		{
			point[i] = third;
			length[i] = 2;
		}
		//printf("point %d is %d \n", i, point[i]);
	}
	printf("%d", point[n]);
}