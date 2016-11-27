#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;
stack <char> sta;

char result[10000];
long int num;
int main()
{
	int i = 0;
	scanf("%ld", &num);
	int count;
	scanf("%d", &count);
	while (num > 0)
	{
		int res = num%count;
		if (res < 10)
		{
			result[i] = res + 48;
			i++;
		}
		else{
			result[i] = res + 55;
			i++;
		}
		num = num / count;
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