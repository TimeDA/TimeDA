#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

#define MAXJ 120
using namespace std;

long long precalc[510][200];

int main()
{
	for (int i = 0; i <= MAXJ; i++)
	{
		precalc[0][i] = i * (i - 1) / 2;
	}
	for (int i = 0; i <= 500; i++)
	{
		precalc[i][0] = 0;
	}
	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= MAXJ; j++)
		{
			long long best = 510;
			for (int k = 0; k < j; k++)			
			{
				if (i >= k)
				{
					long long cand = precalc[i - k][k] + (j - k) * (j - k - 1) / 2;
					best = min(best, cand);
				}
			}
			precalc[i][j] = best;
		}
	}

	/*for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			printf("%4d ", precalc[i][j]);
		}
		printf("\n");
	}*/

	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int r, b;
		scanf("%d %d\n", &r, &b);
		int resp = 0;
		for (int i = 0; i <= MAXJ; i++)
		{
			if (precalc[r][i] > b)
			{
				resp = i - 2;
				break;
			}
		}

		printf("Case #%d: %d\n", t + 1, resp);
	}
	return 0;
}
