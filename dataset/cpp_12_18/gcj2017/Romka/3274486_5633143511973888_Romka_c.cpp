#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <unordered_map>
 #include <unordered_set>
 #include <sstream>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <cassert>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define sqr(x) (x) * (x)
 template <class T> ostream& operator<<(ostream& out, const vector<T>& v) { forn(i, v.size()) { if (i) out << " "; out << v[i]; } return out; }
 template <class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) { out << "{" << p.first << ", " << p.second << "}"; return out; }
 
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 const ld EPS = 1e-7;
 
 void solve() {
     int n, k;
     scanf("%d %d", &n, &k);
     double u;
     scanf("%lf", &u);
     vector<double> p(n);
     forn(i, n) scanf("%lf", &p[i]);
     while (u > EPS) {
         double min1 = 10, min2 = 19;
         forn(i, n) {
             if (p[i] < min1 - EPS) {
                 min2 = min1;
                 min1 = p[i];
             } else if (p[i] > min1 + EPS && p[i] < min2 - EPS) {
                 min2 = p[i];
             }
         }
 
         int csm = 0;
         forn(i, n)
             if (abs(p[i] - min1) < EPS) csm++;
 
         ld want = csm * (min2 - min1);
         ld q = min2 - min1;
         if (want > u) {
             q = u / csm;
         }
         forn(i, n)
             if (abs(p[i] - min1) < EPS) p[i] += q;
         if (want > u) break;
         u -= want;
     }
 
     ld ans = 1;
     forn(i, n) ans *= p[i];
     printf("%.10f\n", double(ans));
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
     return 0;
 }
