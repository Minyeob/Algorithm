#include <stdio.h>

int fibo(int n)
{
	int save[10];
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;
	else if (n > 20)
	{
		
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
	
}

int main()
{
	int count;
	scanf("%d", &count);
	for (int i = 1; i < count + 1; i++)
	{
		int num = fibo(i);
		printf("Number is %d\n", num);
	}
}