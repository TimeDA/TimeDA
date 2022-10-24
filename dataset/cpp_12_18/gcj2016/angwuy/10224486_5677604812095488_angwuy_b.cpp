#include <cstdio>
 #include <cstring>
 #include <algorithm>
 
 const int MAXN = 220;
 
 int n, m;
 double a[MAXN];
 double f[MAXN][MAXN];
 
 
 void init()
 {
 	scanf("%d %d", &n, &m);
 	for (int i = 1; i <= n; ++i)
 		scanf("%lf", &a[i]);
 }
 
 double max(double a, double b){ return a > b ? a : b;}
 
 void solve()
 {
 	std::sort(a + 1, a + n + 1);
 	double ans = 0;
 	for (int i = 0; i <= m; ++i)
 	{
 		int j = m - i;
 		memset(f, 0, sizeof(f));
 		f[0][0] = 1;
 		for (int k = 1; k <= m; ++k)
 		{
 			double tmp;
 			if (k <= i) tmp = a[k];
 			else tmp = a[n - k + i + 1];
 			f[k][0] = f[k - 1][0] * (1 - tmp);
 			for (int l = 1; l <= k; ++l)
 				f[k][l] = f[k - 1][l - 1] * tmp + f[k - 1][l] * (1 - tmp);
 		}
 		if (f[m][m >> 1] > ans) ans = f[m][m >> 1];
 	}
 	printf("%.8lf\n", ans);
 }
 
 
 int main()
 {   
 	int tt, ii;
 	scanf("%d", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		init();
 		solve();
 	}
 	return 0;
 }
 
