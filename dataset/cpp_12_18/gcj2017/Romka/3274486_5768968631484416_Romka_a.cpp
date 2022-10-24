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
 
 const ld PI = acos(-1.0);
 
 void solve() {
     int n, k;
     scanf("%d %d", &n, &k);
     vector<pii> pancakes(n);
     forn(i, n) scanf("%d %d", &pancakes[i].second, &pancakes[i].first);
     sort(pancakes.begin(), pancakes.end(),
         [](const pii& a, const pii& b) { return a.first * (ll)a.second > b.first * (ll)b.second; });
     ll ans = -1;
     forn(i, n) {
         int need = k - 1;
         ll hs = 2LL * pancakes[i].second * pancakes[i].first;
         forn(j, n) {
             if (need == 0) break;
             if (j != i && pancakes[i].second >= pancakes[j].second) {
                 need--;
                 hs += 2LL * pancakes[j].second * pancakes[j].first;
             }
         }
 
         if (need > 0) continue;
         ll cur = pancakes[i].second * (ll)pancakes[i].second + hs;
         if (cur > ans) ans = cur;
     }
     printf("%.10f\n", double(PI * ans));
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
