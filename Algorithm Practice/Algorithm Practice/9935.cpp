#include <cstdio>
#include <cstring>

char input[1000001];
char comp[37];
int length;
int comp_length;

int find(int start)
{
	printf("start is %d \n", start);
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
				count = i-comp_length;
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
	
	int count = find(0);
	while (count < 2000000)
	{
		count = find(count);
	}
	if (length == 0)
		printf("FRULA");
	else
		printf("%s", input);
}