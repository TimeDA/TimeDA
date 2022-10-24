#include <cassert>
 #include <memory.h>
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int N = 105;
 
 double D[N][N];
 double E[N];
 double S[N];
 bool used[N];
 
 const double inf = 1e100;
 
 double A[N][N];
 
 void solve(int cs) {
     int n, q;
     scanf("%d %d", &n, &q);
     for (int i = 0; i < n; i++) {
         scanf("%lf %lf", &E[i], &S[i]);
     }
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             scanf("%lf", &D[i][j]);
             if (D[i][j] < -0.5)
                 D[i][j] = inf;
             if (i == j)
                 D[i][i] = 0;
         }
     }
     for (int k = 0; k < n; k++) {
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) {
                 D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
             }
         }
     }
     for (int t = 0; t < n; t++) {
         memset(used, 0, sizeof(bool) * n);
         for (int i = 0; i < n; i++) {
             A[t][i] = (i == t) ? 0 : inf;
         }
         for (int it = 0; it < n; it++) {
             int mni = -1;
             double mn = 2 * inf;
             for (int i = 0; i < n; i++) {
                 if (used[i])
                     continue;
                 if (mni == -1 || mn > A[t][i])
                     mni = i, mn = A[t][i];
             }
             assert(mni != -1);
             used[mni] = true;
             for (int i = 0; i < n; i++) {
                 if (D[i][mni] < E[i] + 0.5) {
                     double q = D[i][mni] / S[i];
                     if (A[t][i] > mn + q) {
                         assert(!used[i]);
                         A[t][i] = mn + q;
                     }
                 }
             }
         }
     }
     printf("Case #%d:", cs);
     for (int i = 0; i < q; i++) {
         int u, v;
         scanf("%d %d", &u, &v);
         --u, --v;
         assert(A[v][u] < inf / 2);
         printf(" %.10lf", A[v][u]);
     }
     printf("\n");
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {
         solve(i + 1);
     }
 }
