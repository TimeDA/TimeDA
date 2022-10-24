#include <cstdio>
 #include <cstring>
 
 const int MAXN = 60;
 
 int n, m, cnt;
 int num[MAXN][MAXN];
 char a[MAXN][MAXN];
 int b[MAXN][MAXN], c[MAXN][MAXN];
 int px[MAXN], py[MAXN];
 
 int mark[MAXN][MAXN];
 
 bool g[MAXN * 2][MAXN * 2];
 bool g2[MAXN * 2][MAXN * 2];
 int ans[MAXN];
 
 
 
 void init()
 {
 	scanf("%d %d\n", &n, &m);
 	cnt = 0;
 	memset(mark, 0, sizeof(mark));
 	for (int i = 0; i < n; ++i)
 	{
 		scanf("%s\n", a[i]);
 		for (int j = 0; j < m; ++j)
 		{
 			if (a[i][j] == '|' || a[i][j] == '-')
 			{
 				px[cnt] = i;
 				py[cnt] = j;
 				num[i][j] = (cnt++);
 			}
 			if (a[i][j] == '.')
 				mark[i][j] = 1;
 		}
 	}
 }
 
 bool check(int x, int y, int dx, int dy)
 {
 	for (x += dx, y += dy; ; x += dx, y += dy)
 	{
 		if (x < 0 || x >= n || y < 0 || y >= m) return true;
 		if (a[x][y] == '#') return true;
 		if (a[x][y] == '-' || a[x][y] == '|') return false;
 		if (a[x][y] == '/')
 		{
 			if (dx == 0)
 			{
 				dx = -dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = -dx;
 				dx = 0;
 			}
 		}
 		if (a[x][y] == '\\')
 		{
 			if (dx == 0)
 			{
 				dx = dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = dx;
 				dx = 0;
 			}
 		}
 	}
 }
 
 void make_mark(int x, int y, int dx, int dy)
 {
 	for (x += dx, y += dy; ; x += dx, y += dy)
 	{
 		if (x < 0 || x >= n || y < 0 || y >= m) return;
 		if (a[x][y] == '#') return;
 		mark[x][y] = 0;
 		if (a[x][y] == '/')
 		{
 			if (dx == 0)
 			{
 				dx = -dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = -dx;
 				dx = 0;
 			}
 		}
 		if (a[x][y] == '\\')
 		{
 			if (dx == 0)
 			{
 				dx = dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = dx;
 				dx = 0;
 			}
 		}
 	}
 }
 
 void record(int x, int y, int dx, int dy, int k, int s)
 {
 	for (x += dx, y += dy; ; x += dx, y += dy)
 	{
 		if (x < 0 || x >= n || y < 0 || y >= m) return;
 		if (a[x][y] == '#') return;
 		if (mark[x][y] > 0)
 		{
 			if (b[x][y] < 0)
 			{
 				b[x][y] = k;
 				c[x][y] = s;
 			}
 			else
 			{
 				g[(b[x][y] << 1) + (c[x][y] ^ 1)][(k << 1) + s] = true;
 				g[(k << 1) + (s ^ 1)][(b[x][y] << 1) + c[x][y]] = true;
 				b[x][y] = 0x7FFFFFFF;
 			}
 		}
 		if (a[x][y] == '/')
 		{
 			if (dx == 0)
 			{
 				dx = -dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = -dx;
 				dx = 0;
 			}
 		}
 		if (a[x][y] == '\\')
 		{
 			if (dx == 0)
 			{
 				dx = dy;
 				dy = 0;
 			}
 			else
 			{
 				dy = dx;
 				dx = 0;
 			}
 		}
 	}
 }
 
 void dfs(int k)
 {
 	if (ans[k >> 1] != 3) return;
 	ans[k >> 1] = (k & 1);
 	for (int i = 0; i < cnt * 2; ++i)
 	if (g[k][i])
 		dfs(i);
 }
 
 int tryone()
 {
 	memset(b, 0xff, sizeof(b));
 	memset(g, 0, sizeof(g));
 	for (int i = 0; i < cnt; ++i)
 	{
 		if (ans[i] == 1)
 		{
 			make_mark(px[i], py[i], 0, -1);
 			make_mark(px[i], py[i], 0, 1);
 		}
 		else if (ans[i] == 2)
 		{
 			make_mark(px[i], py[i], -1, 0);
 			make_mark(px[i], py[i], 1, 0);
 		}
 		else
 		{
 			record(px[i], py[i], 0, -1, i, 0);
 			record(px[i], py[i], 0, 1, i, 0);
 			record(px[i], py[i], -1, 0, i, 1);
 			record(px[i], py[i], 1, 0, i, 1);
 		}
 	}
 	int ret = 0;
 	for (int i = 0; i < n; ++i)
 	for (int j = 0; j < m; ++j)
 	if (mark[i][j] > 0)
 	{
 		if (b[i][j] < 0)
 		{
 			//printf("fuck!\n");
 			return -1;
 		}
 		else if (b[i][j] >= 0 && b[i][j] < 0x7FFFFFFF)
 		{
 			if ((ans[b[i][j]] & (1 << c[i][j])) == 0) 
 				return -1;
 			else
 			{
 				if (ans[b[i][j]] == 3) ret = 1;
 				ans[b[i][j]] = (1 << c[i][j]);
 			}
 		}
 	}
 	return ret;
 }
 
 void solve()
 {
 	memset(ans, 0, sizeof(ans));
 	for (int i = 0; i < cnt; ++i)
 	{
 		if (check(px[i], py[i], 0, -1) && check(px[i], py[i], 0, 1)) ans[i] += 1;
 		if (check(px[i], py[i], -1, 0) && check(px[i], py[i], 1, 0)) ans[i] += 2;
 		if (ans[i] == 0)
 		{
 			printf("IMPOSSIBLE\n");
 			return;
 		}
 	}
 	
 	for(;;)
 	{
 		int ret = tryone();
 		if (ret == -1)
 		{
 			printf("IMPOSSIBLE\n");
 			return;
 		}
 		else if (ret == 0) break;
 	}
 	
 	for (int i = 0; i < cnt * 2; ++i)
 	if (ans[(i >> 1)] == 3)
 	for (int j = 0; j < cnt * 2; ++j)
 	if (ans[(j >> 1)] == 3)
 		g2[i][j] = g[i][j];
 	for (int k = 0; k < cnt * 2; ++k)
 	if (ans[(k >> 1)] == 3)
 	for (int i = 0; i < cnt * 2; ++i)
 	if (ans[(i >> 1)] == 3)
 	for (int j = 0; j < cnt * 2; ++j)
 	if (ans[(j >> 1)] == 3)
 		if (g2[i][k] && g2[k][j]) g2[i][j] = true;
 	for (int i = 0; i < cnt; ++i)
 	if (ans[(i >> 1)] == 3)
 		if (g2[i << 1][(i << 1) + 1] || g2[(i << 1) + 1][i << 1])
 		{
 			printf("IMPOSSIBLE\n");
 			return;
 		}
 	printf("POSSIBLE\n");
 	for (int i = 0; i < cnt; ++i)
 	if (ans[i] == 3)
 		dfs(i << 1);
 	for (int i = 0; i < cnt; ++i)
 	if (ans[i] == 1)
 		a[px[i]][py[i]] = '-';
 	else
 		a[px[i]][py[i]] = '|';
 	for (int i = 0; i < n; ++i)
 		printf("%s\n", a[i]);
 }
 
 
 
 int main()
 {
 	//freopen("c.in", "r", stdin);
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
