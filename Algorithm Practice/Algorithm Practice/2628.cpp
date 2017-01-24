#include <cstdio>

int row[101];
bool column[101];
int width[101];
int height[101];



int main()
{
	int x, y;
	scanf("%d %d", &x, &y);

	int n;
	scanf("%d", &n);
	int x_count=0, y_count=0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 0)
		{
			column[b] = 1;
			y_count++;
		}
		else if (a == 1)
		{
			row[b] = 1;
			x_count++;
		}
	}
	row[0] = true;
	row[x] = true;
	column[0] = true;
	column[y] = true;

	int left_x = 0 , right_x=0, x_loc=0;
	int left_y=0, right_y=0, y_loc=0;
	while (right_x != x)
	{
		for (int i = right_x; i <= x; i++)
		{
			if (row[i] == true)
			{
				left_x = i;
				break;
			}
		}
		for (int i = left_x+1; i <= x; i++)
		{
			if (row[i] == true)
			{
				right_x = i;
				break;
			}
		}
		//printf("left is %d right is %d\n", left_x, right_x);
		width[x_loc] = right_x - left_x;
		//printf("width is %d\n", width[x_loc]);
		x_loc++;
	}
	while (right_y != y)
	{
		for (int i = right_y; i <= y; i++)
		{
			if (column[i] == true)
			{
				left_y = i;
				break;
			}
		}
		for (int i = left_y+1; i <= y; i++)
		{
			if (column[i] == true)
			{
				right_y = i;
				break;
			}
		}
		//printf("left y is %d right y is %d\n", left_y, right_y);
		height[y_loc] = right_y - left_y;
		y_loc++;
	}

	int max=0;
	for (int i = 0; i < x_loc; i++)
	{
		for (int j = 0; j < y_loc; j++)
		{
			int rr = width[i];
			int tt = height[j];
			//printf("rr is %d tt is %d\n", rr, tt);
			int size = rr*tt;
			//printf("%d\n", size);
			if (size > max)
				max = size;
		}
	}
	printf("%d", max);
}