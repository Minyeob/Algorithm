#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char s[1000001];

int main()
{
	cin.getline(s,sizeof(s));
	int sum = 0;
	for (int i = 1; i < sizeof(s); i++)
	{
		if (s[i] == ' ' && s[i-1]!=' ')
		{
			sum++;
		}
		else if (s[i] == '\0')
		{
			if (s[i - 1] != ' ' && i-1!=0)
				sum++;
			break;
		}
	}
	cout << sum;
}