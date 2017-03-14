#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
stack<int> sta;

int main()
{
	int n;
	scanf("%d", &n);
	char temp[6];

	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		if (strcmp(temp,"push")==0)
		{
			int d;
			scanf("%d", &d);
			sta.push(d);
		}
		else if (strcmp(temp, "pop") == 0)
		{
			if (sta.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", sta.top());
				sta.pop();
			}
		}
		else if (strcmp(temp, "size") == 0)
			printf("%d\n", sta.size());
		else if (strcmp(temp, "empty") == 0)
		{
			if (sta.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(temp, "top") == 0)
		{
			if (sta.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", sta.top());
			}
		}
	}
	while (!sta.empty())
		sta.pop();
}