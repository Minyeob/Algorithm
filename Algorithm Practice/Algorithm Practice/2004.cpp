#include <cstdio>

int main()
{
	//factorial�� ���� Ư�� ���ڷ� �� ���̳� �����ϴ��� �˱� ���ؼ��� �ش� ���ڷ� ������ �� ���������� �����鼭 ���� �� ���Ѵ�
	//���� ��� ���� ���� �ش� ���ڷ� �� ���̳� ������ �ִ��� ��Ÿ���� ���̴�.
	long long n,m;
	scanf("%lld %lld", &n,&m);
	long long max[3][2];
	long long div = 2;
	long long count = n / div;
	max[0][0] = 0;
	while (count != 0)
	{
		max[0][0] = max[0][0] + count;
		div = div * 2;
		count = n / div;
	}
	div = 5;
	count = n / div;
	max[0][1] = 0;
	while (count != 0)
	{
		max[0][1] = max[0][1] + count;
		div = div * 5;
		count = n / div;
	}
	//printf("%lld %lld \n", max[0][0], max[0][1]);

	max[1][0] = 0;
	long long num = n - m;
	div = 2;
	count = num / div;
	while (count!=0)
	{
		max[1][0] = max[1][0] + count;
		div = div * 2;
		count = num / div;
	}
	max[1][1] = 0;
	div = 5;
	count = num / div;
	while (count!=0)
	{
		max[1][1] = max[1][1] + count;
		div = div * 5;
		count = num / div;
	}
	//printf("%lld %lld \n", max[1][0], max[1][1]);
	max[2][0] = 0;
	div = 2;
	count = m / div;
	while (count != 0)
	{
		max[2][0] = max[2][0] + count;
		div = div * 2;
		count = m / div;
	}
	max[2][1] = 0;
	div = 5;
	count = m / div;
	while (count != 0)
	{
		max[2][1] = max[2][1] + count;
		div = div * 5;
		count = m / div;
	}
	long long sum2 = max[0][0] - max[1][0] - max[2][0];
	long long sum5 = max[0][1] - max[1][1] - max[2][1];
	long long min = sum2;
	if (sum2 > sum5)
		min = sum5;

	printf("%lld", min);
}