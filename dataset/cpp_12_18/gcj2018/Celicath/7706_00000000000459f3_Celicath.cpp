/* 2018.5.19 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>

int T, R, B;

const int Rmax = 500;
const int Bmax = 500;
const int amax = 32;
const int bmax = 32;
int dp[Rmax+1][Bmax+1][amax*bmax+1];

int main()
{
	for (int a = 0; a <= amax*bmax; a++)
		dp[0][0][a] = 0;

	for (int i = 0; i <= Rmax; i++)
		for (int j = 0; j <= Bmax; j++)
			dp[i][j][0] = 0;

	for (int i = 0; i <= Rmax; i++)
	{
		for (int j = 0; j <= Bmax; j++)
		{
			for (int t = 1; t <= amax * bmax; t++)
			{
				int a = t / bmax;
				int b = t % bmax;
				dp[i][j][t] = dp[i][j][t - 1];
				if (i >= a && j >= b)
				{
					dp[i][j][t] = std::max(dp[i - a][j - b][t - 1] + 1, dp[i][j][t]);
				}
			}
		}
	}
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d%d", &R, &B);

		printf("Case #%d: %d\n", c_n, dp[R][B][amax*bmax]);
	}
	return -0;
}
