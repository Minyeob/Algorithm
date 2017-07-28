#include <cstdio>
#include <map>
using namespace std;
int num[100];
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int loc = 0;
	while (a >= b)
	{
		num[loc] = a%b;
		a = a / b;
		loc++;
	}
	num[loc] = a%b;

	for (int i = loc; i >= 0; i--)
		printf("%d", num[i]);
}