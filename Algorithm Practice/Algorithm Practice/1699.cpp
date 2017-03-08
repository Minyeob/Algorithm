#include <cstdio>

int point[200001];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i < 320; i++)
	{
		int start = i*i;
		int end = (i + 1)*(i + 1);
		int num = i;
		bool check = false;
		for (int j = start; j < end; j++)
		{
			if (j == n+1)
			{
				end = true;
				break;
			}
			for (int k = num; k > 0; k--)
			{
				int remain = j - k*k;
				int temp = point[remain] + 1;
				if(point[j]==0)
					point[j] = point[remain] + 1;
				else
				{
					if (temp < point[j])
						point[j] = temp;
				}
			}
		}
		if (check == true)
		{
			break;
		}
	}
	printf("%d", point[n]);
}