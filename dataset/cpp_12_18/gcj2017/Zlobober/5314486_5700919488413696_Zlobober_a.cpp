#include <cstdio>
 #include <vector>
 using namespace std;
 
 const int N = 105;
 
 int D[N][N][N][N];
 
 inline void relax(int& x, int y) {
     if (x < y)
         x = y;
 }
 
 void solve(int cs) {
     int n, p;
     scanf("%d %d", &n, &p);
     vector<int> cnt(4);
     for (int i = 0; i < n; i++) {
         int x;
         scanf("%d", &x);
         cnt[x % p]++;
     }
     for (int a = 0; a <= cnt[0]; a++) {
         for (int b = 0; b <= cnt[1]; b++) {
             for (int c = 0; c <= cnt[2]; c++) {
                 for (int d = 0; d <= cnt[3]; d++) {
                     D[a][b][c][d] = -1;
                 }
             }
         }
     }
     D[cnt[0]][cnt[1]][cnt[2]][cnt[3]] = 0;
     for (int a = cnt[0]; a >= 0; a--) {
         for (int b = cnt[1]; b >= 0; b--) {
             for (int c = cnt[2]; c >= 0; c--) {
                 for (int d = cnt[3]; d >= 0; d--) {
                     if (!a && !b && !c && !d)
                         continue;
                     int cur = ((cnt[0] - a) * 0 + (cnt[1] - b) * 1 + (cnt[2] - c) * 2 + (cnt[3] - d) * 3);
                     int nxt = D[a][b][c][d];
                     if (cur % p == 0)
                         ++nxt;
                     if (a)
                         relax(D[a - 1][b][c][d], nxt);
                     if (b)
                         relax(D[a][b - 1][c][d], nxt);
                     if (c)
                         relax(D[a][b][c - 1][d], nxt);
                     if (d)
                         relax(D[a][b][c][d - 1], nxt);
                 }
             }
         }
     }
     printf("Case #%d: %d\n", cs, D[0][0][0][0]);
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
