#include <cstdio>
#include <cmath>
bool result[33];

int main()
{
	int TC;
	int test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int t;
			scanf("%d", &t);
			int j = 0;
			while (t > 0)
			{
				int temp = t % 2;
				if (temp == 1)
				{
					if (result[j] == 0)
						result[j] = 1;
					else
						result[j] = 0;
				}
				t = t / 2;
				j = j + 1;
			}
		}
		unsigned int final = 0;
		for (int i = 0; i < 33; i++)
		{
			if (result[i] == 1)
				final = final + pow(2, i);
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", final);
	}
}