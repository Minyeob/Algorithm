#include <cstdio>

int main()
{
	int a, b;
	while (scanf("%d %d",&a,&b)!=EOF)
	{
		int temp = a + b;
		printf("%d\n", temp);
	}
}