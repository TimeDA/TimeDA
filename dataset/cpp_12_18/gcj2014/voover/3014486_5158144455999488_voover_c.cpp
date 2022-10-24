#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cmath>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <complex>
 #include <sstream>
 using namespace std;
  
 typedef long long LL;
 typedef unsigned long long ULL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
 #define ALL(v) (v).begin(), (v).end()
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 int W,H,N;
 
 #define NODE(i,j) 2 * (W * j + i)
 #define COORDS(v) PII((v / 2) % W, (v/2) / W) 
 
 namespace flow {
 
 class FlowNetwork {
   struct Edge {
     int v;
     int cap;
     int flow;
     Edge* back;
     Edge(int _v, int _cap): v(_v), cap(_cap), flow(0) {}
   };
   
   /** Input */
   int N;
   vector<list<Edge>> adj;
 
   /** Helpers */
   int S, T;
   vector<LL> extra;
   queue<int> unprocessed;
   vector<int> height; // height[S] = N, height[T] = 0, always
   int raises;
 
   private:
   void _push(Edge& e, int f) {
     if (e.v != S && e.v != T && extra[e.v] == 0 && f > 0) {
       unprocessed.push(e.v);
     }
   
     e.flow += f;
     e.back->flow -= f;
     extra[e.v] += f;
     extra[e.back->v] -= f;
   }
 
   void _raise(int u) {
     height[u] = 2 * N;
     for (Edge& e : adj[u]) {
       if (e.flow < e.cap) height[u] = min(height[u], height[e.v] + 1);
     }
     ++raises;
   }
 
   void _bfs(int s, vector<bool>& visited) {
     queue<int> Q;
     Q.push(s);
     while (!Q.empty()) {
       int u = Q.front();
       Q.pop();
       for (Edge& e : adj[u]) {
         if (!visited[e.v] && e.back->flow < e.back->cap) {
           height[e.v] = height[u] + 1;
           visited[e.v] = true;
           Q.push(e.v);
         }
       }
     }
   }
 
   void _relabel() {
     vector<bool> visited(N);
     visited[S] = visited[T] = true;
     _bfs(T, visited);
     _bfs(S, visited);
   }
   
   void _process(int u) {
     while (extra[u] > 0) {
       for (Edge& e : adj[u]) {
         if (e.flow == e.cap || height[e.v] != height[u] - 1) continue;
         _push(e, min(extra[u], (LL)(e.cap - e.flow)));
         if (!extra[u]) return;
       }
       if (raises >= N / 2) {
         raises = 0;
         _relabel();
       } else {
         _raise(u);
       }
     }
   }
 
   public:
   FlowNetwork(int _N): N(_N) {
     adj = vector<list<Edge>>(N);
 
     extra = vector<LL>(N);
     height = vector<int>(N);
   }
 
   void addEdge(int u, int v, int cap) {
     adj[u].push_back(Edge(v,cap));
     adj[v].push_back(Edge(u,0));
     adj[u].back().back = &adj[v].back();
     adj[v].back().back = &adj[u].back();
   }
   
   LL computeFlow(int s, int t) {
     S = s; T = t;
     for (Edge& e: adj[S]) {
       _push(e, e.cap);
     }
     
     REP(i,N) height[i] = 0;
     height[S] = N;
     raises = 0;
     
     while (!unprocessed.empty()) {
       int v = unprocessed.front();
       unprocessed.pop();
       _process(v);
     }
     
     return extra[T];
   }
 };
 
 }
 
 
 int B[10000][4];
 
 bool G[2000][5000];
 
 void scase() {
   scanf("%d%d%d",&W,&H,&N);
   REP(i,N)REP(j,4) scanf("%d", &B[i][j]);
   set<int> S;
   REP(i,N) {
     B[i][3]++;
     S.insert(B[i][1]);
     S.insert(B[i][3]);
   }
   /*
   S.insert(0);
   S.insert(H);
   S.insert(H-1);
   map<int,int> M;
   int m = 0;
   FOREACH(it,S) M[*it] = m++; 
   REP(i,N) {
     B[i][1] = M[B[i][1]];
     B[i][3] = M[B[i][3]];
   }
   H = M[H];
   */
   REP(i,W) REP(j,H) G[i][j] = true;
   REP(i,N) FOR(a, B[i][0], B[i][2] + 1) FOR(b, B[i][1], B[i][3]) G[a][b] = false;
   
   int s = 2 * W * H;
   int t = 2 * W * H + 1;
   
   flow::FlowNetwork net(t + 1);
   REP(i,W)REP(j,H) if (G[i][j]) {
     net.addEdge(NODE(i,j), NODE(i,j)+1, 1);
     if (j == 0) net.addEdge(s, NODE(i,j), 1);
     if (j == H-1) net.addEdge(NODE(i,j) + 1, t, 1);
   }
   
   REP(i,W)REP(j,H) {
     if (!G[i][j]) continue;
     for (int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) {
       if (abs(di + dj) != 1) continue;
       int i2 = i + di;
       int j2 = j + dj;
       if (j2 < 0 || j2 >= H || i2 < 0 || i2 >= W || !G[i2][j2]) continue;
       net.addEdge(NODE(i,j) + 1, NODE(i2,j2), 1);
     }
   }
   /*
   printf("\n");
   FORD(j,H,0) {
     REP(i,W) {
       printf(G[i][j] ? "#" : ".");
     }
     printf("\n");
   }
   */
   int result = net.computeFlow(s, t);
   printf("%d\n", result);
 }
 
 int main() {
   int Z;
   scanf("%d", &Z);
   REP(z,Z) {
     printf("Case #%d: ", z+1);
     scase();
   }
 }    
