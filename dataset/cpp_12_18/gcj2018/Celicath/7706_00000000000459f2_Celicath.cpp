/* 2018.5.19 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>

int T, C;
int B[200];
int delta[200];

char line[200][200];

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d", &C);

		int ofs = 0;
		for (int i = 0; i < C; i++)
		{
			scanf("%d", B + i);
			for (int j = 0; j < B[i]; j++)
				delta[ofs++] = i;
		}
		int max = 0;
		if (B[0] == 0 || B[C - 1] == 0)
			goto hell;

		for (int i = 0; i < C; i++)
		{
			delta[i] = delta[i] - i;
			if (max < abs(delta[i]))
				max = abs(delta[i]);
		}

		for (int i = 0; i <= max; i++)
		{
			for (int j = 0; j < C; j++)
				line[i][j] = '.';
			line[i][C] = '\n';
			line[i][C+1] = '\0';
		}
		for (int i = 0; i < C; i++)
		{
			if (B[i] > 0)
			{
				for (int j = 1; i + j < C && j + delta[i + j] <= 0; j++)
					line[j][i + j] = '/';
				for (int j = 1; i - j >= 0 && j - delta[i - j] <= 0; j++)
					line[j][i - j] = '\\';
			}
		}

		printf("Case #%d: %d\n", c_n, max + 1);
		for (int i = 0; i <= max; i++)
		{
			printf(line[max - i]);
		}
		continue;
	hell:
		printf("Case #%d: IMPOSSIBLE\n", c_n);
	}
	return -0;
}
