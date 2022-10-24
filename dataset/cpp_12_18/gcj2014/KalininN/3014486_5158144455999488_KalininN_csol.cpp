#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 #include <queue>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 struct tsob
 {
 	int y, t;
 	tsob() {}
 	tsob(int y, int t): y(y), t(t) {}
 };
 
 inline bool operator<(const tsob &a, const tsob &b)
 {
 	return a.y < b.y;
 }
 
 struct te
 {
 	int v, f, maxf, o;
 	
 	te() {}
 	te(int v, int f, int maxf, int o): v(v), f(f), maxf(maxf), o(o) {}
 };
 
 const int maxw = 1005;
 const int inf = 1e5;
 const int maxv = 10005;
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 
 vector<tsob> sobs[maxw];
 vector<int> ys;
 int n, W, H;
 queue<int> q;
 int d[maxv], from[maxv];
 vector<te> gr[maxv];
 bool can[maxw][50];
 
 inline int cmpr(int x, int y, int t)
 {
 	return (y * W + x) * 2 + t;
 }
 
 inline void add(int a, int b, int t = 1)
 {
 	int sa = gr[a].size();
 	int sb = gr[b].size();
 	gr[a].push_back(te(b, 0, t, sb));
 	gr[b].push_back(te(a, 0, 0, sa));
 }
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T_ = 1; T_ <= NT; T_++)
 	{
 		printf("Case #%d:", T_);
 		
 		scanf("%d%d%d", &W, &H, &n);
 		for (int i = 0; i < W; i++)
 		{
 			sobs[i].resize(0);
 		}
 		ys.resize(0);
 		ys.push_back(0);
 		ys.push_back(H - 1);
 		for (int i = 0; i < n; i++)
 		{
 			int x1, y1, x2, y2;
 			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 			for (int x = x1; x <= x2; x++)
 			{
 				sobs[x].push_back(tsob(y1, 1));
 				sobs[x].push_back(tsob(y2 + 1, -1));
 			}
 			ys.push_back(y1);
 			if (y1 > 0) ys.push_back(y1 - 1);
 			ys.push_back(y2);
 			if (y2 < H - 1) ys.push_back(y2 + 1);
 		}
 		sort(ys.begin(), ys.end());
 		ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
 		for (int x = 0; x < W; x++)
 		{
 			sort(sobs[x].begin(), sobs[x].end());
 			int cur = 0;
 			int kv = 0;
 			for (int i = 0; i < (int)sobs[x].size(); i++)
 			{
 				int cury = lower_bound(ys.begin(), ys.end(), sobs[x][i].y) - ys.begin();
 				while (cur < cury)
 				{
 					can[x][cur] = (kv == 0);
 					cur++;
 				}
 				kv += sobs[x][i].t;
 			}
 			while (cur < (int)ys.size())
 			{
 				can[x][cur] = true;
 				cur++;
 			}
 		}
 		H = ys.size();
 		int S = W * H * 2;
 		int T = S + 1;
 		int nn = T + 1;
 		for (int i = 0; i < nn; i++) gr[i].resize(0);
 		
 		for (int x = 0; x < W; x++)
 		{
 			for (int y = 0; y < H; y++) if (can[x][y])
 			{
 				for (int dir = 0; dir < 4; dir++)
 				{
 					int nx = x + dx[dir];
 					int ny = y + dy[dir];
 					if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
 					if (!can[nx][ny]) continue;
 					add(cmpr(x, y, 1), cmpr(nx, ny, 0), inf);
 				}
 				add(cmpr(x, y, 0), cmpr(x, y, 1));
 			}
 		}
 		for (int x = 0; x < W; x++)
 		{
 			if (can[x][0]) add(S, cmpr(x, 0, 0));
 			if (can[x][H - 1]) add(cmpr(x, H - 1, 1), T);
 		}
 		
 		int answer = 0;
 		while (true)
 		{
 			for (int i = 0; i < nn; i++) d[i] = inf;
 			d[S] = 0;
 			while (!q.empty()) q.pop();
 			q.push(S);
 			while (!q.empty())
 			{
 				int cur = q.front();
 				q.pop();
 				for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i].f < gr[cur][i].maxf && d[gr[cur][i].v] > d[cur] + 1)
 				{
 					d[gr[cur][i].v] = d[cur] + 1;
 					from[gr[cur][i].v] = gr[cur][i].o;
 					q.push(gr[cur][i].v);
 				}
 			}
 			if (d[T] == inf) break;
 			int cur = T;
 			while (cur != S)
 			{
 				int next = gr[cur][from[cur]].v;
 				int cure = gr[cur][from[cur]].o;
 				gr[cur][from[cur]].f--;
 				gr[next][cure].f++;
 				cur = next;
 			}
 			answer++;
 		}
 		
 		printf(" %d\n", answer);
 		
 // 		for (int y = (int)ys.size() - 1; y >= 0; y--)
 // 		{
 // 			for (int x = 0; x <= W; x++) cout << d[x][y] << ' ';
 // 			cout << endl;
 // 		}
 		
 		fprintf(stderr, "%d/%d cases done!\n", T_, NT);
 	}
 	return 0;
 }
