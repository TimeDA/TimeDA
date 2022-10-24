#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 typedef long long llong;
 
 const int N = 205;
 
 llong A[N][N];
 llong B[N][N];
 
 const int MOD = 1000 * 1000 * 1000 + 7;
 
 void solve(int cs) {
     int r, c;
     scanf("%d %d", &r, &c);
     int n;
     scanf("%d", &n);
     llong D;
     scanf("%lld", &D);
     for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
             A[i][j] = 1e18;
             B[i][j] = -1;
         }
     }
     for (int i = 0; i < n; i++) {
         int y, x;
         scanf("%d %d", &y, &x);
         --y, --x;
         llong v;
         scanf("%lld", &v);
         B[y][x] = v;
         for (int p = 0; p < r; p++) {
             for (int q = 0; q < c; q++) {
                 A[p][q] = min(A[p][q], v + (abs(p - y) + abs(q - x)) * D);
             }
         }
     }
     llong sum = 0;
     bool bad = false;
     for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
             if (B[i][j] != -1 && A[i][j] != B[i][j]) {
                 bad = true;
             }
             sum += A[i][j];
         }
     }
     printf("Case #%d: ", cs);
     if (bad)
         puts("IMPOSSIBLE");
     else
         printf("%d\n", (int)(sum % MOD));
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
