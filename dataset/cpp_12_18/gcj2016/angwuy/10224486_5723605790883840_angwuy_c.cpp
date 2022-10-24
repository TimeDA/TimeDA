#include <cstdio>
 #include <cstring>
 
 
 const int MAXN = 110;
 
 int n, m;
 int a[MAXN][MAXN];
 char b[MAXN][MAXN];
 int xx[MAXN * 4], yy[MAXN * 4];
 
 
 void init()
 {
 	scanf("%d %d", &n, &m);
 	memset(a, 0, sizeof(a));
 	int num = 0;
 	for (int i = 1; i <= m; ++i)
 	{
 		xx[++num] = 0;
 		yy[num] = i;
 	}
 	for (int i = 1; i <= n; ++i)
 	{
 		xx[++num] = i;
 		yy[num] = m + 1;
 	}
 	for (int i = m; i >= 1; --i)
 	{
 		xx[++num] = n + 1;
 		yy[num] = i;
 	}
 	for (int i = n; i >= 1; --i)
 	{
 		xx[++num] = i;
 		yy[num] = 0;
 	}
 	num = 0;
 	for (int i = 1; i <= n + m; ++i)
 	{
 		int n1, n2;
 		scanf("%d %d", &n1, &n2);
 		a[xx[n1]][yy[n1]] = ++num;
 		a[xx[n2]][yy[n2]] = num;
 	}
 }
 
 int check(int x, int y, int nx, int ny)
 {
 	while (a[nx][ny] == 0)
 	{
 		int tx, ty;
 		if (b[nx][ny] == '/')
 		{
 			if (nx == x + 1)
 			{
 				tx = nx;
 				ty = ny - 1;
 			}
 			else if (nx == x - 1)
 			{
 				tx = nx;
 				ty = ny + 1;
 			}
 			else if (ny == y + 1)
 			{
 				tx = nx - 1;
 				ty = ny;
 			}
 			else if (ny == y - 1)
 			{
 				tx = nx + 1;
 				ty = ny;
 			}
 		}
 		else
 		{
 			if (nx == x + 1)
 			{
 				tx = nx;
 				ty = ny + 1;
 			}
 			else if (nx == x - 1)
 			{
 				tx = nx;
 				ty = ny - 1;
 			}
 			else if (ny == y + 1)
 			{
 				tx = nx + 1;
 				ty = ny;
 			}
 			else if (ny == y - 1)
 			{
 				tx = nx - 1;
 				ty = ny;
 			}
 		}
 		x = nx;
 		y = ny;
 		nx = tx;
 		ny = ty;
 	}
 	return a[nx][ny];
 }
 
 bool chk()
 {
 	for (int i = 1; i <= m; ++i)
 	{
 		int st = a[0][i];
 		int ed = check(0, i, 1, i);
 		if (st != ed) return false;
 	}
 	for (int i = 1; i <= m; ++i)
 	{
 		int st = a[n + 1][i];
 		int ed = check(n + 1, i, n, i);
 		if (st != ed) return false;
 	}
 	for (int i = 1; i <= n; ++i)
 	{
 		int st = a[i][0];
 		int ed = check(i, 0, i, 1);
 		if (st != ed) return false;
 	}
 	for (int i = 1; i <= n; ++i)
 	{
 		int st = a[i][m + 1];
 		int ed = check(i, m + 1, i, m);
 		if (st != ed) return false;
 	}
 	return true;
 }
 
 
 bool dfs(int x, int y)
 {
 	if (x > n) 
 	{
 		if (chk())
 		{
 			for (int i = 1; i <= n; ++i)
 			{
 				for (int j = 1; j <= m; ++j)
 					printf("%c", b[i][j]);
 				printf("\n");
 			}
 			return true;
 		}
 		return false;
 	}
 	int nx, ny;
 	if (y == m) nx = x + 1, ny = 1;
 	else nx = x, ny = y + 1;
 	b[x][y] = '\\';
 	if (dfs(nx, ny)) return true;
 	b[x][y] = '/';
 	return dfs(nx, ny);
 }
 
 void solve()
 {
 	if (!dfs(1, 1)) printf("IMPOSSIBLE\n");
 }
 
 int main()
 {    
 	int tt, ii;
 	scanf("%d", &tt);
 	for (ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d:\n", ii);
 		init();
 		solve();
 	}
 	return 0;
 }