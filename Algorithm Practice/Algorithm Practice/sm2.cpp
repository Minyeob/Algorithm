#include <cstdio>

bool check[110001];

int main()
{
	check[1] = true;
	for (int i = 2; i < 320; i++)
	{
		if (check[i] == false)
		{
			for (int j = 2; i*j <= 110000; j++)
			{
				check[i*j] = true;
			}
		}
	}

	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int n;
		scanf("%d", &n);
		int special = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			if (check[temp] == false)
				special++;
		}

		int a = n;
		int b = special;
		int div = 0;
		while (b > 0)
		{
			int count = a%b;
			if (count == 0)
			{
				div = b;
				break;
			}
			a = b;
			b = count;
		}



		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);
		if (special == 0)
			printf("0\n");
		else if (n == special)
			printf("1\n");
		else
			printf("%d/%d\n", special / div, n / div);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}