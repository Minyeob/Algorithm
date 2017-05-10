#include <cstdio>
#include <algorithm>
using namespace std;

int count[27];
char input[15];

int main()
{
	int l, c;
	scanf("%d %d ", &l, &c);

	for (int i = 0; i < c; i++)
	{
		scanf(" %c", &input[i]);
	}

	sort(input, input + c);
	for (int i = 0; i < c; i++)
		printf("%d  %c \n", i,input[i]);


}