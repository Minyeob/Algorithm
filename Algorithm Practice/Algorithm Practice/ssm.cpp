#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

point p[50005];
struct s {
	double size;
	int loc;

	s operator =(const s &temp)
	{
		size = temp.size;
		loc = temp.loc;

		return *this;
	}

	bool operator < (const s &temp)
	{
		return size < temp.size;
	}
};
s com[50005];

bool compare(s a, s b)
{
	return a.size < b.size;
}

bool x_compare(point a, point b)
{
	return a.x < b.x;
}

bool y_compare(point a, point b)
{
	return a.y < b.y;
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
		}

		sort(p, p + n, x_compare);
		int min_y = 50000;
		int max_y = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (min_y > p[i].y)
				min_y = p[i].y;
			if (max_y < p[i].y)
				max_y = p[i].y;
		}
		int sum1 = (p[n - 2].x - p[0].x)*(max_y - min_y);
		printf("%d %d %d %d   sum is %d \n", p[0].x, p[n - 2].x, min_y, max_y,sum1);
		for (int i = 1; i < n; i++)
		{
			if (min_y > p[i].y)
				min_y = p[i].y;
			if (max_y < p[i].y)
				max_y = p[i].y;
		}
		int sum2 = (p[n - 1].x - p[1].x)*(max_y - min_y);
		sort(p, p + n, y_compare);
		int min_x = 50000;
		int max_x = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (min_x > p[i].x)
				min_x = p[i].x;
			if (max_x < p[i].x)
				max_x = p[i].x;
		}
		int sum3 = (p[n - 2].y - p[0].y)*(max_x - min_x);
		for (int i = 1; i < n; i++)
		{
			if (min_x > p[i].x)
				min_x = p[i].x;
			if (max_x < p[i].x)
				max_x = p[i].x;
		}
		int sum4 = (p[n - 1].y - p[1].y)*(max_x - min_x);
		int final = sum1;
		if (sum2 > final)
			final = sum2;
		if (sum3 > final)
			final = sum3;
		if (sum4 > final)
			final = sum4;
		printf("%d %d %d %d \n", sum1, sum2, sum3, sum4);

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", final);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}