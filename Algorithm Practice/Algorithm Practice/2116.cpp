#include <cstdio>

int sample[10001][6];
int maxsum;

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d %d", &sample[i][0], &sample[i][1], &sample[i][2], &sample[i][3], &sample[i][4], &sample[i][5]);
	}


	for (int i = 0; i < 6; i++)
	{	
		int bottom = 0;
		int top = 0;
		int sum = 0;
		int max = 0;

		bottom = sample[0][i];
		if (i == 0)
			top = sample[0][5];
		if (i == 1)
			top = sample[0][3];
		if (i == 2)
			top = sample[0][4];
		if (i == 3)
			top = sample[0][1];
		if (i == 4)
			top = sample[0][2];
		if (i == 5)
			top = sample[0][0];

		for (int t = 0; t < 6; t++)
		{
			if (sample[0][t] != bottom && sample[0][t] != top)
			{
				if (sample[0][t]>max)
					max = sample[0][t];
			}
		}
		sum = sum + max;
		//printf("sum is %d\n", sum);

		for (int z = 1; z < n; z++)
		{
			//printf("z is %d n is %d\n", z, n);
			max = 0;
			for (int j = 0; j < 6; j++)
			{
				if (sample[z][j] == top)
				{
					bottom = sample[z][j];
					if (j == 0)
						top = sample[z][5];
					if (j == 1)
						top = sample[z][3];
					if (j == 2)
						top = sample[z][4];
					if (j == 3)
						top = sample[z][1];
					if (j == 4)
						top = sample[z][2];
					if (j == 5)
						top = sample[z][0];

					for (int k = 0; k < 6; k++)
					{
						if (sample[z][k] != bottom && sample[z][k] != top)
						{
							if (sample[z][k]>max)
								max = sample[z][k];
						}
					}
					sum = sum + max;
					//printf("sum is %d\n", sum);
					break;
				}
			}
		}
		if (sum > maxsum)
			maxsum = sum;
	}
	printf("%d", maxsum);

}