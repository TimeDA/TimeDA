/* 2018.4.7 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int T;
double A;

// 1 <= A <= sqrt(2)
// x coord of one center is set to p, z coord is 0.
double calc_area1(double p)
{
	double p2 = sqrt(std::max(0.25 - p * p, 0.0));
	return (p + p2) * 2;
}

// sqrt(2) <= A <= sqrt(3)
// x coord of two centers is set to +-sqrt(2)/4, z coord is p.
double calc_area2(double p)
{
	double z = (2 * p + sqrt(6 - 8 * p * p)) / 6;
	double points[6][2] =
	{
		{ sqrt(0.5), z },
		{ 0, p },
		{ -sqrt(0.5), z },
		{ -sqrt(0.5), -z },
		{ 0, -p },
		{ sqrt(0.5), -z }
	};

	double result = 0;
	for (int i = 0; i < 6; i++)
	{
		result += points[i][0] * points[(i + 1) % 6][1] - points[(i + 1) % 6][0] * points[i][1];
	}
	return result / 2;
}

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%lf", &A);

		if (A <= sqrt(2))
		{
			double min = 0;
			double max = sqrt(2) / 4;

			while (min != max)
			{
				double mid = (min + max) / 2;
				if (mid == min || mid == max) break;

				if (calc_area1(mid) < A) min = mid;
				else max = mid;
			}

			double p = sqrt(std::max(0.25 - min * min, 0.0));
			printf("Case #%d:\n", c_n);
			printf("%.9f %.9f %.9f\n", min, -p, 0.0);
			printf("%.9f %.9f %.9f\n", -p, -min, 0.0);
			printf("%.9f %.9f %.9f\n", 0.0, 0.0, 0.5);
		}
		else
		{
			double min = 0.5;
			double max = sqrt(2.0 / 3.0);

			while (min != max)
			{
				double mid = (min + max) / 2;
				if (mid == min || mid == max) break;

				if (calc_area2(mid) < A) min = mid;
				else max = mid;
			}

			double z = (2 * min + sqrt(6 - 8 * min * min)) / 6;
			double y1 = sqrt(0.25 - z * z);
			double y2 = sqrt(0.75 - min * min);
			min = -min;
			printf("Case #%d:\n", c_n);
			printf("%.9f %.9f %.9f\n", -sqrt(2) / 4, (y1 + y2) / 2, (z + min) / 2);
			printf("%.9f %.9f %.9f\n", sqrt(2) / 4, (y1 + y2) / 2, (z + min) / 2);
			printf("%.9f %.9f %.9f\n", 0.0, y1, z);
		}
	}
	return -0;
}
