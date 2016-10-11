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
		//endl은 cout을 통해 줄띄움을 할 때 사용 여러개 내용을 cin하거나 cout할때는 연달아서 <<, >> 등을 사용하면 된다.
		if (prime[i] == true)
			cout << i << endl;
	}
}