#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
int result[501][501];
using namespace std;

struct car
{
	int x;
	int y;
	//cont가 99일때 왼쪽에서 오른쪽 cont가 0일때 위에서 아래로
	int cont;

	car(int x, int y, int cont)
	{
		this->x = x;
		this->y = y;
		this->cont = cont;
	}
};
queue<car> q;
int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	
	//result 배열 초기화
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = 0;
		}
	}
	result[0][0] = 1;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("i is %d j is %d result is %d \n", i, j, result[i][j]);
			if (city_map[i][j] == 0)
			{
				result[i+1][j] += result[i][j];
				result[i][j+1] += result[i][j];

				result[i + 1][j] = result[i + 1][j] % MOD;
				result[i][j + 1] = result[i][j + 1] % MOD;
			}
			else if (city_map[i][j] == 1)
				result[i][j] = 0;
			else if (city_map[i][j] == 2)
			{
				if (i + 1 >= 0)
				{
					if (result[i - 1][j] == 0)
						result[i + 1][j] += result[i - 1][j];
					else if (result[i - 1][j] == 2)
					{
						int num = i - 2;
						while (num >= 0)
						{
							if (result[num][j] == 0)
								break;
							num--;
						}
						if (num >= 0)
							result[i + 1][j] = result[num][j];
					}
				}
				if (j - 1 >= 0)
				{
					if (result[i][j+1] == 0)
						result[i][j + 1] += result[i][j - 1];
					else if (result[i][j+1] == 2)
					{
						int num = j - 2;
						while (num >= 0)
						{
							if (result[i][num] == 0)
								break;
							num--;
						}
						if (num >= 0)
							result[i][j+1] = result[i][num];
					}
				}

				result[i + 1][j] = result[i + 1][j] % MOD;
				result[i][j + 1] = result[i][j + 1] % MOD;
			}
		}
	}

	if(m>1 || n>1)
		answer = result[m - 1][n - 1];
	return answer;
}