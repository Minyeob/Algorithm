#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
char str[1000000];
char result[1000010];
stack <char> sta;

int main()
{
	scanf("%s", str);
	if (str[0] == '0')
	{
		printf("0");
		exit(1);
	}
	int i = 0;
	int j = 0;
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
		a = sta.top()-48;
		sta.pop();
		b = a % 2;
		result[i] = b + 48;
		++i;
		a = a / 2;
		b = a % 2;
		result[i] = b + 48;
		++i;
		a = a / 2;
		result[i] = a + 48;
		++i;
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
	while (result[0] == '0')
	{
		if (result[0] == '0')
		{
			for (int j = 0; j < 1000009; j++)
				result[j] = result[j + 1];
		}
	}
	printf("%s", result);
}