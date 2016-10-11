#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

bool prime[1000001];
#define max 1000001

int main(){
	int a, b, sum;
	cin >> a >> b;

	memset(prime,true,max);
	prime[0] = false;
	prime[1] = false;
	
	for (int i = 2; i < 1001; i++)
	{
		if (prime[i])
		{
			for (int j = i*i; j < max; j = j + i)
			{
				if (j%i == 0)
				{
					prime[j] = false;
				}
			}
		}
	}

	for (int i = a; i < b + 1; i++)
	{
		//endl�� cout�� ���� �ٶ���� �� �� ��� ������ ������ cin�ϰų� cout�Ҷ��� ���޾Ƽ� <<, >> ���� ����ϸ� �ȴ�.
		if (prime[i] == true)
			cout << i << endl;
	}
}