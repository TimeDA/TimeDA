#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int n, r, c, h, v, perp;
char buffer[110][110];
int countr[110];
int countc[110];
int cutsr[110];
int cutsc[110];
int regioncount[110][110];

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		scanf("%d %d %d %d\n", &r, &c, &h, &v);
		n = (h + 1) * (v + 1);

		for (int i = 0; i < r; i++)
		{
			scanf("%s", buffer[i]);
		}

		int tcount = 0;
		countr[0] = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (buffer[i][j] == '@')
				{
					tcount++;
				}
			}
			countr[i + 1] = tcount;
		}

		tcount = 0;
		countc[0] = 0;
		for (int j = 0; j < c; j++)
		{
			for (int i = 0; i < r; i++)
			{
				if (buffer[i][j] == '@')
				{
					tcount++;
				}
			}
			countc[j + 1] = tcount;
		}
		perp = tcount / n;

		bool fail = false;
		if (perp * n != tcount)
			fail = true;

		if (!fail)
		{
			int cutcount = 1;
			cutsr[0] = 0;
			for (int i = 0; i <= r && !fail; i++)
			{
				int expected = cutcount * (v + 1) * perp;
				if (countr[i] > expected)
				{
					fail = true;
				}
				else if (countr[i] == expected)
				{
					cutsr[cutcount] = i;
					cutcount++;
				}
			}

			cutcount = 1;
			cutsc[0] = 0;
			for (int j = 0; j <= c && !fail; j++)
			{
				int expected = cutcount * (h + 1) * perp;
				if (countc[j] > expected)
				{
					fail = true;
				}
				else if (countc[j] == expected)
				{
					cutsc[cutcount] = j;
					cutcount++;
				}
			}
		}

		if (!fail)
		{
			for (int i = 0; i <= h; i++)
			{
				regioncount[i][0] = 0;
			}
			for (int j = 0; j <= v; j++)
			{
				regioncount[0][j] = 0;
			}
			for (int i = 0; i <= h; i++)
			{
				int startr = cutsr[i];
				int endr = cutsr[i + 1];
				int extra = 0;
				for (int j = 0; j <= v; j++)
				{
					int startc = cutsc[j];
					int endc = cutsc[j + 1];
					for (int a = startr; a < endr; a++)
					{
						for (int b = startc; b < endc; b++)
						{
							if (buffer[a][b] == '@')
							{
								extra++;
							}
						}
					}
					regioncount[i + 1][j + 1] = regioncount[i][j + 1] + extra;
					if (regioncount[i + 1][j + 1] != (i + 1) * (j + 1) * perp)
						fail = true;
				}
			}
		}

		if (fail)
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
		else
			printf("Case #%d: POSSIBLE\n", t + 1);
	}
	return 0;
}
