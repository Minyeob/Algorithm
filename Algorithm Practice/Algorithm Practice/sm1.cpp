#include <cstdio>
#include <iostream>

using namespace std;

int input[201][301];
int point[201][301];
bool visit[201][301];
int n, m;

void check(int i,int j,int x,int y,int num)
{
	visit[i][j] = true;
	if (input[i - 1][j] <= input[x][y] && i - 1 > 0 &&visit[i-1][j]==false)
	{
		if (point[x][y] < num + 1)
			point[x][y] = num + 1;
		check(i - 1, j, x,y,num+1);
	}
	if (input[i + 1][j] <= input[x][y] &&  i + 1 <= n && visit[i+1][j]==false)
	{
		if (point[x][y] < num + 1)
			point[x][y] = num + 1;
		check(i + 1, j, x, y, num + 1);
	}
	if (input[i][j - 1] <= input[x][y] && j - 1 > 0 && visit[i][j-1]==false)
	{
		if (point[x][y] < num + 1)
			point[x][y] = num + 1;
		check(i, j-1, x, y, num + 1);
	}
	if (input[i][j + 1] <= input[x][y] && j + 1 <= m && visit[i][j+1]==false)
	{
		if (point[x][y] < num + 1)
			point[x][y] = num + 1;
		check(i, j+1, x, y, num + 1);
	}
	visit[i][j]=false;
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d %d", &n, &m);
		int max = 1000000001;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				scanf("%d", &input[i][j]);
		}

	
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				point[i][j] = 1;
				visit[i][j] = true;
				check(i, j, i, j, 1);
				visit[i][j] = false;

				if (point[i][j] >= (n*m + 1) / 2 && input[i][j] < max)
				{
					max = input[i][j];
				}
					
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", max);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}