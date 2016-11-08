#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
char str[1000001];
int main()
{
	stack<char> sta;
	stack<char> temp;
	stack<char> result;
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (int j = 0; str[j]; j++)
		{
			if (str[j] == '<')
			{
				if (sta.empty());
				else
				{
					temp.push(sta.top());
					sta.pop();
				}
			}
			else if (str[j] == '>')
			{
				if (temp.empty());
				else
				{
					sta.push(temp.top());
					temp.pop();
				}
			}
			else if (str[j] == '-')
			{
				if (sta.empty());
				else
					sta.pop();
			}
			else if (str[j] == NULL);
			else if (str[j] == '\n');
			else
				sta.push(str[j]);
		}
		while (!temp.empty())
		{
			sta.push(temp.top());
			temp.pop();
		}
		while (!sta.empty())
		{
			result.push(sta.top());
			sta.pop();
		}
		while (!result.empty())
		{
			cout << result.top();
			result.pop();
		}
		cout << endl;
	}

	return 0;
}