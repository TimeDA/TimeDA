#include <cstdio>
 #include <cstring>
 #include <cmath>
 
 const int MAXN = 200;
 
 int n, m;
 int a[MAXN][MAXN];
 int x[MAXN], y[MAXN];
 
 int max(int a, int b){ return a > b ? a : b;}
 
 void init()
 {
 	scanf("%d %d", &n, &m);
 	memset(x, 0, sizeof(x));
 	memset(y, 0, sizeof(y));
 	for (int i = 1; i <= n; ++i)
 	for (int j = 1; j <= m; ++j)
 	{
 		scanf("%d", &a[i][j]);
 		x[i] = max(x[i], a[i][j]);
 		y[j] = max(y[j], a[i][j]);
 	}
 }
 
 void solve()
 {
 	for (int i = 1; i <= n; ++i)
 	for (int j = 1; j <= m; ++j)
 	if (a[i][j] < x[i] && a[i][j] < y[j])
 	{
 		printf("NO\n");
 		return;
 	}
 	printf("YES\n");
 }
 
 
 
 int main()
 {
 	freopen("b.in", "r", stdin);
 	int t;
 	scanf("%d", &t);
 	for (int i = 1; i <= t; ++i)
 	{
 		init();
 		printf("Case #%d: ", i);
 		solve();
 	}
 	return 0;
 }