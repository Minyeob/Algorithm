#include <cstdio>
using namespace std;

typedef struct{
	int e;
	int s;
	int m;
}year;
year record[100000];

int main()
{
	int e = 0;
	int s = 0;
	int m = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (e >= 15)
			e = 1;
		else
			e++;
		if (s >= 28)
			s = 1;
		else
			s++;
		if (m >= 19)
			m = 1;
		else
			m++;

		record[i].e = e;
		record[i].s = s;
		record[i].m = m;
	}

	scanf("%d %d %d", &e, &s, &m);
	int y=0;
	for (int i = 1; i < 10000; i++)
	{
		if (e == record[i].e)
		{
			if (s == record[i].s)
			{
				if (m == record[i].m)
				{
					y = i;
					break;
				}
			}
		}
	}

	printf("%d", y);
}
