#include <cstdio>
 #include <iostream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <cstring>
 
 using namespace std;
 
 struct Edge {
 	int to, capacity;
 	explicit Edge(int to = 0, int capacity = 0) :
 		to(to), capacity(capacity)
 	{ }
 };
 
 struct MaximumFlowEdge {
 	int to;
 	int capacity;
 	int rev;
 	explicit MaximumFlowEdge(int to = 0, int capacity = 0, int rev = 0) :
 		to(to), capacity(capacity), rev(rev)
 	{ }
 };
 
 template <typename EDGE_TYPE>
 int maximum_flow_dinic(
 	int source, int sink, const vector< vector<EDGE_TYPE> > &conn)
 {
 	typedef MaximumFlowEdge MFEdge;
 	const int INF = 1000000000;
 	// Convert graph format
 	const int n = conn.size();
 	vector< vector<MFEdge> > iconn(n);
 	for(int i = 0; i < n; ++i){
 		for(int j = 0; j < conn[i].size(); ++j){
 			const int to = conn[i][j].to;
 			const int cap = conn[i][j].capacity;
 			iconn[i].push_back(MFEdge(to, cap, iconn[to].size()));
 			iconn[to].push_back(MFEdge(i, 0, iconn[i].size() - 1));
 		}
 	}
 	// DFS function
 	struct {
 		typedef MaximumFlowEdge MFEdge;
 		int operator()(
 			int v, int sink, int f, const vector<int> &level,
 			vector<int> &iter, vector< vector<MFEdge> > &conn)
 		{
 			if(v == sink){ return f; }
 			for(; iter[v] < conn[v].size(); ++iter[v]){
 				MFEdge &e = conn[v][iter[v]];
 				if(e.capacity > 0 && level[v] < level[e.to]){
 					int d = (*this)(
 						e.to, sink, min(f, e.capacity), level, iter, conn);
 					if(d > 0){
 						e.capacity -= d;
 						conn[e.to][e.rev].capacity += d;
 						return d;
 					}
 				}
 			}
 			return 0;
 		}
 	} dinic_dfs;
 	// Dinic
 	int flow = 0;
 	while(true){
 		vector<int> level(n, -1);
 		queue<int> q;
 		level[source] = 0;
 		q.push(source);
 		while(!q.empty()){
 			const int v = q.front();
 			q.pop();
 			for(int i = 0; i < iconn[v].size(); ++i){
 				const MFEdge &e = iconn[v][i];
 				if(e.capacity > 0 && level[e.to] < 0){
 					level[e.to] = level[v] + 1;
 					q.push(e.to);
 				}
 			}
 		}
 		if(level[sink] < 0){ break; }
 		vector<int> iter(n, 0);
 		while(true){
 			const int f = dinic_dfs(
 				source, sink, INF, level, iter, iconn);
 			if(f <= 0){ break; }
 			flow += f;
 		}
 	}
 	return flow;
 }
 
 struct Rect {
 	int x0, y0, x1, y1;
 };
 int grid[503][103];
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		int w, h, n;
 		cin >> w >> h >> n;
 		vector<Rect> blocks(n);
 		vector<int> comp;
 		for(int i = 0; i < n; ++i){
 			Rect &r = blocks[i];
 			cin >> r.x0 >> r.y0 >> r.x1 >> r.y1;
 			++r.x1; ++r.y1;
 		}
 		memset(grid, 0, sizeof(grid));
 		for(int i = 0; i < n; ++i){
 			const Rect &r = blocks[i];
 			--grid[r.y0][r.x0];
 			++grid[r.y0][r.x1];
 			++grid[r.y1][r.x0];
 			--grid[r.y1][r.x1];
 		}
 		for(int i = 0; i < h; ++i){
 			for(int j = 0, s = 0; j < w; ++j){
 				s += grid[i][j];
 				grid[i][j] = s;
 			}
 		}
 		for(int j = 0; j < w; ++j){
 			for(int i = 0, s = 0; i < h; ++i){
 				s += grid[i][j];
 				grid[i][j] = s;
 			}
 		}
 		int color = 0;
 		for(int i = 0; i < h; ++i){
 			for(int j = 0; j < w; ++j){
 				if(grid[i][j] < 0){ continue; }
 				grid[i][j] = color++;
 			}
 		}
 		const int source = color * 2, sink = source + 1;
 		vector< vector<Edge> > conn(color * 2 + 2);
 		for(int i = 0; i < h; ++i){
 			for(int j = 0; j < w; ++j){
 				if(grid[i][j] < 0){ continue; }
 				const int a = grid[i][j] * 2, b = a + 1;
 				conn[a].push_back(Edge(b, 1));
 				if(i + 1 < h && grid[i + 1][j] >= 0){
 					const int s = grid[i + 1][j] * 2, t = s + 1;
 					conn[b].push_back(Edge(s, 1));
 					conn[t].push_back(Edge(a, 1));
 				}
 				if(j + 1 < w && grid[i][j + 1] >= 0){
 					const int s = grid[i][j + 1] * 2, t = s + 1;
 					conn[b].push_back(Edge(s, 1));
 					conn[t].push_back(Edge(a, 1));
 				}
 			}
 		}
 		for(int i = 0; i < w; ++i){
 			if(grid[0][i] >= 0){
 				const int a = grid[0][i] * 2;
 				conn[source].push_back(Edge(a, 1));
 			}
 			if(grid[h - 1][i] >= 0){
 				const int b = grid[h - 1][i] * 2 + 1;
 				conn[b].push_back(Edge(sink, 1));
 			}
 		}
 		const int answer = maximum_flow_dinic(source, sink, conn);
 		cout << "Case #" << caseNum << ": " << answer << endl;
 	}
 	return 0;
 }
 
