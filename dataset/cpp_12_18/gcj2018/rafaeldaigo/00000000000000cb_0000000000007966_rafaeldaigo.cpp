#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n, d;
		char buffer[40];
		scanf("%d %s\n", &d, buffer);
		n = strlen(buffer);
		int resp = 0;
		int sacount[40];
		int ccount = 0;
		int tpow = 1;
		int damage = 0;
		int scount = 0;
		int sacounttemp = 0;

		for (int i = 0; i < n; i++)
		{
			if (buffer[i] == 'C')
			{
				tpow *= 2;
			}
			else
			{
				damage += tpow;
				scount++;
			}
		}

		sacounttemp = scount;
		for (int i = 0; i < n; i++)
		{
			if (buffer[i] == 'C')
			{
				sacount[ccount] = sacounttemp;
				ccount++;
			}
			else
			{
				sacounttemp--;
			}
		}

		if (scount > d)
			printf("Case #%d: IMPOSSIBLE\n", t + 1);
		else
		{
			for (int i = ccount - 1; i >= 0 && damage > d; i--)
			{
				tpow /= 2;
				for (int j = sacount[i]; j > 0 && damage > d; j--)
				{
					damage -= tpow;
					resp++;
				}
			}
			printf("Case #%d: %d\n", t + 1, resp);
		}
	}
	return 0;
}
