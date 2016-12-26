#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

char str[1000000];
stack <char> sta;
char result[400000];
int main()
{
	scanf("%s", str);
	int i = 0;
	while (str[i])
	{
		sta.push(str[i]);
		i++;
	}

	i = 0;
	int a = 0; 
	int b = 0; 
	int c = 0;
	while (!sta.empty())
	{
		a = sta.top() - 48;
		sta.pop();
		if (!sta.empty())
		{
			b = sta.top() - 48;
			b = b * 2;
			sta.pop();
			if (!sta.empty())
			{
				c = sta.top() - 48;
				c = c * 4;
				sta.pop();
			}
		}
		result[i] = (a + b + c) + 48;
		i++;
		a = 0;
		b = 0;
		c = 0;
	}
	i = 0;
	while (result[i])
	{
		sta.push(result[i]);
		i++;
	}
	i = 0;
	while (!sta.empty())
	{
		result[i] = sta.top();
		sta.pop();
		i++;
	}

	printf("%s", result);
}