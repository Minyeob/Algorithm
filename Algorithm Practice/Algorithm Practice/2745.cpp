#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stack>
using namespace std;
char str[1000000];
stack <char> sta;

int main(){
	scanf("%s", str);
	int count = 0;;
	scanf("%d", &count);
	int i = 0;
	while (str[i])
	{
		sta.push(str[i]);
		i++;
	}

	i = 0;

	while (!sta.empty())
	{
		str[i] = sta.top();
		sta.pop();
		i++;
	}
	i = 0;

	long int sum = 0;
	while (str[i])
	{
		if (!isalpha(str[i]))
		{
			sum = sum + (str[i] - 48)*pow(count, i);
			i++;
		}
		else
		{
			sum = sum + (str[i] - 55)*pow(count, i);
			i++;
		}
	}

	printf("%ld", sum);
}