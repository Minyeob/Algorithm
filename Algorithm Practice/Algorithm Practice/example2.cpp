#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int check(char input[]);

int main(){
	char string[210];
	char voca[10][20];
	memset(string, NULL, 210);
	memset(voca, NULL, 200);
	gets(string);
	int j = 0;
	int q = 0;
	int a = 0;
	int b = 0;
	
	for (int i = 0; i < 210; i++)
	{		
		if (string[i] == ' ')
		{
			j++;
			q = 0;
		}
		else if (string[i] == NULL)
			break;
		else
		{
			voca[j][q] = string[i];
			q++;
		}
	}

	for (int c = 0; c < j + 1; c++)
	{
		printf("%s\n", voca[c]);
		int result = check(voca[c]);
		if (result == 1)
			a += 1;
		else if (result == 2)
			b += 1;
		else;
	}

	printf("%d\n", a);
	printf("%d\n", b);
}

int check(char input[])
{
	int a_count = 0;
	int b_count = 0;
	for (int count=0; count < 20; count++)
	{
		if (input[count] == 'a' || input[count]=='e' || input[count]=='i' ||input[count]=='o' || input[count]=='u')
		{
			a_count += 1;
			b_count = 0;
		}
		else if (input[count] == NULL)
			return 0;
		else
		{
			a_count = 0;
			b_count += 1;
		}

		if (a_count == 2)
			return 1;
		else if (b_count == 3)
			return 2;
	}
}