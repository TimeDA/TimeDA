#include <cstdio>
 #include <cstring>
 #include <algorithm>
 
 using namespace std;
 
 const int MAXN = 1000;
 
 int n, m;
 int a[MAXN];
 
 void init()
 {
 	scanf("%d %d", &n, &m);
 	for (int i = 1; i <= n; ++i)
 		scanf("%d", &a[i]);
 	sort(a + 1, a + n + 1);
 }
 
 void solve()
 {
 	int ans = 0;
 	for (int i = n; i >= 1; --i)
 	if (a[i] > 0)
 	{
 		int t;
 		for (t = i - 1; t >= 1; --t)
 		if (a[t] > 0 && a[i] + a[t] <= m) break;
 		++ans;
 		a[t] = -1;
 	}
 	printf("%d\n", ans);
 }
 
 int main()
 {
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		init();
 		printf("Case #%d: ", ii);
 		solve();
 	}
 	return 0;
 }
