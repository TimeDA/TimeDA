#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 struct Event{
     int bx, ex, type;
     Event(int a, int b, int c) : 
         bx(a), ex(b), type(c) {}
     bool operator < (const Event& e) const {
         return make_tuple(type, bx, ex) < make_tuple(e.type, e.bx, e.ex);
     }
 };
 const int INF = 100000000;
 struct Dinic{
     struct Edge{
         int dst, cap, rev;
         Edge(){}
         Edge(int d, int c, int r) :
             dst(d), cap(c), rev(r) {}
     };
     typedef vector<Edge> Node;
     typedef vector<Node> Graph;
 
     Graph G;
     vector<int> level;
     vector<int> iter;
 
     void bfs(int s){
         level.assign(G.size(), -1);
         queue<int> que;
         que.push(s);
         level[s] = 0;
         while(!que.empty()){
             int v = que.front(); que.pop();
             for(const auto& e : G[v]){
                 if(e.cap > 0 && level[e.dst] < 0){
                     level[e.dst] = level[v] + 1;
                     que.push(e.dst);
                 }
             }
         }
     }
 
     int dfs(int v, int t, int f){
         if(v == t) return f;
         for(int& i = iter[v]; i < G[v].size(); i++){
             Edge& e = G[v][i];
             if(e.cap > 0 && level[v] < level[e.dst]){
                 int d = dfs(e.dst, t, min(f, e.cap));
                 if(d > 0){
                     e.cap -= d;
                     G[e.dst][e.rev].cap += d;
                     return d;
                 }
             }
         }
         return 0;
     }
 
     Dinic(int N) : G(N), level(N), iter(N) {}
 
     void add_edge(int src, int dst, int cap){
         G[src].push_back(Edge(dst, cap, G[dst].size()));
         G[dst].push_back(Edge(src, 0, G[src].size() - 1));
     }
 
     int max_flow(int src, int dst){
         int flow = 0;
         while(true){
             bfs(src);
             if(level[dst] < 0) break;
             iter.assign(G.size(), 0);
             while(true){
                 int f = dfs(src, dst, INF);
                 if(f <= 0) break;
                 flow += f;
             }
         }
         return flow;
     }
 };
 
 int solve(int grid[1010][1010], int w, int h) {
     int V = 0;
     static int node[1010][1010] = {};
     memset(node, -1, sizeof(node));
     REP(y, h) REP(x, w) {
         if(grid[y][x] == 0) {
             node[y][x] = V++;
         }
     }
     Dinic solver(V * 2 + 2);
     const int SRC = V * 2;
     const int DST = SRC + 1;
     REP(i, V) {
         solver.add_edge(2 * i, 2 * i + 1, 1);
     }
     REP(x, w) {
         int k = node[0][x];
         if(k >= 0) {
             solver.add_edge(SRC, 2 * k, 1);
         }
     }
     REP(x, w) {
         int k = node[h - 1][x];
         if(k >= 0) {
             solver.add_edge(2 * k + 1, DST, 1);
         }
     }
     int dx[4] = {1, 0, -1, 0};
     int dy[4] = {0, 1, 0, -1};
     REP(y, h) REP(x, w) if(node[y][x] >= 0) REP(r, 4) {
         int nx = x + dx[r];
         int ny = y + dy[r];
         if(!(0 <= nx && nx < w)) continue;
         if(!(0 <= ny && ny < h)) continue;
         if(node[ny][nx] == -1) continue;
         int u = node[y][x];
         int v = node[ny][nx];
         solver.add_edge(2 * u + 1, 2 * v, 1);
     }
     return solver.max_flow(SRC, DST);
 }
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++) {
         printf("Case #%d: ", casenum);
         int W, H;
         cin >> W >> H;
         int B;
         cin >> B;
         map<int, deque<Event>> m;
         m[0].push_back(Event(0, -1, 0));
         m[H - 1].push_back(Event(0, -1, 0));
         int grid[1010][1010] = {};
         int grid2[1010][1010] = {};
         REP(i, B) {
             int x1, y1, x2, y2;
             cin >> x1 >> y1 >> x2 >> y2;
             m[y1].push_back(Event(x1, x2, 1));
             if(y2 + 1 < H) {
                 m[y2 + 1].push_front(Event(x1, x2, 0));
             }
             ///---
             for(int y = y1; y <= y2; y++) {
                 for(int x = x1; x <= x2; x++) {
                     grid2[y][x] = 1;
                 }
             }
         }
         int w = W;
         int h = 0;
         {
             int cur[1010] = {};
             for(const auto& p : m) {
                 for(const Event& e : p.second) {
                     for(int x = e.bx; x <= e.ex; x++) {
                         if(e.type == 1) {
                             assert(cur[x] == 0);
                             cur[x] = 1;
                         } else {
                             assert(cur[x] == 1);
                             cur[x] = 0;
                         }
                     }
                 }
                 for(int x = 0; x < W; x++) {
                     grid[h][x] = cur[x];
                 }
                 h++;
             }
         }
         int ans1 = solve(grid, w, h);
         int ans2 = solve(grid2, W, H);
         if(ans1 != ans2 && false) {
             REP(y, h) {
                 REP(x, w) {
                     cout << grid[y][x] << " ";
                 }
                 cout << endl;
             }
         }
         cout << ans2 << endl;
     }
     return 0;
 }
 
