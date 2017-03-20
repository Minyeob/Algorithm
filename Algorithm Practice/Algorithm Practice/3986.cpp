#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
char input[100001];
stack<char> sta;

int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", input);
		//printf("input is %s \n", input);
		int len = strlen(input);
		// printf("len is %d \n ", len);
		for (int j = 0; j < len; j++)
		{
			if (sta.empty())
				sta.push(input[j]);
			else {
				if (sta.top() == input[j])
					sta.pop();
				else
					sta.push(input[j]);
			}
		}
		if (sta.empty())
			count++;
		while (!sta.empty())
			sta.pop();
		for (int j = 0; j < len; j++)
			input[j] = 0;
	}
	printf("%d", count);
}