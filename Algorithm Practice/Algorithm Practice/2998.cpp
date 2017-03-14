#include <cstdio>
#include <cstring>

char input[101];
int result[101];

int main()
{
	scanf("%s", input);
	int n = strlen(input);
	int loc = n;
	for (int i = n-1; i >= 0; i=i-3)
	{
		int zero = input[i] - '0';
		int first = 0;
		if(i-1>=0)
			first = (input[i - 1] - '0') * 2;
		int second = 0;
		if(i-2>=0)
			second = (input[i-2] - '0') * 4;
		int sum = zero + first + second;
		//printf("zero is %d first is %d second is %d\n", zero, first, second);
		//printf("sum is %d\n", sum);
		result[loc] = sum;
		loc--;
	}
	
	for (int i = loc+1; i <= n; i++)
	{
		printf("%d", result[i]);
	}
}