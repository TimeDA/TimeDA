#ifdef DBG1
   #define _GLIBCXX_DEBUG
 #endif
 
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <algorithm>
 #include <map>
 #include <set>
 
 #ifdef DBG1
     #define dbg(...) fprintf(stderr, __VA_ARGS__)
 #else
     #define dbg(...)
 #endif
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair <int, int> pii;
 
 const int N = 100;
 int n, m;
 char s[N][N];
 bool used[4][N][N];
 vector <vector<int>> cover;
 vector <vector<int>> ed;
 vector <vector<int>> revEd;
               //  R  D  L  U
 const int dx[] = {0, 1, 0, -1};
 const int dy[] = {1, 0, -1, 0};
 
 bool isMap(int x, int y) {
   return (0 <= x && x < n && 0 <= y && y < m);
 }
 
 const int dirs1[] = {3, 2, 1, 0};
 const int dirs2[] = {1, 0, 3, 2};
 
 int getNewDir(int x, int y, int dir) {
   if (s[x][y] == '.') return dir;
   if (s[x][y] == '/') return dirs1[dir];
   if (s[x][y] == '\\') return dirs2[dir];
   dbg("x %d y %d dir %d\n", x, y, dir);
   assert(0);
 }
 
 bool isGood(int x, int y, int dir) {
   bool first = true;
   while (1) {
     if (!first) {
       if (!isMap(x, y)) break;
       if (used[dir^2][x][y]) break;
       used[dir^2][x][y] = true;
       if (s[x][y] == '-' || s[x][y] == '|') {
         return false;
       }
       if (s[x][y] == '#') break;
       int newDir = getNewDir(x, y, dir);
       dir = newDir;
     }
     if (used[dir][x][y]) break;
     used[dir][x][y] = true;
     x += dx[dir];
     y += dy[dir];
     first = false;
   }
   return true;
 }
 
 bool isGood(int x, int y, char z) {
   memset(used, 0, sizeof(used));
   bool ok;
   int num = (x * m + y) * 2;
   if (z == '-') {
     ok = isGood(x, y, 0) && isGood(x, y, 2);
   } else {
     num ++;
     ok = isGood(x, y, 1) && isGood(x, y, 3);
   }
   if (ok) {
     for (int i = 0; i < n; ++i) {
       for (int j = 0; j < m; ++j) {
         if (s[i][j] == '#') { continue; }
         bool cur = false;
         for (int k = 0; k < 4; ++k) {
           cur |= used[k][i][j];
         }
         if (cur) {
           cover[i * m + j].push_back(num);
         }
       }
     }
   }
   return ok;
 }
 
 void dfs(int s, const vector <vector<int>> & ed, vector <int> & used, vector <int> & topsort, int col) {
   if (used[s] != -1) {
     return;
   }
   used[s] = col;
   for (int x : ed[s]) {
     dfs(x, ed, used, topsort, col);
   }
   topsort.push_back(s);
 }
 
 void addEdge2(int x, int y) {
   ed[x].push_back(y);
   revEd[y].push_back(x);
 }
 
 void addEdge(int x, int y) {
   dbg("%d => %d\n", x, y);
   addEdge2(x, y);
   addEdge2(y^1, x^1);
 }
 
 void solve() {
   scanf("%d%d", &n, &m);
   for (int i = 0; i < n; ++i) {
     scanf("%s", s[i]);
   }
   cover.clear();
   cover.resize(n * m);
   ed.clear();
   ed.resize(n * m * 2);
   revEd.clear();
   revEd.resize(n * m * 2);
 
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (s[i][j] == '|' || s[i][j] == '-') {
         bool ok1 = isGood(i, j, '-');
         bool ok2 = isGood(i, j, '|');
         dbg("x %d y %d ok1 %d ok2 %d\n", i, j, ok1, ok2);
         if (!ok1 && !ok2) {
           printf("IMPOSSIBLE\n");
           return;
         }
         if (ok1 && ok2) {
           // nothing
         } else if (ok1) {
           addEdge((i * m + j) * 2 + 1, (i * m + j) * 2 + 0);
           s[i][j] = '-';
         } else {
           addEdge((i * m + j) * 2 + 0, (i * m + j) * 2 + 1);
           s[i][j] = '|';
         }
       }
     }
   }
   dbg("tracing end\n");
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < m; ++j) {
       if (s[i][j] == '#') { continue; }
       int num = i * m + j;
       assert(cover[num].size() <= 2);
       switch (cover[num].size()) {
         case 0: {
           printf("IMPOSSIBLE\n");
           return;
         }
         case 1: {
           addEdge(cover[num][0] ^ 1, cover[num][0]);
         }
         break;
         case 2: {
           addEdge(cover[num][0] ^ 1, cover[num][1]);
           addEdge(cover[num][1] ^ 1, cover[num][0]);
         }
         break;
       }
     }
   }
   dbg("graph built\n");
   vector <int> topsort;
   vector <int> used(n * m * 2, -1);
   for (int i = 0; i < n * m * 2; ++i) {
     if (used[i] == -1) {
       dfs(i, ed, used, topsort, 1);
     }
   }
   vector <int> comp(n * m * 2, -1);
   int cnt = 0;
   reverse(topsort.begin(), topsort.end());
   for (int v : topsort) {
     if (used[v] != -1) {
       vector<int> tmp;
       dfs(v, revEd, comp, tmp, cnt++);
     }
   }
   for (int i = 0; i < n * m * 2; i += 2) {
     if (comp[i] == comp[i ^ 1]) {
       printf("IMPOSSIBLE\n");
       return;
     }
     int x = (i / 2) / m;
     int y = (i / 2) % m;
     if (!(s[x][y] == '-' || s[x][y] == '|')) { continue; }
     if (comp[i] > comp[i ^ 1]) {
       s[x][y] = '-';
     } else {
       s[x][y] = '|';
     }
   }
   printf("POSSIBLE\n");
   for (int i = 0; i < n; ++i) {
     printf("%s\n", s[i]);
   }
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
 //    dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     fflush(stdout);
   }
   return 0;
 }
