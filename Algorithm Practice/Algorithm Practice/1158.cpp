#include <stdio.h>
#include <queue>

int main()
{	
	int loc=0;
	int result[5000];
	typedef struct list
	{
		int data;
		list* next;
	};

	int n, m;
	scanf("%d %d", &n, &m);
	list array[5000];
	int length = n;
	for (int i = 0; i < n; i++)
	{
		array[i].data = i + 1;
		array[i].next = &array[i + 1];
	}
	array[n - 1].next = &array[0];
	

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < m-1; j++)
		{
			if (loc >= n - 1)
				loc = 0;
			else
				loc++;
		}

		result[i] = array[loc].data;
	
		for (int i = loc; i < n-1; i++)
		{
			array[i].data = array[i + 1].data;
		}

		n--;
		
		if (loc >= n)
			loc = 0;
	}

	printf("<");
	for (int i = 0; i < length-1; i++)
	{
		printf("%d, ", result[i]);
	}
	printf("%d", result[length - 1]);
	printf(">");
}