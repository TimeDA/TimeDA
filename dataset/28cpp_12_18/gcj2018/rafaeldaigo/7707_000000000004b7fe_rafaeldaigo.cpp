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
		int n;
		long long minx = 2000000000LL;
		long long maxx = 0;
		long long miny = 2000000000LL;
		long long maxy = 0;

		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
		{
			long long x, y;
			scanf("%lld %lld", &x, &y);
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
		}

		long long resp = max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
		printf("Case #%d: %lld\n", t + 1, resp);
	}
	return 0;
}
