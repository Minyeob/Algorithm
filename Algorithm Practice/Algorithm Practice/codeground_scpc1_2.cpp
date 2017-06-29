/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cstdio>
char input[1002][1002];
bool check[1001][1001];

int goal_x;
int goal_y;

void one(int x, int y,int new_x,int new_y)
{
	//위쪽에서 들어올때
	if (x == new_x - 1 && y == new_y)
	{
		goal_x = new_x;
		goal_y = new_y - 1;
	}
	//아래쪽에서 들어올때
	if (x == new_x + 1 && y == new_y)
	{
		goal_x = new_x;
		goal_y = new_y + 1;
	}
	//왼쪽에서 들어올때
	if (x == new_x && y == new_y-1)
	{
		goal_x = new_x-1;
		goal_y = new_y;
	}
	//오른쪽에서 들어올때
	if (x == new_x && y == new_y + 1)
	{
		goal_x = new_x + 1;
		goal_y = new_y;
	}
}

void two(int x, int y, int new_x, int new_y)
{
	//위쪽에서 들어올때
	if (x == new_x - 1 && y == new_y)
	{
		goal_x = new_x;
		goal_y = new_y + 1;
	}
	//아래쪽에서 들어올때
	else if (x == new_x + 1 && y == new_y)
	{
		goal_x = new_x;
		goal_y = new_y - 1;
	}
	//왼쪽에서 들어올때
	else if (x == new_x && y == new_y - 1)
	{
		goal_x = new_x + 1;
		goal_y = new_y;
	}
	//오른쪽에서 들어올때
	else if (x == new_x && y == new_y + 1)
	{
		goal_x = new_x - 1;
		goal_y = new_y;
	}
}

void zero(int x, int y, int new_x, int new_y)
{
	//위쪽에서 들어올때
	if (x == new_x - 1 && y == new_y)
	{
		goal_x = new_x+1;
		goal_y = new_y;
	}
	//아래쪽에서 들어올때
	else if (x == new_x + 1 && y == new_y)
	{
		goal_x = new_x-1;
		goal_y = new_y;
	}
	//왼쪽에서 들어올때
	else if (x == new_x && y == new_y - 1)
	{
		goal_x = new_x;
		goal_y = new_y+1;
	}
	//오른쪽에서 들어올때
	else if (x == new_x && y == new_y + 1)
	{
		goal_x = new_x;
		goal_y = new_y-1;
	}
}

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", &input[i][1]);
		}

		int x = 1;
		int y = 0;
		pair<int, int> start;
		if (input[1][1] == '1')
		{
			one(x, y, 1, 1);
			check[1][1] = true;
		}
		else if (input[1][1] == '2')
		{
			two(x, y, 1, 1);
			check[1][1] = true;
		}
		else
		{
			zero(x, y, 1, 1);
		}
		x = 1;
		y = 1;
		while (x > 0 && y > 0 && x <= n && y <= n)
		{
			int next_x = goal_x;
			int next_y = goal_y;
			//printf("next x is %d next y is %d \n", next_x, next_y);
			if (input[next_x][next_y] == '1')
			{
				one(x, y, next_x, next_y);
				check[next_x][next_y] = true;
			}
			else if (input[next_x][next_y] == '2')
			{
				two(x, y, next_x, next_y);
				check[next_x][next_y] = true;
			}
			else
			{
				zero(x, y, next_x, next_y);
			}
			x = next_x;
			y = next_y;
		}

		//접근하게 되는 거울의 개수
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[i][j] == true)
				{
					Answer++;
					check[i][j] = false;
				}
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}