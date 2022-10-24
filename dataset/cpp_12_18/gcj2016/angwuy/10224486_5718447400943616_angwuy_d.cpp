#include <cstdio>
 #include <cstring>
 
 
 const int MAXN = 10;
 
 int n;
 int a[MAXN][MAXN];
 int v[MAXN];
 
 int ans;
 
 bool chk(int lck, int dep, int k)
 {
 //printf("%d, %d, %d\n", lck, dep, k);
 //fflush(stdout);
 	if (k <= 0) return false;
 	if (dep > n) return true;
 	if (dep == lck) return chk(lck, dep + 1, k);
 	bool ans = true;
 	for (int i = 1; i <= n; ++i)
 	if (v[i] && a[dep][i])
 	{
 		v[i] = false;
 		ans &= chk(lck, dep + 1, k - 1);
 		v[i] = true;
 	}
 	return ans & chk(lck, dep + 1, k);
 }
 
 void dfs(int x, int y, int cost)
 {
 	if (x > n)
 	{
 		bool ok = true;
 		for (int i = 1; i <= n; ++i)
 		{
 			int k = 0;
 			for (int j = 1; j <= n; ++j)
 			{
 				k += a[i][j];
 				v[j] = (a[i][j] == 1);
 			}
          		if (k == 0) ok = false;
          		else ok &= chk(i, 1, k);
 		}
 		if (ok && cost < ans) ans = cost;
 		return;
 	}
 	int nx, ny;
 	if (y == n) nx = x + 1, ny = 1;
 	else nx = x, ny = y + 1;
 	dfs(nx, ny, cost);
 	if (a[x][y] == 0)
 	{
 		a[x][y] = 1;
 		dfs(nx, ny, cost + 1);
 		a[x][y] = 0;
 	}
 }
 
 void init()
 {
 	char s[MAXN + 1];
 	scanf("%d\n", &n);
 	for (int i = 1; i <= n; ++i)
 	{
 		scanf("%s\n", s);
 		for (int j = 1; j <= n; ++j)
 		if (s[j - 1] == '0') a[i][j] = 0;
 		else a[i][j] = 1;
 	}
 }
 
 void solve()
 {
 	ans = 100;
 	dfs(1, 1, 0);
 	printf("%d\n", ans);
 }
 
 int main()
 {     
 	int tt, ii;
 	scanf("%d\n", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 		init();
 		solve();
 	}
 	return 0;
 }