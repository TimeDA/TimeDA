#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int N =15;
 int E[N][2];
 int to[N][2];
 int L[N][2], D[N][2];
 bool used[N][2];
 
 int n;
 
 int go(int x, int vis = 0, int curt = 0)
 {
     if (x == 0 && vis == 2 * n) {
         return curt;
     }
     int best = 1000 * 1000 * 1000;
     for (int e = 0; e < 2; e++) {
         if (used[x][e])
             continue;
         int z = curt % 24;
         int ncurt = 0;
         if (z <= L[x][e]) {
             ncurt = curt + L[x][e] - z + D[x][e];
         } else {
             ncurt = curt + L[x][e] - z + D[x][e] + 24;
         }
         used[x][e] = true;
         best = min(best, go(to[x][e], vis + 1, ncurt));
         used[x][e] = false;
     }
     return best;
 }
 
 void solve(int cs) {
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < 2; j++) {
             scanf("%d %d %d", &to[i][j], &L[i][j], &D[i][j]);
             --to[i][j];
         }
     }
     int ans = go(0);
     printf("Case #%d: %d\n", cs, ans);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
