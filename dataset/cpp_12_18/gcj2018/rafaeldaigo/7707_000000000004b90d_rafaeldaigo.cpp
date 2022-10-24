#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>

#define MAXN 1100
using namespace std;

long long x[MAXN];
long long y[MAXN];
long long z[MAXN];

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n;
		int resp[MAXN];
		bool used[MAXN];
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
			used[i] = false;
		}
		resp[0] = 0;

		for (int i = 1; i < n; i++)
		{
			if (z[i] > z[resp[0]])
				resp[0] = i;
		}
		used[resp[0]] = true;

		double best1 = 1000000.0;
		int bestin1 = -1;
		for (int i = 0; i < n; i++)
		{
			if (used[i])
				continue;
			double dx = x[i] - x[resp[0]];
			double dy = y[i] - y[resp[0]];
			double dz = z[i] - z[resp[0]];
			double cand = -dz / sqrt(dx * dx + dy * dy);
			if (cand < best1)
			{
				best1 = cand;
				bestin1 = i;
			}
		}
		resp[1] = bestin1;
		used[resp[1]] = true;

		for (int i = 2; i < n; i++)
		{
			double dx1 = x[resp[i - 1]] - x[resp[i - 2]];
			double dy1 = y[resp[i - 1]] - y[resp[i - 2]];
			double dz1 = z[resp[i - 1]] - z[resp[i - 2]];
			double best = -10.0f;
			int bestin = -1;
			for (int j = 0; j < n; j++)
			{
				if (used[j])
					continue;
				double dx2 = x[j] - x[resp[i - 2]];
				double dy2 = y[j] - y[resp[i - 2]];
				double dz2 = z[j] - z[resp[i - 2]];
				double cx = dy1 * dz2 - dz1 * dy2;
				double cy = dz1 * dx2 - dx1 * dz2;
				double cz = dx1 * dy2 - dy1 * dx2;
				double len = sqrt(cx * cx + cy * cy + cz * cz);
				double cand = abs(cz) / len;
				if (cand > best)
				{
					best = cand;
					bestin = j;
				}
			}
			resp[i] = bestin;
			used[bestin] = true;
		}		

		printf("Case #%d:", t + 1);
		for (int i = n - 1; i >= 0; i--)
		{
			printf(" %d", resp[i] + 1);
		}
		printf("\n");
	}
	return 0;
}
