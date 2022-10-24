#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <set>
 #include <map>
 #include <bitset>
 #include <queue>
 
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
 
 typedef int Weight;
 struct Edge {
   int index;
   int src;
   int dest;
   Weight weight;
   Edge(int index, int src, int dest, Weight weight) : index(index), src(src), dest(dest), weight(weight) {;}
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
 
 void PrintMatrix(const Matrix &matrix) {
   for (int y = 0; y < (int)matrix.size(); y++) {
     for (int x = 0; x < (int)matrix[y].size(); x++) {
       printf("%d ", matrix[y][x]);
     }
     puts("");
   }
 }
 
 Weight augment(const Graph &g, Array &capacity, const vector<int> &level, vector<bool> &finished, int from, int t, Weight cur) {
   if (from == t || cur == 0) { return cur; }
   if (finished[from]) { return 0; }
   for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
     int to = it->dest;
     if (level[to] != level[from] + 1) { continue; }
     Weight f = augment(g, capacity, level, finished, to, t, min(cur, capacity[it->index]));
     if (f > 0) {
       capacity[it->index] -= f;
       capacity[it->index^1] += f;
       return f;
     }
   }
   finished[from] = true;
   return 0;
 }
 
 // index^1 is reverse edge
 Weight MaxFlow(const Graph &g, int e, int s, int t) {
   int n = g.size();
   Array capacity(e);
   for (int from = 0; from < n; from++) {
     for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
       capacity[it->index] += it->weight;
     }
   }
   int ans = 0;
   while (true) {
     vector<int> level(n, -1);
     level[s] = 0;
     queue<int> que;
     que.push(s);
     for (int d = n; !que.empty() && level[que.front()] < d; ) {
       int from = que.front();
       que.pop();
       if (from == t) { d = level[from]; }
       for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
         int to = it->dest;
         if (capacity[it->index] > 0 && level[to] == -1) {
           que.push(to);
           level[to] = level[from] + 1;
         }
       }
     }
     vector<bool> finished(n);
     bool end = true;
     while (true) {
       Weight f = augment(g, capacity, level, finished, s, t, 2000000000LL);
       if (f == 0) { break; }
       ans += f;
       end = false;
     }
     if (end) { break; }
   }
   return ans;
 }
 
 void AddEdge(Graph &g, int &e, int from, int to, Weight capacity) {
   g[from].push_back(Edge(e++, from, to, capacity));
   g[to].push_back(Edge(e++, to, from, 0));
 }
 
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
     //puts("");
     solve();
   }
 }
 
 int w, h, m;
 bitset<1010> bits[1010];
 bool flag[1010];
 inline int IN(int x) { return 2 * x; }
 inline int OUT(int x) { return 2 * x + 1; }
 
 void solve() {
   int x0[1010];
   int x1[1010];
   int y0[1010];
   int y1[1010];
   REP(i, 1010) { bits[i].reset(); }
   MEMSET(flag, false);
 
   scanf("%d %d %d", &w, &h, &m);
   map<int, int> mapto;
   mapto[0] = 0;
   REP(i, m) {
     scanf("%d %d %d %d", &x0[i], &y0[i], &x1[i], &y1[i]);
     FOREQ(x, x0[i], x1[i]) {
       bits[i][x] = 1;
     }
     FOR(x, w, 1010) { bits[i][x] = 1; }
     y1[i]++;
     mapto[y0[i]] = 0;
     mapto[y1[i]] = 0;
   }
 
   // compress
   // {
   //   int y = 0;
   //   FORIT(it, mapto) {
   //     it->second = y++;
   //   }
   //   REP(i, m) {
   //     y0[i] = mapto[y0[i]];
   //     y1[i] = mapto[y1[i]];
   //   }
   //   h = y;
   // }
 
 
   Graph g(4);
   int e = 0;
   bitset<1010> prev;
   map<int, int> prevgMap;
   REP(x, w) {
     prevgMap[x] = 0;
   }
   FOR(x, w, 1010) {
     prev[x] = 1;
     prevgMap[x] = -1;
   }
 
   FOREQ(y, 0, h) {
     map<int, int> gMap;
 
     // make b
     bitset<1010> b;
     FOR(x, w, 1010) { b[x] = 1; }
     REP(i, m) {
       if (y0[i] == y) {
         flag[i] = true;
       } else if (y1[i] == y) {
         flag[i] = false;
       }
       if (flag[i]) { b |= bits[i]; }
     }
 
     REP(x, w + 1) {
       //putchar(b[x] ? '#' : '.');
       if (b[x] == 0) {
         if (y == h) {
           gMap[x] = g.size() / 2 - 1;
         } else {
           gMap[x] = g.size() / 2 - 1;
           g.push_back(Edges());
           g.push_back(Edges());
           AddEdge(g, e, OUT(gMap[x]), IN(gMap[x]), 1);
         }
       }
       if (x != 0 && b[x] == 0 && b[x - 1] == 0) {
         AddEdge(g, e, IN(gMap[x - 1]), OUT(gMap[x]), 1);
         AddEdge(g, e, IN(gMap[x]), OUT(gMap[x - 1]), 1);
       }
       if (b[x] == 0 && prev[x] == 0) {
         AddEdge(g, e, IN(gMap[x]), OUT(prevgMap[x]), 1);
         AddEdge(g, e, IN(prevgMap[x]), OUT(gMap[x]), 1);
       }
 
     }
     //puts("");
     prev = b;
     prevgMap = gMap;
   }
   //cout << g.size() << endl;
 
   int ans = MaxFlow(g, e, IN(0), OUT(g.size() / 2 - 1));
   cout << ans << endl;
 }
