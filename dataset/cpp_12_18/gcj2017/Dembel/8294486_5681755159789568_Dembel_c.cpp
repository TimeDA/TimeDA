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
 
 const double INF = 1e100;
 
 void solve() {
   int n, q;
   scanf("%d%d", &n, &q);
   vector <int> E(n), V(n);
   for (int i = 0; i < n; ++i) {
     scanf("%d%d", &E[i], &V[i]);
   }
   vector <vector<double> > a(n, vector<double>(n));
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < n; ++j) {
       int x;
       scanf("%d", &x);
       a[i][j] = (x == -1 ? INF : x);
     }
   }
   for (int k = 0; k < n; ++k) {
     for (int i = 0; i < n; ++i) { 
       for (int j = 0; j < n; ++j) {
           if (a[i][j] > a[i][k] + a[k][j]) {
             a[i][j] = a[i][k] + a[k][j];
           }
       }
     }
   }
   vector <vector<double> > w(n, vector<double>(n, INF));
   for (int i = 0; i < n; ++i) {
     for (int j = 0; j < n; ++j) {
       if (a[i][j] <= E[i]) {
         w[i][j] = (a[i][j] / double(V[i]));
       }
     }
   }
   for (int k = 0; k < n; ++k) {
     for (int i = 0; i < n; ++i) { 
       for (int j = 0; j < n; ++j) {
         w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
       }
     }
   }
 
   for (int i = 0; i < q; ++i) {
     int u, v;
     scanf("%d%d", &u, &v);
     --u, --v;
     printf(" %.10lf", w[u][v]);
   }
   //printf("\n");
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
 //    dbg("Case #%d:\n", ii);
     printf("Case #%d:", ii);
     solve();
     printf("\n");
     fflush(stdout);
   }
   return 0;
 }
