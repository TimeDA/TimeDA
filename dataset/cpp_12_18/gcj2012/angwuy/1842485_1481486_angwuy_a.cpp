#include <cstdio>
 #include <cstring>
 
 const int MAXN = 10010;
 
 int n, d1;
 int d[MAXN], l[MAXN];
 int f[MAXN], next[MAXN];
 
 inline int min(int a, int b){ return a < b ? a : b;}
 
 int getnext(int p)
 {
 	return f[next[p]] < 0 ? next[p] : next[p] = getnext(next[p]);
 }
 
 void init()
 {
 	scanf("%d", &n);
 	for (int i = 1; i <= n; ++i)
 		scanf("%d %d", &d[i], &l[i]);
 	scanf("%d", &d1);
 }
 
 void solve()
 {
 	memset(f, 0xff, sizeof(f));
 	f[1] = d[1];
 	d[n + 1] = d1;
 	l[n + 1] = 0x7FFFFFFF;
 	d[n + 2] = 0x7FFFFFFF;
 	int i, j;
 	for (i = 1; i <= n + 1; ++i)
 		next[i] = i + 1;
 	for (i = 1; i <= n; ++i)
 	{
 		for (j = getnext(i); d[j] <= d[i] + f[i]; j = getnext(j))
 		//if (l[j] >= d[j] - d[i])
 			f[j] = min(d[j] - d[i], l[j]);
 	}
 	if (f[n + 1] >= 0) printf("YES\n");
 	else printf("NO\n");
 }
 
 int main()
 {
 	freopen("a.in", "r", stdin);
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
