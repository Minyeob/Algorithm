#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char input[100001];
stack<char> sta;

int main()
{
	int sum = 0;
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++)
	{
		if (input[i] == '(')
		{
			sta.push(input[i]);
		}
		else if (input[i] == ')')
		{
			sta.pop();
			if (input[i - 1] == '(')
				sum += sta.size();
			else
				sum += 1;
		}
		else
			break;
		//printf("i is %d size is %d sum is %d\n", i, sta.size(),sum);
	}
	printf("%d", sum);
}
