#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
long long m[1100];
long long s[1100];
long long p[1100];

int main()
{
	int t, teste;
	scanf("%d\n", &teste);
	for (int t = 0; t < teste; t++)
	{
		int r, c, b;
		scanf("%d %d %d\n", &r, &b, &c);
		long long maxtime = 0;
		for (int i = 0; i < c; i++)
		{
			scanf("%lld %lld %lld\n", &m[i], &s[i], &p[i]);
			maxtime = max(maxtime, m[i] * s[i] + p[i]);
		}

		long long ta = 0;
		long long tb = maxtime;
		while (ta + 1 < tb)
		{
			long long tc = (ta + tb) / 2;
			vector<long long> bcount;
			for (int i = 0; i < c; i++)
			{
				if (tc >= s[i] + p[i])
				{
					long long bits = min((tc - p[i]) / s[i], m[i]);
					bcount.push_back(bits);
				}
			}
			sort(bcount.begin(), bcount.end(), greater<long long>());
			long long bpassed = 0;
			for (int i = 0; i < r && i < bcount.size(); i++)
			{
				bpassed += bcount[i];
			}
			if (bpassed >= b)
				tb = tc;
			else
				ta = tc;
		}

		printf("Case #%d: %lld\n", t + 1, tb);
	}
	return 0;
}
