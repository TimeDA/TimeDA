#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;
int w[110];
int h[110];
int minextra[110];
double maxextra[110];

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int n, p, minper;
		scanf("%d %d\n", &n, &p);
		minper = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d\n", &w[i], &h[i]);
			minper += 2 * w[i] + 2 * h[i];
			if (w[i] < h[i])
			{
				minextra[i] = 2 * w[i];
			}
			else
			{
				minextra[i] = 2 * h[i];
			}
			maxextra[i] = 2 * sqrt(w[i] * w[i] + h[i] * h[i]);
		}
		int target = p - minper;

		map<int, double> best[2];
		best[0].clear();
		best[0][0] = 0;
		int selfindex = 0;
		int otherindex = 1;
		for (int i = 0; i < n; i++)
		{
			best[otherindex].clear();
			map<int,double>::iterator it;
			for (it = best[selfindex].begin(); it != best[selfindex].end(); ++it)
			{
				if (best[otherindex].count(it->first) == 0 || it->second > best[otherindex][it->first])
				{
					best[otherindex][it->first] = it->second;
				}
				best[otherindex][it->first + minextra[i]] = it->second + maxextra[i];
			}
			selfindex = 1 - selfindex;
			otherindex = 1 - otherindex;
		}

		double resp = 0;
		map<int,double>::iterator respit;
		for (respit = best[selfindex].begin(); respit != best[selfindex].end(); ++respit)
		{
			if (respit->first <= target)
			{
				if (respit->second >= target)
					resp = target;
				else
				{
					resp = max(resp, respit->second);
				}
			}
		}

		printf("Case #%d: %lf\n", t + 1, resp + minper);
	}
	return 0;
}
