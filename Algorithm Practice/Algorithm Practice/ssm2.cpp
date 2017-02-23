#include <cstdio>
#include <iostream>

using namespace std;
int head[300001];
int input[300001];

int find(int loc,int size)
{
	int next = head[loc];
	if (input[next] == 0)
		return 0;
	else if (input[next] >= size)
	{
		return next;
	}
	else if (input[next] < size)
		return find(next, size);
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

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &input[i]);
		}

		for (int i = 2; i <= n; i++)
		{
			if (input[i] > input[i - 1])
			{
				head[i] = find(i - 1, input[i]);
			}
			else
				head[i] = i - 1;
			//printf("%d 's   head is %d  \n", i, head[i]);
		}

		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum = sum + head[i];
		}



		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%lld\n", sum);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}