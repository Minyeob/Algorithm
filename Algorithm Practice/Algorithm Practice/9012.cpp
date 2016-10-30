#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
char str[1000][50];

int main()
{
	int number = 0;
	scanf("%d", &number);
	
	for (int i = 0; i < number; i++)
	{
		scanf("%s", &str[i]);
	}
	
	for (int i = 0; i < number; i++)
	{
			stack<char> s;
			
			for (int q = 0; q < 50; q++)
			{
				if (str[i][q] == '(')
					s.push(str[i][q]);
				else if (str[i][q] == ')')
				{
					if (s.empty())
					{
						s.push(str[i][q]);
						break;
					}
					else
						s.pop();
				}
			}
			
			if (s.empty())
				printf("YES\n");
			else
			{
				printf("NO\n");
				while (!s.empty())
				s.pop();
			}
	}
}