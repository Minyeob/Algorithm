#include <cstdio>
#include <cmath>
#include <algorithm>

bool h[11];
char point[11][11];
bool visit[11][11];
int next_x[4] = { 0,1, 1,1 };
int next_y[4] = { 1,-1, 0, 1 };

struct vertex
{
	int x;
	int y;

	inline bool operator<(const vertex& temp)
	{
		if (x < temp.x)
		{
			return true;
		}
		
		else if (x == temp.x)
		{
			if (y < temp.y)
				return true;
		}

		return false;
	}
};
vertex v[8];
int loc;

void check(int x,int y)
{
	vertex temp;
	temp.x = x;
	temp.y = y + 1;
	v[loc] = temp;
	loc = loc + 1;
}

void next_find(vertex now)
{
	int now_x = now.x;
	int next_x = now.x + 1;
	while (point[next_x][now.y] == '1')
	{
		now_x = next_x;
		next_x = now_x + 1;
	}
	vertex e;
	e.x = now_x;
	e.y = now.y;
	v[loc] = e;
	loc++;

	int now_y = now.y;
	int next_y = now.y + 1;
	while (point[now.x][next_y] == '1')
	{
		now_y = next_y;
		next_y = now_y + 1;
	}
	vertex f;
	f.x = now.x;
	f.y = now_y;
	v[loc] = f;
	loc++;
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		scanf("%s", point[i]);
	}

	//위쪽 왼쪽부터
	for (int i = 1; i < 11; i++)
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

	//위쪽 오른쪽부터
	for (int i = 1; i < 11; i++)
	{
		bool t = false;
		for (int j = 9; j >= 0; j--)
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

	//아래 왼쪽부터
	for (int i = 10; i > 0; i--)
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

	
	//아래 오른쪽부터
	for (int i = 10; i > 0; i--)
	{
		bool t = false;
		for (int j = 9; j >= 0; j--)
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

	//왼쪽 위부터
	for (int j = 0; j < 10; j++)
	{
		bool t = false;
		for (int i = 1; i <= 10; i++)
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

	//왼쪽 아래부터
	for (int j = 0; j < 10; j++)
	{
		bool t = false;
		for (int i = 10; i > 0; i--)
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

	//오른쪽 위부터
	for (int j = 9; j >= 0; j--)
	{
		bool t = false;
		for (int i = 1; i <= 10; i++)
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

	//오른쪽 아래부터
	for (int j = 9; j >= 0; j--)
	{
		bool t = false;
		for (int i = 10; i > 0; i--)
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



	/*for (int i = 0; i < 8; i++)
	{
		printf("origin %d %d\n", v[i].x, v[i].y);
	}*/
	

	loc = 0;
	for (int i = 0; i < 8; i++)
	{
		vertex now = v[i];
		bool t = false;
		for (int j = i+1; j < 8; j++)
		{
			if (now.x == v[j].x && now.y == v[j].y)
			{
				t = true;
				break;
			}
		}
		if (t == false)
		{
			v[loc] = now;
			loc++;
		}
	}

	if (loc != 3)
	{
		printf("0\n");
		return 0;
	}

	std::sort(v, v + 3);
	int height = v[2].x - v[0].x+1;
	int width;
	int w1 = abs(v[2].y - v[1].y)+1;
	int w2 = abs(v[2].y - v[0].y)+1;
	int w3 = abs(v[1].y - v[0].y)+1;
	if (w1 > w2)
		width = w1;
	else
		width = w2;
	if (w3 > width)
		width = w3;
	
	if (height >= width)
		height = height + 1;
	else
		width = width + 1;

	int count = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (point[i][j] == '1')
				count = count + 1;
		}
	}
	if (count != width*height / 2)
	{
		printf("0");
		return 0;
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

	if (min_val == 0)
	{
		printf("0\n");
		return 0;
	}

	if (mid_val == min_val)
	{
		double pivot = hypot(mid_val, min_val);
		if ((pivot-max_val)<0.00001)
		{
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