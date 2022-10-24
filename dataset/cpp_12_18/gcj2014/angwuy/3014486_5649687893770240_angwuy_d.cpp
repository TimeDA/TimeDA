#include <cstdio>
 #include <cstring>
 
 const int MAXN = 100;
 const int MAXA = 200;
 
 int n, m;
 int a[MAXN];
 char s[10][MAXN];
 int trie[10][MAXN][MAXA];
 int len[MAXN];
 
 int calc()
 {
 	int ans = 0;
 	memset(trie, 0xff, sizeof(trie));
 	memset(len, 0xff, sizeof(len));
 	for (int i = 1; i <= n; ++i)
 	{
 		int k = a[i];
 		int cur = 0;
 		if (len[k] == -1)
 		{
 			len[k] = 0;
 			++ans;
 		}
 		for (int j = 0; j < strlen(s[i]); ++j)
 		{
 			if (trie[k][cur][s[i][j]] == -1) 
 			{
 				trie[k][cur][s[i][j]] = ++len[k];
 				++ans;
 			}
 			cur = trie[k][cur][s[i][j]];
 		}
 	}
 	return ans;
 }
 
 void init()
 {
 	scanf("%d %d", &n, &m);
 	for (int i = 1; i <= n; ++i)
 		scanf("%s", s[i]);
 }
 
 int ansx, ansy;
 
 void dfs(int dep)
 {
 	if (dep > n)
 	{
 		int ret = calc();
 		if (ret > ansx) { ansx = ret; ansy = 1;}
 		else if (ret == ansx) { ++ansy;}
 		return;
 	}
 	for (int i = 1; i <= m; ++i)
 	{
 		a[dep] = i;
 		dfs(dep + 1);
 	}
 }
 
 void solve()
 {
 	ansx = -1;
 	dfs(1);
 	printf("%d %d\n", ansx, ansy);
 }
 
 int main()
 {
 	freopen("D.in", "r", stdin);
 	freopen("D.out","w",stdout);
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
