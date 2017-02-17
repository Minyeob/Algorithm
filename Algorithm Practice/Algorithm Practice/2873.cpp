#include <cstdio>

int point[1001][1001];

int main()
{
	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", &point[i][j]);
		}
	}

	if (r % 2 == 1)
	{
		for (int i = 1; i < r; i++)
		{
			for (int j = 1; j < c; j++)
			{
				if (i % 2 == 1)
					printf("R");
				else
					printf("L");
			}
			printf("D");
		}
		for (int j = 1; j < c; j++)
			printf("R");
	}
	else
	{
		if (c%2==1)
		{
			for (int j = 1; j < c; j++)
			{
				for (int i = 1; i < r; i++)
				{
					if (j % 2 == 1)
						printf("D");
					else
						printf("U");
				}
				printf("R");
			}
			for (int i = 1; i < r; i++)
				printf("D");
		}
		else
		{
			int min = 1001;
			int min_x = 0;
			int min_y = 0;
			for (int i = 1; i <= r; i = i + 2)
			{
				for (int j = 2; j <= c; j = j + 2)
				{
					if (point[i][j] < min)
					{
						min = point[i][j];
						min_x = i;
						min_y = j;
					}
				}
			}
			for (int i = 2; i <= r; i = i + 2)
			{
				for (int j = 1; j <= c; j = j + 2)
				{
					if (point[i][j] < min)
					{
						min = point[i][j];
						min_x = i;
						min_y = j;
					}
				}
			}
			//printf("min x is %d  min y is %d \n", min_x, min_y);

			for (int i = 1; i < min_x - 1; i++)
			{
				for (int j = 1; j < c; j++)
				{
					if (i % 2 == 1)
						printf("R");
					else
						printf("L");
				}
				printf("D");
			}

			//최소값의 y좌표가 짝수 일때
			if (min_y % 2 == 0)
			{
				if (min_x > 1)
				{
					for (int j = 1; j < c; j++)
						printf("L");
					printf("D");
				}
				for (int j = 1; j < min_y; j++)
				{
					for (int i = 1; i < 2; i++)
					{
						if (j % 2 == 1)
							printf("D");
						else
							printf("U");
					}
					printf("R");
				}
				if (min_y < c)
				{
					printf("R");
					for (int j = min_y + 1; j < c; j++)
					{
						for (int i = 1; i < 2; i++)
						{
							if (j % 2 == 0)
								printf("D");
							else
								printf("U");
						}
						printf("R");
					}
					printf("D");
				}
				if (min_x + 1 < r)
				{
					printf("D");
					for (int j = 1; j < c; j++)
					{
						printf("L");
					}
					printf("D");
					for (int i = min_x + 2; i < r-1; i++)
					{
						for (int j = 1; j < c; j++)
						{
							if (i % 2 == 1)
								printf("R");
							else
								printf("L");
						}
						printf("D");
					}
					for (int j = 1; j < c; j++)
						printf("R");
				}
			}
			//최소값의 y좌표가 홀수 일때
			else
			{
				for (int j = 1; j < min_y; j++)
				{
					for (int i = 1; i < 2; i++)
					{
						if (j % 2 == 1)
							printf("D");
						else
							printf("U");
					}
					printf("R");
				}
				printf("R");
				if (min_y < c)
				{
					for (int j = min_y + 1; j < c; j++)
					{
						for (int i = 1; i < 2; i++)
						{
							if (j % 2 == 0)
								printf("D");
							else
								printf("U");
						}
						printf("R");
					}
					printf("D");
				}
				if (min_x + 1 < r)
				{
					printf("D");
					for (int j = 1; j < c; j++)
					{
						printf("L");
					}
					printf("D");
					for (int i = min_x + 2; i < r-1; i++)
					{
						for (int j = 1; j < c; j++)
						{
							if (i % 2 == 1)
								printf("R");
							else
								printf("L");
						}
						printf("D");
					}
					for (int j = 1; j < c; j++)
						printf("R");
				}
			}


		
		}
	}
}