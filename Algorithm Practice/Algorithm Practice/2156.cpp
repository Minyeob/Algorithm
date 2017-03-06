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
		int first = point[i - 1];
		int second = point[i - 2] + input[i];
		int third = point[i - 3] + input[i - 1] + input[i];

		//printf("first is %d second is %d third is %d \n", first, second, third);
		int top = std::max(first, second);
		top = std::max(top, third);
		//printf("top is %d\n", top);

		point[i] = top;
		//printf("point %d is %d \n", i, point[i]);
	}
	printf("%d", point[n]);
}