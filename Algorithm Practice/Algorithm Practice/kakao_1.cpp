#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
bool check[100][100];
int input[100][100];
int temp;
queue<pair<int, int>> q;
void bfs(int m,int n,int color)
{
	int next_x[4] = { 1,-1,0,0 };
	int next_y[4] = { 0,0,1,-1 };

	while (!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		int x = now.first;
		int y = now.second;
		for (int i = 0; i < 4; i++)
		{
			int nex = x + next_x[i];
			int ney = y + next_y[i];
			if (nex >= 0 && nex < m && ney >= 0 && ney < n)
			{
				if (check[nex][ney] == false && input[nex][ney] == color)
				{
					check[nex][ney] = true;
					temp++;
					q.push(make_pair(nex, ney));
				}
			}
		}
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> width;
	
	//check배열 초기화
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = false;
	}

	//picture 배열 복사
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			input[i][j] = picture[i][j];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			if (input[i][j] != 0 && check[i][j]==false)
			{
				check[i][j] = true;
				temp = 1;
				q.push(make_pair(i, j));
				bfs(m,n,input[i][j]);
				//printf("color is %d and size is %d \n", input[i][j], temp);
				width.push_back(temp);
			}
			check[i][j] = true;
		}
	}
	number_of_area = width.size();
	for (int i = 0; i < number_of_area; i++)
	{
		if (width[i] > max_size_of_one_area)
			max_size_of_one_area = width[i];
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}