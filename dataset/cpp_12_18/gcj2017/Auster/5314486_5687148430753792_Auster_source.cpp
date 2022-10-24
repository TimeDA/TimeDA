#define _CRT_SECURE_NO_WARNINGS
 
 #pragma comment(linker, "/STACK:250000000")
 
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <string>
 #include <vector>
 #include <bitset>
 #include <queue>
 #include <stack>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <complex>
 #include <functional>
 #include <numeric>
 #include <random>
 #include <cstring>
 #include <ctime>
 #include <cassert>
 
 #define y1 klfjvkldfngldf
 
 using namespace std;
 
 typedef long long LL;
 
 
 struct Network
 {
 	struct edge
 	{
 		int from, to, cap, cost, flow;
 	};
 
 	static const int N = 2 + 3 * 1000;
 
 	vector<edge> E;
 	vector<int> G[N];
 	LL phi[N];
 	LL d[N];
 	int path[N];
 	int n;
 
 	vector<int> ids;
 
 	Network(int n) : n(n) {}
 
 	void addEdge(int from, int to, int cap, int cost)
 	{
 		G[from].push_back(E.size());
 		E.push_back({ from, to, cap, cost, 0 });
 		G[to].push_back(E.size());
 		E.push_back({ to, from, 0, -cost, 0 });
 	}
 
 	void bellmanFord(int from)
 	{
 		fill(phi, phi + n, (LL)1e9);
 		phi[from] = 0;
 		for (int i = 0; i < n - 1; ++i)
 			for (edge & e : E)
 				if (e.cap > 0)
 					phi[e.to] = min(phi[e.to], phi[e.from] + e.cost);
 	}
 
 	void push(int v)
 	{
 		while (path[v] != -1)
 		{
 			E[path[v]].flow++;
 			E[path[v] ^ 1].flow--;
 			v = E[path[v]].from;
 		}
 	}
 
 	LL getWeight(const edge & e)
 	{
 		return e.cost - phi[e.to] + phi[e.from];
 	}
 
 	queue<int> q0, q1;
 	int d0, d1;
 
 	void dijkstra(int from)
 	{
 		fill(path, path + n, -1);
 		fill(d, d + n, (LL)1e9);
 		d[from] = 0;
 		d0 = 0;
 		d1 = 1;
 		q0.push(from);
 		while (!q0.empty() || !q1.empty())
 		{
 			if (q0.empty())
 			{
 				swap(q0, q1);
 				d0 = d1;
 				d1++;
 			}
 			int v = q0.front();
 			q0.pop();
 			if (d[v] != d0)
 				continue;
 			for (int id : G[v])
 			{
 				edge & e = E[id];
 				if (e.cap - e.flow == 0)
 					continue;
 				LL w = getWeight(e);
 				//if (w < 0 || w > 1)
 				//{
 				//	cout << "!!!";
 				//}
 				if (d[e.to] > d[e.from] + w)
 				{
 					d[e.to] = d[e.from] + w;
 					if (w == 0)
 						q0.push(e.to);
 					else
 						q1.push(e.to);
 					path[e.to] = id;
 				}
 			}
 		}
 	}
 
 	pair<int, int> minCost(int from, int to)
 	{
 		int flow = 0;
 		int cost = 0;
 		bellmanFord(from);
 		while (1)
 		{
 			dijkstra(from);
 			if (d[to] + phi[to] >= (int)1e9)
 				break;
 			flow++;
 			cost += d[to] + phi[to];
 			push(to);
 			for (int i = 0; i < n; ++i)
 				phi[i] += d[i];
 		}
 		return{ flow, cost };
 	}
 
 	void init(int w)
 	{
 		for (int i = 0; i < E.size(); ++i)
 			E[i].flow = 0;
 		for (int id : ids)
 			E[id].cap = w;
 	}
 };
 
 int n, c, m;
 int p[1000], b[1000];
 
 Network G(0);
 
 int cnt[1000];
 
 int from = 0, to = 0;
 
 void init()
 {
 	G = Network(2 + c + 2 * n);
 	from = c + 2 * n;
 	to = c + 2 * n + 1;
 	for (int i = 0; i < m; ++i)
 	{
 		int u = b[i];
 		int v0 = c + n + p[i];
 		G.addEdge(u, v0, 1, 0);
 		if (p[i] != 0)
 		{
 			int v1 = c + p[i] - 1;
 			G.addEdge(u, v1, 1, 1);
 		}
 	}
 	for (int i = 1; i < n; ++i)
 	{
 		int u = c + i;
 		int v = c + i - 1;
 		G.addEdge(u, v, (int)1e9, 0);
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		int u = c + i;
 		int v = c + n + i;
 		G.addEdge(u, v, (int)1e9, 0);
 	}
 
 	for (int i = 0; i < c; ++i)
 	{
 		G.addEdge(from, i, cnt[i], 0);
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		G.ids.push_back(G.E.size());
 		G.addEdge(c + n + i, to, 0, 0);
 	}
 }
 
 void read()
 {
 	scanf("%d%d%d", &n, &c, &m);
 	for (int i = 0; i < m; ++i)
 	{
 		scanf("%d%d", &p[i], &b[i]);
 		p[i]--;
 		b[i]--;
 	}
 }
 
 pair<int, int> solve()
 {
 	memset(cnt, 0, sizeof(cnt));
 	for (int i = 0; i < m; ++i)
 		cnt[b[i]]++;
 	init();
 
 	int L = *max_element(cnt, cnt + c) - 1;
 	int R = 1001;
 
 	while (R - L > 1)
 	{
 		int M = (L + R) / 2;
 		G.init(M);
 
 		auto res = G.minCost(from, to);
 		if (res.first == m)
 			R = M;
 		else
 			L = M;
 	}
 
 	G.init(R);
 	int cost = G.minCost(from, to).second;
 	return{ R, cost };
 }
 
 int main()
 {
 #ifndef _DEBUG
 	freopen("B-small-attempt4.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 	int t;
 	scanf("%d", &t);
 
 	//int start = clock();
 	for (int i = 1; i <= t; ++i)
 	{
 		read();
 		auto res = solve();
 		printf("Case #%d: %d %d\n", i, res.first, res.second);
 	}
 	return 0;
 }