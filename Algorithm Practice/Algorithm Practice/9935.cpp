#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack<char> result;
stack<char> check;
stack<char> str;

char input[1000001];
char comp[37];
int length;
int comp_length;

int find(int start)
{
	//printf("start is %d \n", start);
	int count = 2000000;
	for (int i = start; i < length; i++)
	{
		if (input[i] == comp[0])
		{
			bool check = true;
			for (int j = i + 1; j < i + comp_length; j++)
			{
				if (input[j] != comp[j - i])
				{
					check = false;
					break;
				}
			}
			if (check == true)
			{
				for (int j = i; j < length; j++)
				{
					input[j] = input[j + comp_length];
				}
				length = length - comp_length;
				count = i - comp_length;
				//printf("%s\n", input);
				break;
			}
		}
	}
	return count;
}

int main()
{
	scanf("%s", input);
	scanf("%s", comp);
	length = strlen(input);
	comp_length = strlen(comp);
	for (int i = length - 1; i >= 0; i--)
		str.push(input[i]);

	while (!str.empty())
	{
		char temp = str.top();
		str.pop();
		if (temp == comp[0])
		{
			check.push(temp);
			if (str.size() < comp_length-1)
			{
				result.push(temp);
				check.pop();
			}
			else
			{
				for (int i = 1; i < comp_length; i++)
				{
					char c = str.top();
					str.pop();
					if (c == comp[i])
						check.push(c);
					else
					{
						str.push(c);
						stack<char> t;
						while (!check.empty())
						{
							t.push(check.top());
							check.pop();
						}
						while (!t.empty())
						{
							result.push(t.top());
							t.pop();
						}
						break;
					}
				}
			}
			if (check.size() == comp_length)
			{
				while (!check.empty())
					check.pop();
				int min = result.size();
				if (min > comp_length)
					min = comp_length;
				//printf("mis is %d\n", min);
				for (int i = 0; i < min; i++)
				{
					char d = result.top();
					str.push(d);
					result.pop();
				}
			}
		}

		else
			result.push(temp);
	}

	if (result.size()==0)
		printf("FRULA");
	else
	{
		stack<char> final;
		while (!result.empty())
		{
			final.push(result.top());
			result.pop();
		}
		while (!final.empty())
		{
			printf("%c", final.top());
			final.pop();
		}
	}
}