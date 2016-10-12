#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	char string[20];
	char voca[10][20];
	gets(string);
	for (int i = 0; i < 20; i++)
	{
		int j,q = 0;
		if (string[i] == ' ')
			j++;
		else
		{
			voca[j][q] = string[i];
			q++;
		}
	}
	printf("%s %s\n", a,b);
}

int check(char* input)
{
	if (input[0] == 'a' || 'e' || 'i' || 'o' || 'u')
	{

	}
}