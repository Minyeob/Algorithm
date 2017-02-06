#include <cstdio>
#include <cmath>

float red[2];
float blue[2];
float yellow[2];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%f %f", &red[0], &red[1]);
	scanf("%f %f", &blue[0], &blue[1]);
	scanf("%f %f", &yellow[0], &yellow[1]);

	float fold1 = 0;
	float fold2 = 0;
	float fold3 = 0;

	fold1 = (red[0] + red[1]) / 2.0;
	fold2 = (blue[0] + blue[1]) / 2.0;
	fold3 = (yellow[0] + yellow[1]) / 2.0;
	float start = 0;
	float end = n;
	float left = 0;
	float right = 0;

	//printf("fold1 is %f\n", fold1);
	if (red[0] != red[1])
	{
		left = fold1 - start;
		right = end - fold1;
		if (left > right)
		{
			end = fold1;
		}
		else
			end = end - fold1;
	}
	else
		fold1 = 0.0;
	//printf("start is %f end is %f \n", start, end);

	blue[0] = std::abs(blue[0] - fold1);
	blue[1] = std::abs(blue[1] - fold1);
	yellow[0] = std::abs(yellow[0] - fold1);
	yellow[1] = std::abs(yellow[1] - fold1);
	fold2 = (blue[0] + blue[1]) / 2.0;

	if (blue[0] != blue[1])
	{
		//printf(" blue fold2 is %f \n", fold2);
		left = fold2 - start;
		right = end - fold2;

		if (left > right)
		{
			end = fold2;
		}
		else
			end = end - fold2;
	}
	else
		fold2 = 0.0;

	yellow[0] = std::abs(yellow[0] - fold2);
	yellow[1] = std::abs(yellow[1] - fold2);
	fold3 = (yellow[0] + yellow[1]) / 2.0;
	//printf("start is %f end is %f fold3 is %f\n", start, end,fold3);

	//printf("fold3 is %f \n", fold3);

	if (yellow[0] != yellow[1])
	{
		left = fold3 - start;
		right = end - fold3;

		if (left > right)
		{
			end = fold3;
		}
		else
			end = end - fold3;
	}
	//printf("start is %f end is %f \n", start, end);

	printf("%.1f", end - start);
}