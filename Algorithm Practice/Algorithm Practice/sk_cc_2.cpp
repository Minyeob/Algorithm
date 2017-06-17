#include <vector>
using namespace std;
bool check[501][501];
pair<int,int> mapping[250001];

int solution(vector<vector<int>> board, vector<int> nums) {
	int answer = 0;
	int n = board[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mapping[board[i][j]] = make_pair(i, j);
		}
	}
	for (int i = 0; i < nums.size(); i++)
	{
		int temp = nums[i];
		int x = mapping[temp].first;
		int y = mapping[temp].second;
		check[x][y] = true;
	}
	for (int i = 0; i < n; i++)
	{
		bool bingo = true;
		for (int j = 0; j < n; j++)
		{
			if (check[i][j] == false)
			{
				bingo = false;
				break;
			}
		}
		if (bingo == true)
			answer++;
	}

	for (int i = 0; i < n; i++)
	{
		bool bingo = true;
		for (int j = 0; j < n; j++)
		{
			if (check[j][i] == false)
			{
				bingo = false;
				break;
			}
		}
		if (bingo == true)
			answer++;
	}

	bool bingo = true;
	for (int i = 0; i < n; i++)
	{
		if (check[i][i] == false)
		{
			bingo = false;
			break;
		}
	}
	if (bingo == true)
		answer++;

	bool bingo = true;
	for (int i = 0; i < n; i++)
	{
		if (check[i][n-1-i] == false)
		{
			bingo = false;
			break;
		}
	}
	if (bingo == true)
		answer++;
	return answer;
}

int main()
{
	vector<vector<int>> board;
	board.resize(5);
	board[0].push_back(1);
	board[0].push_back(1);
	board[0].push_back(1);

	board[1].push_back(1);
	board[1].push_back(1);
	board[1].push_back(1);

	board[2].push_back(1);
	board[2].push_back(1);
	board[2].push_back(1);
	
	vector<int> nums;
	aaa.push_back(1);
	int a = solution(board, aaa);
}