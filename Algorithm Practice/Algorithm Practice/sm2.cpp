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
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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



		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);
		if (special == 0)
			printf("0\n");
		else if (n == special)
			printf("1\n");
		else
			printf("%d/%d\n", special / div, n / div);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}