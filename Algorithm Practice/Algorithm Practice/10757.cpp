#include <cstdio>
#include <cstring>

char A[10002];
char B[10002];
int result[100000];

int main()
{	
	scanf("%s %s", A, B);
	int end = 0;
	int end1 = strlen(A);
	int end2 = strlen(B);
	if (end1 > end2)
	{
		end = end1;
		for (int i = end-1; i >= 0; i--)
		{
			B[i+end-end2] = B[i];
		}
		for (int i = 0; i < end - end2; i++)
			B[i] = '0';
	}
	else if (end2 > end1)
	{
		end = end2;
		for (int i = end-1; i >= 0; i--)
		{
			A[i+end-end1] = A[i];
		}
		for (int i = 0; i < end - end1; i++)
			A[i] = '0';
	}
	else
		end = end1;


	
	//printf("%d %d %d\n", end1,end2,end);
	for (int i = end - 1; i >= 0; i--)
	{
		int temp1 = 0;
		int temp2 = 0;
		if (A[i] != 0)
			temp1 = A[i] - 48;
		if (B[i] != 0)
			temp2 = B[i] - 48;

		if (result[i+1] + temp1 + temp2 >= 10)
		{
			result[i+1] = (result[i+1] + temp1 + temp2) % 10;
			result[i] = result[i] + 1;
		}
		else
			result[i+1] = result[i+1] + temp1 + temp2;
	}
	//printf("%s\n", A);
	//printf("%c %c\n", A[0],B[0]);
	if (result[0] != 0)
		printf("%d", result[0]);
	for (int i = 1; i <= end; i++)
	{
		printf("%d", result[i]);
	}
}