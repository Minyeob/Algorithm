#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

typedef struct {
	char name[11];
	int korean;
	int english;
	int math;
} profile;
profile arr[100005];
int result[100005];

void swap(int first, int second)
{
	/*
	profile temp;
	strcpy(temp.name, arr[first].name);
	temp.korean = arr[first].korean;
	temp.english = arr[first].english;
	temp.math = arr[first].math;

	strcpy(arr[first].name, arr[second].name);
	arr[first].korean = arr[second].korean;
	arr[first].english = arr[second].english;
	arr[first].math = arr[second].math;

	strcpy(arr[second].name, temp.name);
	arr[second].korean = temp.korean;
	arr[second].english = temp.english;
	arr[second].math = temp.math;
	*/
	int temp;
	temp = result[first];
	result[first] = result[second];
	result[second] = temp;
}

void quick_korean(int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[result[start]].korean;
	int loc=start;
	int dest=start;
	for (int i = start+1; i <= end; i++)
	{
		if (arr[result[i]].korean > pivot)
		{
			dest = i;
			swap(i, loc);
			loc++;
		}
	}
	swap(loc, dest);

	quick_korean(start, loc - 1);
	quick_korean(loc + 1, end);
}

void quick_english(int start, int end)
{
	if (start >= end)
		return;

	int pivot_english = arr[result[start]].english;
	int loc = start;
	int dest = start;

	for (int i = start + 1; i <= end; i++)
	{
		if (arr[result[i]].english < pivot_english)
		{
			dest = i;
			swap(i, loc);
			loc++;
		}
	}
	swap(loc, dest);

	quick_english(start, loc - 1);
	quick_english(loc + 1, end);
}

void quick_math(int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[result[start]].math;
	int loc = start;
	int dest = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[result[i]].math > pivot)
		{
			dest = i;
			swap(i, loc);
			loc++;
		}
	}
	swap(loc, dest);

	quick_math(start, loc - 1);
	quick_math(loc + 1, end);
}

void quick_name(int start, int end)
{
	if (start >= end)
		return;

	int pivot = arr[result[start]].name[0];
	if (pivot > 96)
		pivot = pivot - 32;
	int loc = start;
	int dest = start;

	for (int i = start + 1; i <= end; i++)
	{
		int name = arr[result[i]].name[0];
		if (name > 96)
			name = name - 32;
		if (name < pivot)
		{
			dest = i;
			swap(i, loc);
			loc++;
		}
	}
	swap(loc, dest);

	quick_name(start, loc - 1);
	quick_name(loc + 1, end);
}

int main()
{
	int number;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		result[i] = i;
	}

	
	for (int i = 0; i < number; i++)
	{
		scanf("%s %d %d %d", arr[i].name, &arr[i].korean, &arr[i].english, &arr[i].math);
	}

	quick_korean(0, number-1);
	for (int i = 0; i < number; i++)
	{
		if (arr[result[i]].korean != arr[result[i+1]].korean)
			printf("%s\n", arr[result[i]].name);
		else
		{
			int end = i;
			for (int j = i + 1; j < number; j++)
			{
				if (arr[result[j]].korean != arr[result[i]].korean)
				{
					end = j - 1;
					break;
				}
			}
			quick_english(i, end);

			if (arr[result[i]].english != arr[result[i+1]].english)
				printf("%s\n", arr[result[i]].name);
			else
			{
				int end = i;
				for (int j = i + 1; j < number; j++)
				{
					if (arr[result[j]].english != arr[result[i]].english)
					{
						end = j - 1;
						break;
					}
				}
				quick_math(i, end);

				if (arr[result[i]].math != arr[result[i+1]].math)
					printf("%s\n", arr[result[i]].name);
				else
				{
					int end = i;
					for (int j = i + 1; j < number; j++)
					{
						if (arr[result[j]].math != arr[result[i]].math)
						{
							end = j - 1;
							break;
						}
					}
					quick_name(i, end);

					printf("%s\n", arr[result[i]].name);
				}
			}
		}
	}

}