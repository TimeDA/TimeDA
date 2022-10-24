#include <cstdio>
 #include <cstring>
 
 const int MAXN = 110;
 
 int n, p;
 int a[MAXN];
 //int dp[3][4][MAXN][MAXN][MAXN];
 
 //itn 
 
 
 void init()
 {
 	scanf("%d %d", &n, &p);
 	memset(a, 0, sizeof(a));
 	for (int i = 0; i < n; ++i)
 	{
 		int t;
 		scanf("%d", &t);
 		++a[t % p];
 	}
 }
 
 void solve()
 {
 	if (p == 2)
 	{
 		printf("%d\n", a[0] + (a[1] + 1) / 2);
 	}
 	else if (p == 3)
 	{
 		int t;
 		if (a[1] < a[2]) t = a[1];
 		else t = a[2];
 		a[1] -= t;
 		a[2] -= t;
 		printf("%d\n", a[0] + t + (a[1] + a[2] + 2) / 3);
 	}
 }
 
 
 int main()
 {
 	//memset(dp, 0xff, sizeof(dp));
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