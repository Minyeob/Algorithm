#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int age[100005];
typedef struct{
	int age;
	char name[105];
}profile;
profile ranking[100005];
char name[100005][105];

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
		if (age[i] <= age[j])
		{
			ranking[q].age = age[i];
			strcpy(ranking[q].name, name[i]);
			++i;
		}

		else
		{
			ranking[q].age = age[j];
			strcpy(ranking[q].name, name[j]);
			++j;
		}
		q++;
	}
	
	while (i <= mid)
	{
		ranking[q].age = age[i];
		strcpy(ranking[q].name, name[i]);
		i++;
		q++;
	}

	while (j <= end)
	{
		ranking[q].age = age[j];
		strcpy(ranking[q].name, name[j]);
		j++;
		q++;
	}

	for (int i = start; i <= end; i++)
	{
		age[i] = ranking[i - start].age;
		strcpy(name[i], ranking[i - start].name);
	}
}


int main()
{
	int length;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> age[i] >> name[i];
	}
	merge(0, length - 1);
	for (int i = 0; i < length; i++)
	{
		cout << age[i] << ' '<< name[i] << endl;
	}

	return 0;
}