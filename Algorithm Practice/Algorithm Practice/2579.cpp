#include <cstdio>
#include <algorithm>
using namespace std;
int input[305];
int point[305];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &input[i]);
	}
	
	input[n] = input[n] + 30000;
	point[1] = input[1];
	point[2] = input[1] + input[2];


	for (int i = 3; i <= n; i++)
	{
		int first = point[i - 2] + input[i];
		int second = point[i - 3] + input[i - 1] + input[i];

		int top = max(first, second);

		point[i] = point[i]+top;
	}
	point[n] = point[n] - 30000;	
	printf("%d", point[n]);
}