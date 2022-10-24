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
 
 const int md = 1000000007;
 
 ll mx[210][210];
 int rr[210], cc[210], bb[210];
 int n, m, k, d;
 
 void solve() {
     scanf("%d %d %d %d", &n, &m, &k, &d);
     forn(i, n) forn(j, m) mx[i][j] = -1;
     forn(q, k) {
         int r, c, b;
         scanf("%d %d %d", &r, &c, &b);
         r--, c--;
         rr[q] = r;
         cc[q] = c;
         bb[q] = b;
         forn(i, n) forn(j, m) {
             ll dist = abs(i - r) + abs(j - c);
             ll v = b + dist * d;
             if (mx[i][j] == -1 || mx[i][j] > v)
                 mx[i][j] = v;
         }
     }
 
     forn(q, k)
         if (mx[rr[q]][cc[q]] != bb[q]) {
             printf("IMPOSSIBLE\n");
             return;
         }
 
     ll ans = 0;
     forn(i, n) forn(j, m) ans = (ans + mx[i][j]) % md;
     cout << ans << endl;
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
