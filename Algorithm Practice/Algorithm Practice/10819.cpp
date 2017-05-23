#include <cstdio>
#include <algorithm>
using namespace std;

int input[9];
int temp[9];

int abs(int a)
{
	if (a >= 0)
		return a;
	else
		return -a;
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	sort(input, input + n);
	int max = 0;
	int count = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			sum += abs(input[i] - input[i + 1]);
		}
		if (sum > max)
			max = sum;
	} while (next_permutation(input, input + n));	//next_permutation�� �����ϸ� first���� last���� ���� ���� ���պ��� ������������ permutation�� �����Ѵ�
	//next_permutation(start,end) ������ �ִ� ���ҵ��� �������� ū ������ ���� ���� - ������ ���·� ���纸�� ������ �ڿ� �ִ� ����� 
	//���� next_permutation���� ��� ����� ���� Ȯ���ϱ� ���ؼ��� sort�� ���� ������������ ������ �ٲ� �� �����ϸ� ��� ����� ���� Ȯ���� �� �ִ�.
	printf("%d", max);
}