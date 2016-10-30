#include <stdio.h>
char str[1000000];
char order[100];

int main()
{	
	long long int number;
	int cursor;
	int length;
	number = scanf("%s", str);
	for (int i = 0; i < 100000; i++)
	{
		if (str[i] == NULL)
		{
			cursor = i;
			length = i;
			break;
		}
	}
	scanf("%lld", &number);
	fflush(stdin);

	for (int i = 0; i < number; i++)
	{
		gets(order);
		if (order[0] == 'L')
		{
			if (cursor == 0)
				continue;
			else
				cursor--;
		}

		else if (order[0] == 'D')
		{
			if (cursor == length)
				continue;
			else
				cursor++;
		}

		else if (order[0] == 'B')
		{
			if (cursor == 0)
				continue;
			else
			{ 
				for (int i = cursor - 1; i < length - 1; i++)
				{
					str[i] = str[i + 1];
				}
				str[cursor] = NULL;
				cursor--;
				length--;
			}
		}

		else if (order[0] == 'P')
		{
			for (int i = length; i > cursor; i--)
				str[i] = str[i - 1];
			str[cursor] = order[2];
			cursor++;
			length++;
		}
		else;
	}

	printf("%s", str);
}