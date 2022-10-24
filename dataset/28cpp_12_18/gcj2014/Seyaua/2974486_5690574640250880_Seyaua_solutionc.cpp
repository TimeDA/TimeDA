#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <bitset>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <ctime>
 #pragma comment(linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 6;
 char a[maxN][maxN];
 int total[maxN][maxN];
 int used[maxN][maxN];
 
 int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
 int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
 int r, c, m;
 
 bool is_in(int x, int y) {
   return x >= 0 && x < r && y >= 0 && y < c;
 }
 
 int cnt;
 
 void dfs(int x, int y) {
   if (!is_in(x, y)) {
     return;
   }
   if (used[x][y]) {
     return;
   }
   ++cnt;
   used[x][y] = 1;
   if (total[x][y] == 0) {
     for (int i = 0; i < 8; ++i) {
       dfs(x + dx[i], y + dy[i]);
     }
   }
 }
 
 void solve(int tcase) {
   printf("Case #%d:\n", tcase);
 
   scanf("%d%d%d", &r, &c, &m);
 
   for (int i = 0; i < r; ++i) {
     for (int j = 0; j < c; ++j) {
       a[i][j] = '*';
     }
   }
 
   queue <pair<int, int> > q;
   q.push(make_pair(0, 0));
   a[0][0] = 'c';
 
   int tot = r * c - m - 1;
 
   while (!q.empty() && tot > 0) {
     pair<int, int> cur = q.front();
     q.pop();
 
     int cx = cur.first, cy = cur.second;
 
     for (int i = 0; i < 8; ++i) {
       int nx = cx + dx[i], ny = cy + dy[i];
       if (is_in(nx, ny) && a[nx][ny] == '*' && tot > 0) {
         --tot;
         q.push(make_pair(nx, ny));
         a[nx][ny] = '.';
       }
     }
   }
   memset(total, 0, sizeof(total));
   for (int i = 0; i < r; ++i) {
     for (int j = 0; j < c; ++j) {
       if (a[i][j] != '*') {
         for (int k = 0; k < 8; ++k) {
           if (is_in(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] == '*') {
             ++total[i][j];
           }
         }
       }
     }
   }
   memset(used, 0, sizeof(used));
   cnt = 0;
   dfs(0, 0);
   if (cnt == r * c - m) {
     for (int i = 0; i < r; ++i) {
       for (int j = 0; j < c; ++j) {
         printf("%c", a[i][j]);
       }
       printf("\n");
     }
     return;
   } else {
     for (int mask = 0; mask < (1 << (r * c)); ++mask) {
       int bt = 0;
       for (int i = 0; i < (r * c); ++i) {
         if (mask & (1 << i)) {
           ++bt;
         }
       }
       if (bt != m) continue;
       for (int i = 0; i < r; ++i) {
         for (int j = 0; j < c; ++j) {
           int num = i * c + j;
           if (mask & (1 << num)) {
             a[i][j] = '*';
           } else {
             a[i][j] = '.';
           }
         }
       }
 
       memset(total, 0, sizeof(total));
       for (int i = 0; i < r; ++i) {
         for (int j = 0; j < c; ++j) {
           if (a[i][j] != '*') {
             for (int k = 0; k < 8; ++k) {
               if (is_in(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] == '*') {
                 ++total[i][j];
               }
             }
           }
         }
       }
 
       for (int i = 0; i < r; ++i) {
         for (int j = 0; j < c; ++j) {
           if (a[i][j] == '*') continue;
           memset(used, 0, sizeof(used));
           cnt = 0;
           dfs(i, j);
           if (cnt == r * c - m) {
             a[i][j] = 'c';
             for (int i = 0; i < r; ++i) {
               for (int j = 0; j < c; ++j) {
                 printf("%c", a[i][j]);
               }
               printf("\n");
             }
             return;
           }
         }
       }
     }
   }
   printf("Impossible\n");
 }
 
 int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
 
   int t;
   scanf("%d", &t);
 
   for (int i = 0; i < t; ++i) {
     cerr << i << endl;
     solve(i + 1);
   }
 
   return 0;
 }
