#include <cstdio>
#include <algorithm>

char color[5];
int number[5];
char temp[5];

int main()
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", &color[i],&number[i]);
	}

	char temp = color[0];
	bool flush = true;
	for (int i = 1; i < 5; i++)
	{
		if (color[i] != temp)
		{
			flush = false;
			break;
		}
	}
	std::sort(number, number + 5);
	bool fourcard = true;
	bool straight = true;
	bool fullhouse = false;
	bool triple = false;
	bool twopair = true;
	bool onepair = true;
	
	int pivot = number[0];
	for (int i = 1; i < 5; i++)
	{
		if (number[i] != pivot + i)
		{
			straight = false;
			break;
		}
	}

	int fourcard_number = 0;
	pivot = number[1];
	for (int i = 2; i < 4; i++)
	{
		if (number[i] != pivot)
			fourcard = false;
	}

	if (pivot == number[0] && fourcard == true)
	{
		fourcard = true;
		fourcard_number = pivot;
	}
	else if (pivot == number[4] && fourcard == true)
	{
		fourcard = true;
		fourcard_number = pivot;
	}
	else
		fourcard = false;

	int full_triple = 0;
	int full_two = 0;
	if (number[0] == number[1])
	{
		if (number[1] == number[2])
		{
			if (number[3] == number[4])
			{
				fullhouse = true;
				full_triple = number[1];
				full_two = number[3];
			}
		}

		else if (number[2] == number[3])
		{
			if (number[3] == number[4])
			{
				fullhouse = true;
				full_triple = number[4];
				full_two = number[0];
			}
		}
	}

	int triple_number = 0;
	if (number[0] == number[1])
	{
		if (number[1] == number[2])
		{
			triple = true;
			triple_number = number[1];
		}
	}
	else if (number[1] == number[2])
	{
		if (number[2] == number[3])
		{
			triple = true;
			triple_number = number[2];
		}
	}
	else if (number[2] == number[3])
	{
		if (number[3] == number[4])
		{
			triple = true;
			triple_number = number[3];
		}
	}

	if (flush)
	{
		if (straight)
		{
			printf("%d", number[4] + 900);
			return 0;
		}
	}

	if (fourcard)
	{
		printf("%d", fourcard_number + 800);
		return 0;
	}

	if (fullhouse)
	{
		printf("%d", full_triple * 10 + full_two + 700);
		return 0;
	}

	if (flush)
	{
		printf("%d", number[4] + 600);
		return 0;
	}

	if (straight)
	{
		printf("%d", number[4] + 500);
		return 0;
	}

	if (triple)
	{
		printf("%d", triple_number + 400);
		return 0;
	}

	int same = 0;
	int loc[2] = {};
	int index = 0;
	for (int i = 0; i < 4; i++)
	{
		int pivot = number[i];
		int next = number[i + 1];
		if (pivot == next)
		{
			same = same + 1;
			loc[index] = pivot;
			index++;
		}
	}

	if (same == 2)
	{
		printf("%d", loc[1] * 10 + loc[0] + 300);
		return 0;
	}

	if (same == 1)
	{
		printf("%d", loc[0] + 200);
		return 0;
	}

	printf("%d", number[4] + 100);
	return 0;
}