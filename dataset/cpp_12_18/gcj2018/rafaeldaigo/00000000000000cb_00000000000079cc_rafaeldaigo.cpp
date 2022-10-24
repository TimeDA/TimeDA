#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main()
{
	double pi4 = acos(0)/2;
	double sq2 = sqrt(2);
	double sq22 = sqrt(2)/2;
	double casebmax = acos(1/sqrt(3));
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		double target;
		scanf("%lf\n", &target);

		printf("Case #%d:\n", t + 1);
		if (target <= sq2)
		{
			double a = 0.0;
			double b = pi4;
			for (int i = 0; i < 100; i++)
			{
				double c = (a+b)/2;
				double calc = cos(c) + sin(c);
				if (calc > target)
					b = c;
				else
					a = c;
			}
			printf("%0.9lf %0.9lf 0\n", 0.5 * cos(a), 0.5 * sin(a));
			printf("%0.9lf %0.9lf 0\n", -0.5 * sin(a), 0.5 * cos(a));
			printf("0 0 0.5\n");
		}
		else
		{
			double a = 0.0;
			double b = casebmax;
			for (int i = 0; i < 100; i++)
			{
				double c = (a+b)/2;
				double calc = sq2 * cos(c) + sin(c);
				if (calc > target)
					b = c;
				else
					a = c;
			}
			printf("%0.9lf %0.9lf %0.9lf\n", 0.5 * sq22, 0.5 * sq22 * cos(a), 0.5 * sq22 * sin(a));
			printf("%0.9lf %0.9lf %0.9lf\n", -0.5 * sq22, 0.5 * sq22 * cos(a), 0.5 * sq22 * sin(a));
			printf("0 %0.9lf %0.9lf\n", -0.5 * sin(a), 0.5 * cos(a));
		}
	}
	return 0;
}
