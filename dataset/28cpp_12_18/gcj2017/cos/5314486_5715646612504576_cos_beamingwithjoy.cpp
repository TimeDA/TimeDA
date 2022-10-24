#include <stdio.h>
 #include <string.h>
 #include <algorithm>
 #include <iostream>
 #include <math.h>
 #include <assert.h>
 #include <vector>
 #include <map>
 
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
       cout << matrix[y][x] << " ";
       // printf("%d ", matrix[y][x]);
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
 
 int h, w;
 char field[100][100];
 vector<pair<int, int> > beam[110][110];
 vector<int> usable[2];
 Graph g;
 int posx[200];
 int posy[200];
 
 int simulate(int x, int y, int dir, int index, int original_dir) {
   const int dx[4] = { 1, 0, -1, 0 };
   const int dy[4] = { 0, 1, 0, -1 };
   int nx = x + dx[dir];
   int ny = y + dy[dir];
   if (nx < 0 || nx >= w || ny < 0 || ny >= h) { return 1; }
   if (field[ny][nx] == '#') { return 1; }
   if (field[ny][nx] == '-' || field[ny][nx] == '|') { return 0; }
   int ndir = dir;
   if (field[ny][nx] == '/') {
     if (dir == 0) { ndir = 3; }
     else if (dir == 1) { ndir = 2; }
     else if (dir == 2) { ndir = 1; }
     else if (dir == 3) { ndir = 0; }
   }
   if (field[ny][nx] == '\\') {
     if (dir == 0) { ndir = 1; }
     else if (dir == 1) { ndir = 0; }
     else if (dir == 2) { ndir = 3; }
     else if (dir == 3) { ndir = 2; }
   }
   // cout << ny << " " << nx << " " << index << " " << original_dir << endl;
   bool ret = simulate(nx, ny, ndir, index, original_dir);
   if (ret) { beam[ny][nx].push_back(make_pair(index, original_dir)); }
   return ret;
 }
 
 int HORIZON(int i) { return 2 * i + 0; }
 int VERTICAL(int i) { return 2 * i + 1; }
 void AddEdge(int i, int j) {
   g[i].push_back(Edge(i, j, 0));
   // cout << i << " " << j << endl;
 }
 
 void solve() {
   REP(y, 110) REP(x, 110) { beam[y][x].clear(); }
   REP(i, 2) { usable[i].clear(); }
   g.clear();
   MEMSET(posx, -1);
   MEMSET(posy, -1);
   scanf("%d %d", &h, &w);
   REP(y, h) {
     scanf("%s", field[y]);
   }
   int cnt = 0;
   REP(y, h) {
     REP(x, w) {
       if (field[y][x] == '-' || field[y][x] == '|') {
         posx[cnt] = x;
         posy[cnt] = y;
         usable[0].push_back(1);
         usable[1].push_back(1);
         REP(dir, 4) {
           usable[dir % 2][cnt] &= simulate(x, y, dir, cnt, dir % 2);
         }
         cnt++;
       }
     }
   }
   g = Graph(2 * cnt);
   {
     REP(i, cnt) {
       if (usable[0][i] == 0 && usable[1][i] == 0) { goto ng; }
       if (usable[0][i] == 0) { AddEdge(HORIZON(i), VERTICAL(i)); }
       if (usable[1][i] == 0) { AddEdge(VERTICAL(i), HORIZON(i)); }
     }
     REP(y, h) {
       REP(x, w) {
         if (field[y][x] == '.') {
           vector<pair<int, int> > source = beam[y][x];
           if (source.size() == 0) { goto ng; }
           if (source.size() == 1) {
             int index = source[0].first;
             int original_dir = source[0].second;
             AddEdge(index * 2 + (original_dir ^ 1), index * 2 + original_dir);
           } else {
             REP(i, 2) {
               int index1 = source[i].first;
               int original_dir1 = source[i].second;
               int index2 = source[i ^ 1].first;
               int original_dir2 = source[i ^ 1].second;
               AddEdge(index1 * 2 + (original_dir1 ^ 1), index2 * 2 + original_dir2);
               // cout << index1 << " " << original_dir1 << " " << index2 << " " << original_dir2 << endl;
             }
           }
         }
       }
     }
     vector<vector<int> > scc = Scc(g);
     map<int, int> used;
     REP(i, scc.size()) {
       REP(j, scc[i].size()) {
         int index = scc[i][j] / 2;
         int original_dir = scc[i][j] % 2;
         // cout << i << " " << scc[i][j] << " " << index << " " << original_dir << endl;
         if (used.count(index)) {
           if (used[index] == i) { goto ng; }
           assert(used[index] < i);
           // continue;
         }
         int c = original_dir == 0 ? '-' : '|';
         field[posy[index]][posx[index]] = c;
         used[index] = i;
       }
     }
     puts("POSSIBLE");
     REP(y, h) {
       printf("%s\n", field[y]);
     }
   }
   return;
 ng:
   puts("IMPOSSIBLE");
   return;
 }
