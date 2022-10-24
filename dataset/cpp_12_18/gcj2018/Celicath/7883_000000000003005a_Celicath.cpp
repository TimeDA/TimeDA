/* 2018.4.14 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int T, R, C, H, V;
char lines[200][200];

int rowsums[200];
int colsums[200];

int rowcuts[200];
int colcuts[200];

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d%d%d%d", &R, &C, &H, &V);

		for (int i = 0; i < R; i++)
			scanf("%s", lines[i]);

		int totsum = 0;
		for (int i = 0; i < R; i++)
		{
			rowsums[i] = 0;
			for (int j = 0; j < C; j++)
				rowsums[i] += (lines[i][j] == '@');
			totsum += rowsums[i];
		}
		for (int i = 0; i < C; i++)
		{
			colsums[i] = 0;
			for (int j = 0; j < R; j++)
				colsums[i] += (lines[j][i] == '@');
		}
		int cur, pos, num, each;

		if (totsum % ((H + 1) * (V + 1)))
			goto hell;

		each = totsum / ((H + 1) * (V + 1));

		cur = 0;
		pos = 0;
		for (int i = 0; i < R; i++)
		{
			cur += rowsums[i];
			if (cur > each * (V + 1)) goto hell;
			else if (cur == each * (V + 1))
			{
				cur = 0;
				rowcuts[pos++] = i;
			}
		}
		cur = 0;
		pos = 0;
		for (int i = 0; i < C; i++)
		{
			cur += colsums[i];
			if (cur > each * (H + 1)) goto hell;
			else if (cur == each * (H + 1))
			{
				cur = 0;
				colcuts[pos++] = i;
			}
		}

		for (int i = 0; i <= H; i++)
			for (int j = 0; j <= V; j++)
			{
				num = 0;

				for (int a = (i == 0 ? 0 : rowcuts[i - 1] + 1); a <= rowcuts[i]; a++)
					for (int b = (j == 0 ? 0 : colcuts[j - 1] + 1); b <= colcuts[j]; b++)
						num += (lines[a][b] == '@');
				if (num != each) goto hell;
			}

		printf("Case #%d: POSSIBLE\n", c_n);
		continue;

	hell:
		printf("Case #%d: IMPOSSIBLE\n", c_n);
	}
	return -0;
}
