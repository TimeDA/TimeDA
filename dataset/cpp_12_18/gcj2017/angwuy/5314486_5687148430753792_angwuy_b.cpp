#include <cstdio>
 #include <cstring>
 #include <algorithm>
 
 const int MAXN = 1100;
 
 int n,c,m;
 int a[MAXN];
 int b[MAXN];
 int g[MAXN];
 bool chk[MAXN];
 
 int min(int x, int y){ return x < y ? x : y;}
 
 int max(int x, int y){ return x > y ? x : y;}
 
 void init()
 {
 	scanf("%d %d %d", &n, &c, &m);
 	memset(a, 0, sizeof(a));
 	memset(b, 0, sizeof(b));
 	for (int i = 1; i <= m; ++i)
 	{
 		int x, y;
 		scanf("%d %d", &x, &y);
 		if (y == 1)  a[++a[0]] = x;
 		else         b[++b[0]] = x;
 	}
 	std::sort(a + 1, a + a[0] + 1);
 	std::sort(b + 1, b + b[0] + 1);
 }
 
 bool dfs(int i)
 {
 	for (int j = 1; j <= b[0]; ++j)
 	if(a[i] != b[j] && !chk[j])
 	{
 		chk[j]=true;
 		if(g[j] == -1 || dfs(g[j]))
 		{
 			g[j] = i;
 			return true;
 		}
 	}
 	return false;
 }
 
 void solve()
 {
 	memset(g, 0xff, sizeof(g));
 	
 	int r = 0;
 	for(int i=a[0];i>=1;--i)
 	{
 		memset(chk, 0, sizeof(chk));
 		if(dfs(i)) ++r;
 	}
 	
 	int ans, cur;
 	if(a[0] == r)
 	{
 		ans = b[0];
 		cur = 0;
 	}
 	else
 	if(b[0] == r)
 	{
 		ans=a[0];
 		cur=0;
 	}
 	else
 	{
 		int tmp;
 		for(int i = 1; i <= b[0]; ++i) 
 			if(g[i]==-1) tmp=b[i];
 		if(tmp > 1){
  			ans = r + max(a[0]-r, b[0]-r);
 			cur = min(a[0] - r, b[0] - r);
 		}
 		else
 		{
 			ans = r + a[0] - r + b[0] - r;
 			cur=0;
 		}
 	}
 	printf("%d %d\n", ans, cur);
 }
 
 
 int main()
 {
 	//freopen("b.in", "r", stdin);
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