#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 
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
     // puts("");
     solve();
   }
 }
 
 
 typedef int Weight;
 struct Edge {
   int src;
   int dest;
   Weight weight;
   int index;
   int dir;
   Edge(int src, int dest, Weight weight, int index, int dir) : src(src), dest(dest), weight(weight), index(index), dir(dir) {;}
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
       cout << matrix[y][x] << " ";
       // printf("%d ", matrix[y][x]);
     }
     puts("");
   }
 }
 
 int n, m;
 Graph g;
 int anss[2010];
 bool visited[1010];
 
 void AddWeight(Edge e, int v) {
   anss[e.index] += e.dir * v;
 }
 
 int dfs(int start, int from, int prev_index, int max_v) {
   if (start == from) { return max_v + 1; }
   if (visited[from]) { return 0; }
   visited[from] = true;
   int cap[2] = { 0, n * n };
   REP(iter, 2) {
     FORIT(it, g[from]) {
       if (it->index == prev_index) { continue; }
       if (abs(anss[it->index]) > cap[iter]) { continue; }
       int nmax_v = max(max_v, abs(anss[it->index]));
       int nret = dfs(start, it->dest, it->index, nmax_v);
       if (nret == 0) { continue; }
       AddWeight(*it, nret);
       return nret;
     }
   }
   return 0;
 }
 
 void solve() {
   MEMSET(visited, false);
   MEMSET(anss, 0);
   scanf("%d %d", &n, &m);
   g = Graph(n);
   REP(i, m) {
     int f, t;
     scanf("%d %d", &f, &t);
     f--; t--;
     g[f].push_back(Edge(f, t, 0, i, 1));
     g[t].push_back(Edge(t, f, 0, i, -1));
   }
   REP(i, n) {
     FORIT(it, g[i]) {
       if (anss[it->index] != 0) { continue; }
       MEMSET(visited, false);
       int ans = dfs(i, it->dest, it->index, 0);
       if (ans == 0) { goto ng; }
       AddWeight(*it, ans);
     }
   }
   REP(i, m) {
     if (i != 0) { putchar(' '); }
     printf("%d", anss[i]);
     assert(anss[i] <= n * n);
   }
   puts("");
   return;
 ng:;
    puts("IMPOSSIBLE");
 }
