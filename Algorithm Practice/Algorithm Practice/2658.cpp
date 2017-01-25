#include <cstdio>
#include <cmath>
#include <algorithm>

char point[11][11];
int next_x[2] = { 1, 0 };
int next_y[2] = { 0, 1 };

struct vertex
{
	int x;
	int y;

	inline bool operator<(const vertex& temp)
	{
		if (x < temp.x)
		{
			if (y < temp.y)
				return true;
		}
		return false;
	}
};
vertex v[3];
int loc;

void check(int x,int y)
{
	int number = 0;
	vertex temp;
	temp.x = x;
	temp.y = y + 1;
	v[loc] = temp;
	loc = loc + 1;

	for (int i = 0; i < 2; i++)
	{
		int check_x = x + next_x[i];
		int check_y = y + next_y[i];
		if (check_x < 0 || check_x>10 || check_y < 0 || check_y>10)
			continue;
		else if (point[check_x][check_y] == '1')
		{
			if (i == 0)
			{
				int now_x = x;
				int next_x = now_x + 1;
				while (next_x == '1' && next_x<=10)
				{
					now_x = next_x;
					next_x = now_x + 1;
				}
				vertex temp;
				temp.x = now_x;
				temp.y = y + 1;
				v[loc] = temp;
				loc = loc + 1;
			}
			else if (i == 1)
			{
				int now_y = y;
				int next_y = now_y + 1;
				while (next_y == '1' && next_y < 10)
				{
					now_y = next_y;
					next_y = now_y + 1;
				}
				vertex temp;
				temp.x = x;
				temp.y = now_y + 1;
				v[loc] = temp;
				loc = loc + 1;
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		scanf("%s", point[i]);
	}

	for (int i = 1; i <= 10; i++)
	{
		bool t = false;
		for (int j = 0; j < 10; j++)
		{
			if (point[i][j] == '1')
			{
				check(i, j);
				t = true;
				break;
			}
		}
		if (t == true)
			break;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}

	double line1 = sqrt((v[0].x - v[1].x)*(v[0].x - v[1].x) + (v[0].y - v[1].y)*(v[0].y - v[1].y));
	double line2 = sqrt((v[0].x - v[2].x)*(v[0].x - v[2].x) + (v[0].y - v[2].y)*(v[0].y - v[2].y));
	double line3 = sqrt((v[2].x - v[1].x)*(v[2].x - v[1].x) + (v[2].y - v[1].y)*(v[2].y - v[1].y));
	
	double max_val = 0;
	double mid_val = 0;
	double min_val = 0;
	
	if (line1 > line2)
	{
		if (line3 > line1)
		{
			max_val = line3;
			mid_val = line1;
			min_val = line2;
		}
		else
		{
			max_val = line1;
			if (line2 > line3)
			{
				mid_val = line2;
				min_val = line3;
			}
			else
			{
				mid_val = line3;
				min_val = line2;
			}
		}
	}

	else
	{
		if (line3 > line2)
		{
			max_val = line3;
			mid_val = line2;
			min_val = line1;
		}
		else
		{
			max_val = line2;
			if (line1 > line3)
			{
				mid_val = line1;
				min_val = line3;
			}
			else
			{
				mid_val = line3;
				min_val = line1;
			}
		}
	}

	//printf("max is %lf mid is %lf min is %lf\n", max_val, mid_val, min_val);
	if (mid_val == min_val)
	{
		double pivot = hypot(mid_val, min_val);
		if (pivot == max_val)
		{
			//std::sort(v, v+3);
			for (int i = 0; i < 3; i++)
			{
				printf("%d %d\n", v[i].x, v[i].y);
			}
		}
		else
		{
			printf("0\n");
			return 0;
		}
	}
	else
		printf("0\n");

}