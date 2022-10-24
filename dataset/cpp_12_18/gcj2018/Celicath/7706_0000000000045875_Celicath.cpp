/* 2018.5.20 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>

int T, N;

int A[200][200];
bool sr[200][200];
bool sc[200][200];
int r[200];
int c[200];

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				sr[i][j] = false;
				sc[i][j] = false;
				scanf("%d", &A[i][j]);
			}

		for (int i = 0; i < N; i++)
		{
			r[i] = 0;
			c[i] = 0;
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!sr[i][j])
					for (int k = j + 1; k < N; k++)
						if (A[i][j] == A[i][k])
						{
							r[i]++;
							sr[i][j] = sr[i][k] = true;
						}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!sc[j][i])
					for (int k = j + 1; k < N; k++)
						if (A[j][i] == A[k][i])
						{
							c[i]++;
							sc[j][i] = sc[k][i] = true;
						}

		int tot = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				if (sr[i][j] && sc[i][j] && r[i] > 0 && c[j] > 0)
				{
					int count = 0;
					for (int k = 0; k < N; k++)
						if (A[i][j] == A[i][k]) count++;
					if (count < 2)
						for (int k = 0; k < N; k++)
							if (A[i][j] == A[i][k]) sr[i][k] = false;
					for (int k = 0; k < N; k++)
						if (A[j][i] == A[k][i]) count++;
					if (count < 2)
						for (int k = 0; k < N; k++)
							if (A[j][i] == A[k][i]) sc[k][i] = false;
					r[i]--;
					c[j]--;
					tot++;
				}
			}
		for (int i = 0; i < N; i++)
			tot += r[i];
		for (int j = 0; j < N; j++)
			tot += c[j];
		printf("Case #%d: %d\n", c_n, tot);
	}
	return -0;
}
