#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <queue>
 #include <set>
 
 using namespace std;
 typedef long long ll;
 typedef unsigned int uint;
 typedef unsigned long long ull;
 static const double EPS = 1e-9;
 static const double PI = acos(-1.0);
 
 #define REP(i, n) for (int i = 0; i < (int)(n); i++)
 #define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
 #define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
 #define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
 #define MEMSET(v, h) memset((v), h, sizeof(v))
 
 void solve();
 int main() {
   int test;
   scanf("%d", &test);
   char str[1000];
   fgets(str, 999, stdin);
   int test_case = 0;
   while (test--) {
     test_case++;
     printf("Case #%d: ", test_case);
     solve();
   }
 }
 
 
 typedef ll Weight;
 struct Edge {
   int src;
   int dest;
   Weight weight;
   Edge(int src, int dest, Weight weight)
     : src(src), dest(dest), weight(weight) {;}
   bool operator<(const Edge &rhs) const {
     if (weight != rhs.weight) { return weight > rhs.weight; }
     if (src != rhs.src) { return src < rhs.src; }
     return dest < rhs.dest;
   }
 };
 typedef vector<Edge> Edges;
 typedef vector<Edges> Graph;
 typedef vector<Weight> Array;
 typedef vector<Array> Matrix;
 
 Weight Dijkstra(const Graph &g, int s, int t) {
   const int n = g.size();
   vector<bool> visit(n, false);
   Array dist(n, 2000000000000000LL);
   priority_queue<Edge> que;
   que.push(Edge(s, s, 0));
   Weight ans = -1;
   dist[s] = 0;
   while (!que.empty()) {
     Edge edge = que.top();
     que.pop();
     int from = edge.dest;
     if (visit[from]) { continue; }
     visit[from] = true;
     if (from == t) {
       ans = edge.weight;
       break;
     }   
     for (int i = 0; i < (int)g[from].size(); i++) {
       int to = g[from][i].dest;
       Weight ncost = edge.weight + g[from][i].weight;
       if (visit[to] || ncost >= dist[to]) { continue; }
       dist[to] = ncost;
       que.push(Edge(from, to, ncost));
     }   
   }
   return ans;
 }
 
 
 static const Weight INF = 2000000000LL;
 vector<Weight> SPFA(const Graph &g, int s) {
   const int n = g.size();
   vector<Weight> dist = vector<Weight>(n, 1LL << 58);
   dist[s] = 0;
   vector<int> updated(n, 0);
   vector<bool> inque(n, false);
   queue<int> que;
   que.push(s);
   while (!que.empty()) {
     int from = que.front();
     que.pop();
     inque[from] = false;
     updated[from]++;
     if (updated[from] == n) {
       // exist negative cycle
       fill(dist.begin(), dist.end(), -INF);
       break;
     }
     for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
       int to = it->dest;
       Weight cost = dist[from] + it->weight;
       if (cost < dist[to]) {
         dist[to] = cost;
         if (!inque[to]) {
           que.push(to);
           inque[to] = true;
         }
       }
     }
   }
   return dist;
 }
 
 
 int n, m, p;
 set<int> used;
 int froms[3000];
 int tos[3000];
 ll lows[3000];
 ll highs[3000];
 int route[3000];
 
 void solve() {
   scanf("%d %d %d", &n, &m, &p);
   REP(i, m) {
     scanf("%d %d %lld %lld", &froms[i], &tos[i], &lows[i], &highs[i]);
     froms[i]--;
     tos[i]--;
   }
   ll candidate = 0;
   REP(i, p) {
     scanf("%d", &route[i]);
     route[i]--;
     used.insert(route[i]);
     candidate += lows[route[i]];
   }
 
   vector<ll> dists;
   ll global_ans;
   {
     Graph g(n);
     REP(i, m) {
       ll cost = highs[i];
       g[froms[i]].push_back(Edge(froms[i], tos[i], cost));
     }
     global_ans = Dijkstra(g, 0, 1);
 
     g = Graph(n);
     REP(i, m) {
       ll cost = highs[i];
       if (used.count(i)) { cost = lows[i]; }
       g[froms[i]].push_back(Edge(froms[i], tos[i], cost));
     }
     dists = SPFA(g, 0);
   }
 
   Graph g(n);
   REP(i, m) {
     g[froms[i]].push_back(Edge(froms[i], tos[i], lows[i]));
   }
   ll sum = 0;
   REP(i, p) {
     int index = route[i];
     int from = tos[index];
     sum += lows[index];
     ll ans = Dijkstra(g, from, 1) + sum;
     // {
     //   Graph ng(n);
     //   REP(i, m) {
     //     ll cost = highs[i];
     //     g[froms[i]].push_back(Edge(froms[i], tos[i], cost));
     //   }
     //   vector<ll> ndists = SPFA(g, from);
     //   REP(i, n) {
     //     dists[i] = min(ds0ts[i], ndists[i] + sum);
     //   }
     // }
     //cout << index << " " << sum << endl;
     if (ans > global_ans || sum > dists[from]) {
       printf("%d\n", index + 1);
       return;
     }
   }
   puts("Looks Good To Me");
 }
