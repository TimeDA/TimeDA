#include <cstdio>
 #include <cstring>
 
 const int MAXN = 1100;
 const int MAXV = 210000;
 const int MAXE = 2100000;
 
 struct Tedge{
 	int p, c, f, next;
 }; 
 
 int n, m, s, t, len;
 int a[MAXV];
 Tedge edge[MAXE];
 int map[MAXN][MAXN], map2[MAXN][MAXN];
 int d[MAXV], q[MAXV], last[MAXV];
 
 void addedge(int s, int t)
 {
 	edge[++len].p = t;
 	edge[len].next = a[s];
 	edge[len].f = len + 1;
 	edge[len].c = 1;
 	a[s] = len;
 	edge[++len].p = s;
 	edge[len].next = a[t];
 	edge[len].f = len - 1;
 	edge[len].c = 0;
 	a[t] = len;
 }
 
 void init()
 {
 	int k = 0;
 	scanf("%d %d %d", &n, &m, &k);
 	int x1, x2, y1, y2;
 	memset(map, 0, sizeof(map));
 	while (k--)
 	{
 		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 		for (int i = x1; i <= x2; ++i)
 		for (int j = y1; j <= y2; ++j)
 			map[i][j] = -1;
 	}
 	s = 0;
 	memset(a, 0xff, sizeof(a));
 	len = 0;
 	for (int i = 0; i < n; ++i)
 	for (int j = 0; j < m; ++j)
 	if (map[i][j] == 0)
 	{
 		map[i][j] = (++s);
 		map2[i][j] = (++s);
 		addedge(map[i][j], map2[i][j]);
 	}
 	/*for (int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < m; ++j)
 			printf("%3d ", map[i][j]);
 		printf("\n");
 	}*/
 	++s;
 	t = s + 1;
 	for (int i = 0; i < n; ++i)
 	{
 		if (map[i][0] >= 0) addedge(s, map[i][0]);
 		if (map[i][m - 1] >= 0) addedge(map2[i][m - 1], t);
 	}
 	for (int i = 0; i < n; ++i)
 	for (int j = 0; j < m; ++j)
 	if (map[i][j] >= 0)
 	{
 		if (i + 1 < n && map[i + 1][j] >= 0)
 		{
 			addedge(map2[i][j], map[i + 1][j]);
 			addedge(map2[i + 1][j], map[i][j]);
 		}
 		if (j + 1 < m && map[i][j + 1] >= 0)
 		{
 			addedge(map2[i][j], map[i][j + 1]);
 			addedge(map2[i][j + 1], map[i][j]);
 		}
 	}
 }
 
 bool bfs()
 {
 	memset(d, 0xff, sizeof(d));
 	int st = 0, ed = 1, i, k;
 	q[1] = s;
 	d[s] = 0;
 	while (st < ed)
 	{
 		k = q[++st];
 		//printf("%d\n", k);
 		for (i = a[k]; i != -1; i = edge[i].next)
 		if (edge[i].c > 0 && d[edge[i].p] < 0)
 		{
 			d[edge[i].p] = d[k] + 1;
 			q[++ed] = edge[i].p;
 			last[edge[i].p] = i;
 			if (edge[i].p == t) return true;
 		}
 	}
 	return false;
 }
 
 void solve()
 {
 	int ans = 0;
 	while (bfs())
 	{
 		++ans;
 		for (int cur = t; cur != s; cur = edge[edge[last[cur]].f].p)
 		{
 			--edge[last[cur]].c;
 			++edge[edge[last[cur]].f].c;
 		}
 	}
 	printf("%d\n", ans);
 }
 
 int main()
 {
 	freopen("C.in", "r", stdin);
 	freopen("C.out","w",stdout);
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
