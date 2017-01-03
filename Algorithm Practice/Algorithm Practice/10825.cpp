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

	//�⺻������
	profile(){}

	//��������� - ��������ڸ� �����ϸ� �⺻�����ڿ� ���� ���� �ٽ� ����� �Ѵ�.
	profile(const profile & ths)
	{
		strcpy(name, ths.name);
		korean = ths.korean;
		english = ths.english;
		math = ths.math;
	}

	// = �����ڿ� ���� ����
	void operator=(const profile & ths)
	{
		strcpy(name, ths.name);
		korean = ths.korean;
		english = ths.english;
		math = ths.math;
	}
}profile;
profile arr[100005];

// &�� ����ϸ� �ش� ���� ����ִ� �ּұ��� ���ԵǾ� �ش� �ּҿ� �ִ� ���� ����ȴ�. �̰� ������� ������ �׳� �ش� �ּ��� ���� �� �ش� �ּ��� ���� �ٲ��� �ʴ´�
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
				char temp1[11];
				char temp2[11];
				for (int i = 0; i < 11; i++)
				{
					temp1[i] = tolower(obj.name[i]);
					temp2[i] = tolower(pivot.name[i]);
				}
				if (strcmp(temp1, temp2) < 0)
					return true;
			}
		}
	}
	else
		return false;
}

void quick(int start, int end)
{
	if (start >= end)
		return;

	profile pivot = arr[start];
	int loc=start;
	int dest=start;
	for (int i = start+1; i <= end; i++)
	{
		if (compare(arr[i], pivot))
		{
			dest = i;
			swap(arr[i], arr[loc]);
			loc++;
		}
	}
	swap(arr[loc], arr[dest]);

	quick(start, loc - 1);
	quick(loc + 1, end);
}


int main()
{
	int number;
	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%s %d %d %d", arr[i].name, &arr[i].korean, &arr[i].english, &arr[i].math);
	}

	quick(0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%s\n", arr[i].name);
	}

}