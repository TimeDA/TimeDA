#include <iostream>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdio>
 #include <bitset>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 
 const int INF = 1000 * 1000 * 1000;
 
 struct rib {
 	int b, u, c, f;
 	size_t back;
 };
 
 void add_rib(vector < vector<rib> > & g, int a, int b, int u, int c) {
 	rib r1 = { b, u, c, 0, g[b].size() };
 	rib r2 = { a, 0, -c, 0, g[a].size() };
 	g[a].push_back(r1);
 	g[b].push_back(r2);
 }
 
 void solve(int tcase) {
 	cout << "Case #" << tcase << ": ";
 	int n, c, m;
 	cin >> n >> c >> m;	
 
 	vector < vector<rib> > g(m + 2);
 	int s, t;
 
 	vector<int> p(m), b(m);
 	vector<int> cur[2];
 	for (int i = 0; i < m; ++i) {
 		cin >> p[i] >> b[i];
 		--p[i];
 		--b[i];
 		cur[b[i]].push_back(p[i]);
 	}
 
 	int offset = cur[0].size();
 	for (int i = 0; i < cur[0].size(); ++i) {
 		for (int j = 0; j < cur[1].size(); ++j) {
 			if (cur[0][i] == cur[1][j] && cur[0][i] == 0) continue;
 			if (cur[0][i] == cur[1][j]) {
 				add_rib(g, i, j + offset, 1, 1);
 			} else {
 				add_rib(g, i, j + offset, 1, 0);
 			}
 		}
 	}
 	s = m, t = m + 1;
 	for (int i = 0; i < cur[0].size(); ++i) {
 		add_rib(g, s, i, 1, 0);
 	}
 	for (int i = 0; i < cur[1].size(); ++i) {
 		add_rib(g, i + offset, t, 1, 0);
 	}
 
 	int k = INF;
 
 	n = m + 2;
 
 
 	int flow = 0, cost = 0;
 	while (flow < k) {
 		vector<int> id(n, 0);
 		vector<int> d(n, INF);
 		vector<int> q(n);
 		vector<int> p(n);
 		vector<size_t> p_rib(n);
 		int qh = 0, qt = 0;
 		q[qt++] = s;
 		d[s] = 0;
 		while (qh != qt) {
 			int v = q[qh++];
 			id[v] = 2;
 			if (qh == n)  qh = 0;
 			for (size_t i = 0; i<g[v].size(); ++i) {
 				rib & r = g[v][i];
 				if (r.f < r.u && d[v] + r.c < d[r.b]) {
 					d[r.b] = d[v] + r.c;
 					if (id[r.b] == 0) {
 						q[qt++] = r.b;
 						if (qt == n)  qt = 0;
 					} else if (id[r.b] == 2) {
 						if (--qh == -1)  qh = n - 1;
 						q[qh] = r.b;
 					}
 					id[r.b] = 1;
 					p[r.b] = v;
 					p_rib[r.b] = i;
 				}
 			}
 		}
 		if (d[t] == INF)  break;
 		int addflow = k - flow;
 		for (int v = t; v != s; v = p[v]) {
 			int pv = p[v];  size_t pr = p_rib[v];
 			addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
 		}
 		for (int v = t; v != s; v = p[v]) {
 			int pv = p[v];  size_t pr = p_rib[v], r = g[pv][pr].back;
 			g[pv][pr].f += addflow;
 			g[v][r].f -= addflow;
 			cost += g[pv][pr].c * addflow;
 		}
 		flow += addflow;
 	}
 
 	int exp = min(cur[0].size(), cur[1].size());
 	cout << max(cur[0].size(), cur[1].size()) + exp - flow << " " << cost << endl;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	cin >> tests;
 
 	for (int i = 1; i <= tests; ++i) {
 		cerr << "Starting tcase: " << i << endl;
 		solve(i);
 	}
 
 	return 0;
 }