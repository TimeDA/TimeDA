#include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 #include <bitset>
 #include <unordered_map>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define PI 3.14159265358979
 #define MEMS(a,b) memset(a,b,sizeof(a))
 #define LL long long
 #define U unsigned
 
 struct edge
 {
 	int u, cap, flow;
 };
 vector<edge> E;
 vector<vector<int> > g;
 int was[200010];
 int d[200010];
 int p[200010];
 int start, finish;
 int pr[200010];
 void addedge(int a, int b, int cap)
 {
 	edge e1 = { b, cap, 0 };
 	edge e2 = { a, 0, 0 };
 	g[a].push_back(E.size());
 	E.push_back(e1);
 	g[b].push_back(E.size());
 	E.push_back(e2);
 }
 LL dfs(int v, LL flow)
 {
 	if (v == finish)
 		return flow;
 	if (!flow)
 		return 0;
 	int res = 0;
 	FOR(i, pr[v], g[v].size())
 	{
 		int k = g[v][i];
 		int to = E[k].u;
 		pr[v]++;
 		if (d[to] == d[v] + 1)
 		{
 			LL fl = MIN(flow, E[k].cap - E[k].flow);
 			LL res1 = dfs(to, fl);
 			if (res1)
 			{
 				E[k].flow += res1;
 				E[k ^ 1].flow -= res1;
 				return res1;
 			}
 		}
 	}
 	return 0;
 }
 bool bfs()
 {
 	p[0] = start;
 	MEMS(was, 0);
 	MEMS(d, -1);
 	was[start] = 1;
 	d[start] = 0;
 	int l = 0, r = 0;
 	while (l <= r)
 	{
 		int v = p[l];
 		if (v == finish)
 			break;
 		l++;
 		FOR(i, 0, g[v].size())
 		{
 			int x = g[v][i];
 			int to = E[g[v][i]].u;
 			if ((was[to] == 0) && (E[x].flow<E[x].cap))
 			{
 				r++;
 				p[r] = to;
 				d[to] = d[v] + 1;
 				was[to] = 1;
 			}
 		}
 	}
 	return (was[finish] == 1);
 }
 LL dinic()
 {
 	LL flow = 0;
 	while (1)
 	{
 		if (!bfs())
 			return flow;
 		MEMS(pr, 0);
 		while (1)
 		{
 			LL k = dfs(start, 1000000);
 			if (!k)
 				break;
 			flow += k;
 		}
 	}
 }
 
 int gr[510][510];
 int innum[510][510];
 int outnum[510][510];
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt","w",stdout);
 	double beg = clock();
 #else
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt","w",stdout);
 #endif
 
 	int t;
 	scanf("%d", &t);
 	FOR(test, 1, t + 1)
 	{
 		int m, n, b;
 		scanf("%d%d%d", &m, &n, &b);
 		MEMS(gr, 0);
 		FOR(it, 0, b)
 		{
 			int x1, y1, x2, y2;
 			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 			FOR(i, y1, y2 + 1)
 				FOR(j, x1, x2 + 1)
 					gr[i][j] = 1;
 		}
 		int v = 2;
 		g.clear();
 		E.clear();
 		g.resize(n * m * 2 + 10);
 		FOR(i, 0, n)
 		{
 			FOR(j, 0, m)
 			{
 				innum[i][j] = v;
 				v++;
 				outnum[i][j] = v;
 				v++;
 				addedge(innum[i][j], outnum[i][j], 1);
 			}
 		}
 		FOR(j, 0, m)
 		{
 			if (gr[0][j] == 0)
 			{
 				addedge(0, innum[0][j], 1);
 			}
 		}
 		FOR(i,0,n)
 			FOR(j, 0, m)
 			{
 				if (gr[i][j] == 0)
 				{
 					if ((j) && (gr[i][j - 1]==0))
 					{
 						addedge(outnum[i][j], innum[i][j - 1], 1);
 					}
 					if ((j+1!=m) && (gr[i][j + 1]==0))
 					{
 						addedge(outnum[i][j], innum[i][j + 1], 1);
 					}
 					if ((i + 1 != n) && (gr[i+1][j]==0))
 					{
 						addedge(outnum[i][j], innum[i+1][j], 1);
 					}
 					if ((i) && (gr[i - 1][j] == 0))
 					{
 						addedge(outnum[i][j], innum[i - 1][j], 1);
 					}
 				}
 			}
 		FOR(j, 0, m)
 		{
 			if (gr[n-1][j] == 0)
 			{
 				addedge(outnum[n-1][j], 1, 1);
 			}
 		}
 		start = 0;
 		finish = 1;
 		int res = dinic();
 		printf("Case #%d: %d\n", test, res);
 		fprintf(stderr, "%d done", test);
 	}
 
 	
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }