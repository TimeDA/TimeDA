#include <cstdio>
 #include <cassert>
 #include <vector>
 using namespace std;
 
 const int N = 50500;
 const int MX = 1000 * 1000 + 42;
 vector<int> E[MX + 42];
 int used[MX];
 int rto[MX];
 int to[N];
 
 void clear() {
     for (int i = 0; i < N; i++) {
         to[i] = -1;
     }
     for (int i = 0; i < MX; i++) {
         E[i].clear();
         rto[i] = -1;
     }
 }
 
 int curver = 0;
 
 bool DFS(int x) {
     used[x] = curver;
     for (int y : E[x]) {
         if ((to[y] == -1) || (used[to[y]] != curver && DFS(to[y]))) {
             to[y] = x;
             rto[x] = y;
             return true;
         }
     }
     return false;
 }
 
 void solve(int cs) {
     clear();
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) 
     {
         for (int j = 0; j < 6; j++) {
             int x;
             scanf("%d", &x);
             E[x].push_back(i);
         }
     }
     int ans = 0;
     for (int l = 1, r = 1; l < MX; l++) {
         r = max(l, r);
         while (r != MX) {
             ++curver;
             if (DFS(r)) {
                 ++r;
             } else {
                 break;
             }
         }
         ans = max(ans, r - l);
 
         if (l != r) {
             assert(rto[l] != -1);
             assert(to[rto[l]] == l);
             to[rto[l]] = -1;
             rto[l] = -1;
         }
     }
     printf("Case #%d: %d\n", cs, ans);
 }
 
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
