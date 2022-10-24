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
     solve();
   }
 }
 
 typedef int Weight;
 struct Edge {
   int src;
   int dest;
   Weight weight;
   Edge(int src, int dest, Weight weight) : src(src), dest(dest), weight(weight) {;}
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
 
 void SccDfs(const Graph &g, int from, vector<int> &visit, vector<int> &st) {
   visit[from] = 1;
   for (Edges::const_iterator it = g[from].begin(); it != g[from].end(); it++) {
     if (visit[it->dest]) { continue; }
     SccDfs(g, it->dest, visit, st);
   }
   st.push_back(from);
 }
 
 vector<vector<int> > Scc(const Graph &g) {
   const int n = g.size();
   vector<vector<int> > ret;
   Graph revg(n);
   for (int i = 0; i < n; i++) {
     for (Edges::const_iterator it = g[i].begin(); it != g[i].end(); it++) {
       revg[it->dest].push_back(Edge(it->dest, i, it->weight));
     }
   }
   vector<int> st;
   vector<int> visit(n, 0);
   for (int i = 0; i < n; i++) {
     if (visit[i]) { continue; }
     SccDfs(g, i, visit, st);
   }
   visit = vector<int>(n, 0);
   for (int i = n - 1; i >= 0; i--) {
     int index = st[i];
     if (visit[index]) { continue; }
     vector<int> nret;
     SccDfs(revg, index, visit, nret);
     ret.push_back(nret);
   }
   return ret;
 }
 
 void MakeMatrix(int n, int matrix[2010][2010], int a[2010], int rev) {
   REP(target, n) {
     int postNumPos = -1;
     int targetNumPos = -1;
     int start = rev ? 0 : n - 1;
     int dir = rev ? 1 : -1;
     for (int i = start; 0 <= i && i < n; i += dir) {
       if (a[i] == target - 1) {
         postNumPos = i;
       } else if (a[i] == target) {
         if (postNumPos != -1) { matrix[i][postNumPos] = 1; } // X[i] > X[post]
         if (targetNumPos != -1) { matrix[targetNumPos][i] = 1; } // X[post] > X[i] 
         targetNumPos = i;
       }
     }
   }
 }
 
 int n;
 int a[2010];
 int b[2010];
 int matrix[2010][2010];
 
 void solve() {
   MEMSET(matrix, 0);
   scanf("%d", &n);
   REP(i, n) { scanf("%d", &a[i]); a[i]--; }
   REP(i, n) { scanf("%d", &b[i]); b[i]--; }
   MakeMatrix(n, matrix, a, 1);
   MakeMatrix(n, matrix, b, 0);
   REP(k, n) REP(i, n) REP(j, n) {
     matrix[i][j] |= matrix[i][k] && matrix[k][j];
   }
   Graph g(n);
   REP(i, n) REP(j, n) {
     if (matrix[i][j]) { g[i].push_back(Edge(i, j, 0)); }
   }
   vector<vector<int> > order = Scc(g);
   assert((int)order.size() == n);
   reverse(order.begin(), order.end());
   vector<int> ans(n);
   int index = 0;
   FORIT(it, order) { ans[(*it)[0]] = index++; }
   REP(i, n) {
     if (i != 0) { putchar(' '); }
     printf("%d", ans[i] + 1);
   }
   puts("");
 }
