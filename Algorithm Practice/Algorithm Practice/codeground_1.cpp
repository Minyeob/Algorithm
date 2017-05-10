#include <cstdio>
#include <cmath>
bool result[33];

int main()
{
	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
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

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", final);
	}
}