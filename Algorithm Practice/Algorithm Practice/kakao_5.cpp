#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
bool check[5000][5000];
map<pair<int, int>, int> fun;

struct point {
	int x, y;

	void operator=(const point& opposite)
	{
		x = opposite.x;
		y = opposite.y;
	}
};

point arr[5000];

bool compare(point a, point pivot)
{
	if (a.x < pivot.x)
		return true;
	else if (a.x == pivot.x)
	{
		if (a.y < pivot.y)
			return true;
	}
	return false;
}

bool compare_next(point a, point pivot)
{
	if (a.y < pivot.y)
		return true;
	else if (a.x == pivot.x)
	{
		if (a.x < pivot.x)
			return true;
	}
	return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		arr[i].x = data[i][0];
		arr[i].y = data[i][1];
		fun[make_pair(arr[i].x, arr[i].y)] = i;
	}

	//x기준 정렬
	sort(arr, arr + n, compare);
	for (int i = 0; i < n - 1; i++)
	{
		int minx = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].x == arr[j].x)
				continue;
			if (minx == 0)
				minx = arr[j].x;
			if (minx != 0 && arr[j].x > minx)
				break;
			if (arr[i].y != arr[j].y)
			{
				int start = fun[make_pair(arr[i].x, arr[i].y)];
				int end = fun[make_pair(arr[j].x, arr[j].y)];
				printf("i.x is %d i.y is %d hash is %d \n", arr[i].x, arr[i].y, start);
				printf("j.x is %d j.y is %d hash is %d \n", arr[j].x, arr[j].y, end);
				if (check[start][end] == false && start!=end)
				{
					check[start][end] = true;
					check[end][start] = true;
					answer++;
				}
			}
		}
	}

	//y기준 정렬
	sort(arr, arr + n, compare_next);
	for (int i = 0; i < n - 1; i++)
	{
		int miny = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i].y == arr[j].y)
				continue;
			if (miny == 0)
				miny = arr[j].y;
			if (miny != 0 && arr[j].y > miny)
				break;
			if (arr[i].x != arr[j].x)
			{
				int start = fun[make_pair(arr[i].x, arr[i].y)];
				int end = fun[make_pair(arr[j].x, arr[j].y)];
				printf("i.x is %d i.y is %d hash is %d \n", arr[i].x, arr[i].y, start);
				printf("j.x is %d j.y is %d hash is %d \n", arr[j].x, arr[j].y, end);
				if (check[start][end] == false && start != end)
				{
					check[start][end] = true;
					check[end][start] = true;
					answer++;
				}
			}
		}
	}
	return answer;
}