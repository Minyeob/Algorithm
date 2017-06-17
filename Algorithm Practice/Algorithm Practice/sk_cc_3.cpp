#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
bool check[16][16];
bool visit_A[16][16];
bool visit_B[16][16];

struct people
{
	int x;
	int y;
	int time;
	char name;
};
queue<people> q;
vector<people> final_A;
vector<people> final_B;

int solution(vector<vector<int> > board, int K, int Ax, int Ay, int Bx, int By) {
	int answer = -1;
	int n = board[0].size();

	//��ź����Ȯ��
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1)
			{
				check[i][j] = true;
				//�Ʒ� ����
				for (int q = i + 1; q <= i + K; q++)
				{
					if (q >= n)
						break;
					if (board[q][j] == 2)
						break;
					check[q][j] = true;
				}

				//�� ����
				for (int q = i - 1; q >= i - K; q--)
				{
					if (q < 0)
						break;
					if (board[q][j] == 2)
						break;
					check[q][j] = true;
				}

				//������ ����
				for (int q = j + 1; q <= j + K; q++)
				{
					if (q >= n)
						break;
					if (board[i][q] == 2)
						break;
					check[i][q] = true;
				}

				//���� ����
				for (int q = j - 1; q >= j - K; q--)
				{
					if (q < 0)
						break;
					if (board[i][q] == 2)
						break;
					check[i][q] = true;
				}
			}
		}
	}

	//��ֹ��ִ°��� �� �� ����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 2)
				check[i][j] = true;
		}
	}

	//�ʱⰪ
	people A;
	A.x = Ax;
	A.y = Ay;
	A.time = 0;
	A.name = 'A';

	q.push(A);
	people B;
	B.x = Bx;
	B.y = By;
	B.time = 0;
	B.name = 'B';
	q.push(B);

	int Ax_last = n;
	int Ay_last = n;
	int A_time = 9999;
	int Bx_last = n;
	int By_last = n;
	int B_time = 9999;

	//�����Ѱ����� ���� �ּҽð�
	while (!q.empty())
	{
		people now = q.front();
		q.pop();
		//A����϶�
		if (now.name == 'A')
		{
			visit_A[now.x][now.y] = true;
			if (check[now.x][now.y] == false)
			{
				A_time = now.time;
				Ax_last = now.x;
				Ay_last = now.y;
				final_A.push_back(now);
			}

			//���� �ƴҰ�� �ٸ������� �̵�
			//�Ʒ���
			if (visit_A[now.x + 1][now.y] == false && now.x + 1 < n && board[now.x+1][now.y]!=1 && board[now.x + 1][now.y] != 2)
			{
				people temp;
				temp.x = now.x + 1;
				temp.y = now.y;
				temp.time = now.time + 1;
				temp.name = 'A';
				q.push(temp);
			}

			//����
			if (visit_A[now.x - 1][now.y] == false && now.x - 1 >= 0 && board[now.x - 1][now.y] != 1 && board[now.x - 1][now.y] != 2)
			{
				people temp;
				temp.x = now.x - 1;
				temp.y = now.y;
				temp.time = now.time + 1;
				temp.name = 'A';
				q.push(temp);
			}

			//������
			if (visit_A[now.x][now.y + 1] == false && now.y + 1 < n && board[now.x][now.y+1] != 1 && board[now.x][now.y+1] != 2)
			{
				people temp;
				temp.x = now.x;
				temp.y = now.y + 1;
				temp.time = now.time + 1;
				temp.name = 'A';
				q.push(temp);
			}

			//����
			if (visit_A[now.x][now.y - 1] == false && now.y - 1 >= 0 && board[now.x][now.y-1] != 1 && board[now.x][now.y-1] != 2)
			{
				people temp;
				temp.x = now.x;
				temp.y = now.y - 1;
				temp.time = now.time + 1;
				temp.name = 'A';
				q.push(temp);
			}
		}

		//B����϶�
		if (now.name == 'B')
		{
			visit_B[now.x][now.y] = true;
			//printf("B�϶� %d %d %d \n", now.x, now.y, now.time);
			if (check[now.x][now.y] == false)
			{
				B_time = now.time;
				Bx_last = now.x;
				By_last = now.y;
				final_B.push_back(now);
			}

			//���� �ƴҰ�� �ٸ������� �̵�
			//�Ʒ���
			if (visit_B[now.x + 1][now.y] == false && now.x + 1 < n && board[now.x + 1][now.y] != 1 && board[now.x + 1][now.y] != 2)
			{
				people temp;
				temp.x = now.x + 1;
				temp.y = now.y;
				temp.time = now.time + 1;
				temp.name = 'B';
				q.push(temp);
			}

			//����
			if (visit_B[now.x - 1][now.y] == false && now.x - 1 >= 0 && board[now.x - 1][now.y] != 1 && board[now.x - 1][now.y] != 2)
			{
				people temp;
				temp.x = now.x - 1;
				temp.y = now.y;
				temp.time = now.time + 1;
				temp.name = 'B';
				q.push(temp);
			}

			//������
			if (visit_B[now.x][now.y + 1] == false && now.y + 1 < n && board[now.x][now.y + 1] != 1 && board[now.x][now.y + 1] != 2)
			{
				people temp;
				temp.x = now.x;
				temp.y = now.y + 1;
				temp.time = now.time + 1;
				temp.name = 'B';
				q.push(temp);
			}

			//����
			if (visit_B[now.x][now.y - 1] == false && now.y - 1 >= 0 && board[now.x][now.y - 1] != 1 && board[now.x][now.y - 1] != 2)
			{
				people temp;
				temp.x = now.x;
				temp.y = now.y - 1;
				temp.time = now.time + 1;
				temp.name = 'B';
				q.push(temp);
			}
		}
	}

	//�����ִ� �ּҽð� ���ϱ�
	for (int i = 0; i < final_A.size(); i++)
	{
		people AA = final_A[i];
		for (int j = 0; j < final_B.size(); j++)
		{
			people BB = final_B[j];
			if (AA.x == BB.x && AA.y == BB.y)
				continue;
			else
			{
				int result;
				if (AA.time > BB.time)
					result = AA.time;
				else
					result = BB.time;
				if (answer==-1)
					answer = result;
				else
				{
					if(result<answer)
						answer = result;
				}
			}
		}
	}

	return answer;
}
