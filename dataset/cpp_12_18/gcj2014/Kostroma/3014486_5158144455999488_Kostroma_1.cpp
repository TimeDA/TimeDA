#define _CRT_SECURE_NO_WARNINGS
 #pragma comment (linker, "/STACK:128000000")
 //#include "testlib.h"
 #include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <iostream>
 #include <memory.h>
 #include <string>
 #include <vector>
 #include <set>
 #include <map>
 #include <cmath>
 //#include <unordered_map>
 //#include <unordered_set>
 #include <ctime>
 #include <stack>
 #include <queue>
 using namespace std;
 //#define FILENAME ""
 #define mp make_pair
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve();
 //void precalc();
 clock_t start;
 //int timer = 1;
 
 
 int main() {
 #ifdef room111
     freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #else
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
     //freopen(FILENAME".in", "r", stdin);
     //freopen(FILENAME ".out", "w", stdout);
 #endif
     int t = 1;
 	cout.sync_with_stdio(0);
 	//precalc();
 	cout.precision(10);
 	cout << fixed;
 	cin >> t;
 	start = clock();
 	int testNum = 1;
     while (t--) {
 		cout << "Case #" << testNum++ << ": ";
         solve();
 		//++timer;
 	}
 
 #ifdef room111
 	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
     return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 //#define int li
 
 int n, m;
 
 int b;
 
 int water[1010][1010];
 
 struct edge {
 	int from, to, cap, flow;
 	edge(int from, int to, int cap):from(from), to(to), cap(cap) { flow = 0; }
 };
 
 vector<edge> edges;
 vector<int> g[100500];
 
 void add_edge(int from, int to, int cap) {
 	g[from].push_back(edges.size());
 	edges.push_back(edge(from, to, cap));
 	g[to].push_back(edges.size());
 	edges.push_back(edge(to, from, 0));
 }
 
 
 
 int dist[100500];
 
 int q[100500];
 
 int pointer[100500];
 
 int dfs(int v, int t, int mx) {
 	if(!mx)
 		return mx;
 	if(v == t)
 		return mx;
 
 	for(int& i = pointer[v]; i < g[v].size(); ++i) {
 		int id = g[v][i];
 		edge& e = edges[id];
 		if(dist[e.to] == dist[v] + 1) {
 			if(int pushed = dfs(e.to, t, min(mx, (e.cap - e.flow)))) {
 				e.flow += pushed;
 				edges[id ^ 1].flow -= pushed;
 				return pushed;
 			}
 		}
 	}
 	return 0;
 }
 
 bool bfs(int s, int t) {
 	int qh = 0, qt = 0;
 	q[qt++] = s;
 	memset(dist, -1, sizeof dist);
 	dist[s] = 0;
 	while(qh != qt) {
 		int cur = q[qh++];
 		for(int i = 0; i < g[cur].size(); ++i) {
 			edge& e = edges[g[cur][i]];
 			if(e.flow != e.cap && dist[e.to] == -1) {
 				q[qt++] = e.to;
 				dist[e.to] = dist[cur] + 1;
 			}
 		}
 	}
 	return dist[t] != -1;
 }
 
 int dinic(int s, int t) {
 	int result = 0;
 	while(bfs(s, t)) {
 		memset(pointer, 0, sizeof pointer);
 		while(true) {
 			int pushed = dfs(s, t, 1e9);
 			if (pushed == 0)
 				break;
 			result += pushed;
 		}
 	}
 	return result;
 }
 
 int dx[] = {-1, 0, 1, 0};
 int dy[] = {0, 1, 0, -1};
 
 void solve() {
 	cin >> m >> n >> b;
 	memset(water, 0, sizeof water);
 	for (int w = 0; w < b; ++w) {
 		pair<int, int> start, finish;
 		cin >> start.first >> start.second >> finish.first >> finish.second;
 		for (int i = start.first; i <= finish.first; ++i)
 			for (int j = start.second; j <= finish.second; ++j)
 				water[j][i] = 1;
 	}
 
 	for (int i = 0; i < 100500; ++i)
 		g[i].clear();
 	edges.clear();
 
 	int s = 2 * n * m;
 	int t = 2 * n * m + 1;
 
 	for (int i = 0; i < m; ++i)
 		if (!water[0][i])
 			add_edge(s, i, 1);
 
 	for (int i = 0; i < m; ++i)
 		if (!water[n - 1][i])
 			add_edge(i + n * m + (n - 1) * m, t, 1);
 	
 
 	for (int i = 0; i < n; ++i)
 		for (int j = 0; j < m; ++j) {
 			if (water[i][j])
 				continue;
 			add_edge(i * m + j, n * m + i * m + j, 1);
 			for (int k = 0; k < 4; ++k) {
 				int x = i + dx[k];
 				int y = j + dy[k];
 				if (x < 0 || y < 0 || x >= n || y >= m)
 					continue;
 				if (water[x][y])
 					continue;
 				add_edge(n * m + i * m + j, x * m + y, 1);
 			}
 		}
 
 	cout << dinic(s, t) << "\n";
 
 }
