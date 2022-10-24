/* 2018.4.14 Celicath */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <climits>
#include <set>

int T, N, P;
int W[200];
int H[200];
double diag[200];

double V[105][25005];

int main()
{
	scanf("%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		scanf("%d%d", &N, &P);

		double dP = P / 2.0;
		int sum = 0;

		for (int i = 1; i <= N; i++)
		{
			scanf("%d%d", W + i, H + i);
			if (W[i] > H[i])
			{
				int temp = W[i];
				W[i] = H[i];
				H[i] = temp;
			}
			diag[i] = sqrt(H[i] * H[i] + W[i] * W[i]);
			sum += H[i] + W[i];
		}
		dP -= sum;

		double max = 0;
		for (int i = 0; i <= 25000; i++)
		{
			V[0][i] = 0;
			for (int j = 1; j <= N; j++)
			{
				V[j][i] = std::max(V[j - 1][i], (i >= W[j] ? V[j - 1][i - W[j]] + diag[j] : 0));
				if (V[j][i] > max && i <= dP + 0.001) max = V[j][i];
			}
		}
		if (max > dP) max = dP;
		printf("Case #%d: %.9f\n", c_n, (max + sum) * 2);
	}
	return -0;
}
