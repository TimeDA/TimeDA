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
 
 bool check(int D, int n, const vector <int> & pos, const vector <int> & v, double V0) {
   bool ok = true;
   for (int i = 0; i < n; ++i) {
     if (v[i] >= V0) { continue; }
     double dv = V0 - v[i];
     double dt = pos[i] / dv;
     double X = V0 * dt;
     ok &= (X >= D);
   }
   return ok;
 }
 
 void solve() {
   int D, n;
   scanf("%d%d", &D, &n);
   vector <int> pos(n);
   vector <int> v(n);
   for (int i = 0; i < n; ++i) {
     scanf("%d%d", &pos[i], &v[i]);
   }
 
   double left = 0.0;
   double right = 1e13;
   for (int it = 0; it < 100; ++it) {
     double middle = (left + right) / 2.0;
     if (check(D, n, pos, v, middle)) {
       left = middle;
     } else {
       right = middle;
     }
   }
   printf("%.10lf\n", (left + right) / 2.0);
 }
 
 int main() {
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii) {
 //    dbg("Case #%d:\n", ii);
     printf("Case #%d: ", ii);
     solve();
     printf("\n");
     fflush(stdout);
   }
   return 0;
 }
