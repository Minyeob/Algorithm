#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;

typedef struct profile{
	char name[11];
	int korean;
	int english;
	int math;

	//기본생성자
	profile(){}

	//복사생성자 - 복사생성자를 선언하면 기본생성자에 대한 선언도 다시 해줘야 한다.
	profile(const profile & ths)
	{
		strcpy(name, ths.name);
		korean = ths.korean;
		english = ths.english;
		math = ths.math;
	}

	// = 연산자에 대한 선언
	void operator=(const profile & ths)
	{
		strcpy(name, ths.name);
		korean = ths.korean;
		english = ths.english;
		math = ths.math;
	}
};
profile arr[100005];
profile arr2[100005];

// &을 사용하면 해당 값이 들어있는 주소까지 포함되어 해당 주소에 있는 값이 변경된다. 이걸 사용하지 않으면 그냥 해당 주소의 값만 들어가 해당 주소의 값은 바뀌지 않는다
void swap(profile& first, profile& second)
{
	profile temp;
	temp = first;
	first = second;
	second = temp;
}

bool compare(profile obj, profile pivot)
{
	if (obj.korean > pivot.korean)
		return true;

	else if (obj.korean == pivot.korean)
	{
		if (obj.english < pivot.english)
			return true;
		else if (obj.english == pivot.english)
		{
			if (obj.math > pivot.math)
				return true;
			else if (obj.math == pivot.math)
			{
				if (strcmp(obj.name, pivot.name) < 0)
					return true;
			}
		}
	}
	return false;
}

void quick(int start, int end)
{
	if (start >= end)
		return;

	profile pivot = arr[start];
	int loc=start;
	swap(arr[start], arr[end]);
	for (int i = start; i < end; i++)
	{
		if (compare(arr[i], pivot))
		{
			swap(arr[i], arr[loc]);
			loc++;
		}
	}
	swap(arr[loc], arr[end]);

	quick(start, loc - 1);
	quick(loc + 1, end);
}

void merge(int start, int end)
{
	if (start == end)
	{
		return;
	}

	int mid = (start + end) / 2;

	merge(start, mid);
	merge(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int q = 0;

	while (i <= mid && j <= end)
	{
		if (compare(arr[i],arr[j]))
		{
			arr2[q] = arr[i];
			++i;
		}

		else
		{
			arr2[q] = arr[j];
			++j;
		}
		q++;
	}

	while (i <= mid)
	{
		arr2[q] = arr[i];
		i++;
		q++;
	}

	while (j <= end)
	{
		arr2[q] = arr[j];
		j++;
		q++;
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = arr2[i - start];
	}
}


int main()
{
	int number;
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%s %d %d %d", arr[i].name, &arr[i].korean, &arr[i].english, &arr[i].math);
	}

	quick(0, number-1);

	for (int i = 0; i < number; i++)
	{
		printf("%s\n", arr[i].name);
	}

}