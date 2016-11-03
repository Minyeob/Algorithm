#include <stdio.h>

int main()
{
	int array[1001];
	float value[1001];
	float select[1001];
	int number;
	int loc;
	int sum=0;

	scanf("%d", &number);
	for (int i = 1; i <= number; i++)
	{
		scanf("%d", &array[i]);
		value[i] = (float)array[i] / i;
	}

	while (1)
	{
		float max = value[1];
		loc = 1;
		for (int i = 2; i <= number; i++)
		{
			if (max < value[i])
			{
				max = value[i];
				loc = i;
			}
		}
		value[loc] = 0;
		float remainmax = value[1];
		int remainloc = 1;

		int count = number / loc;

		for (int i = 0; i <= count; i++)
		{
			remainmax = value[1];
			remainloc = 1;
			for (int j = 1; j <= number - (i*loc); j++)
			{
				if (remainmax < value[j])
				{
					remainmax = value[j];
					remainloc = j;
				}
			}
			select[i] = array[loc] * i + remainmax*(number - (i*loc));	
		}
		remainmax = select[1];
		remainloc = 1;
		for (int i = 2; i <= number-loc; i++)
		{
			if (remainmax <= select[i])
			{
				remainmax = select[i];
				remainloc = i;
			}
		}

		count = remainloc * loc;

		sum = sum + (array[loc]*remainloc);
		number = number - count;

		if (number <= 0)
			break;
	}

	printf("%d", sum);

	return 0;
}
