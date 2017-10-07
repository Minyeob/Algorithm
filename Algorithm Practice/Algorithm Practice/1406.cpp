#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
stack<char> left;
stack<char> right;
char input[1000000];
char temp[10];

int main()
{
	scanf("%s", input);
	int len = strlen(input);
	for (int i = 0; i < len; i++)
	{
		left.push(input[i]);
	}
	int n;
	scanf("%d", &n);
	//printf("n is %d \n", n);
	fgets(temp, sizeof(temp),stdin);

	for (int j = 0; j < n; j++)
	{
		fgets(temp, sizeof(temp), stdin);
		//printf("temp is %s \n", temp);
		
		//수정문자가 L일때
		if (temp[0] == 'L')
		{
			if (!left.empty())
			{
				char x = left.top();
				left.pop();
				right.push(x);
			}
		}

		//수정문자가 R일때
		if (temp[0] == 'D')
		{
			if (!right.empty())
			{
				char x = right.top();
				right.pop();
				left.push(x);
			}
		}

		//수정문자가 B일때
		if (temp[0] == 'B')
		{
			if (!left.empty())
			{
				left.pop();
			}
		}

		//수정문자가 P일때
		if (temp[0] == 'P')
		{
			left.push(temp[2]);
		}
	}

	stack<char> final;
	while (!left.empty())
	{
		char x = left.top();
		left.pop();
		final.push(x);
	}

	while (!final.empty())
	{
		char x = final.top();
		final.pop();
		printf("%c", x);
	}

	while (!right.empty())
	{
		char x = right.top();
		right.pop();
		printf("%c", x);
	}
}