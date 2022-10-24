#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <unordered_map>
 #include <unordered_set>
 #include <sstream>
 #include <tuple>
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
 
 void solve() {
     int k1, k2, a, b;
     scanf("%d %d", &k1, &k2);
     vector<tuple<int, int, int>> ev;
     int left1 = 720, left2 = 720;
     forn(i, k1) {
         scanf("%d %d", &a, &b);
         ev.emplace_back(a, b, 1);
         left1 -= b - a;
     }
     forn(i, k2) {
         scanf("%d %d", &a, &b);
         ev.emplace_back(a, b, 2);
         left2 -= b - a;
     }
     sort(ev.begin(), ev.end());
     ev.emplace_back(get<0>(ev.front()) + 1440, get<1>(ev.front()) + 1440, get<2>(ev.front()));
     assert(ev.size() == k1 + k2 + 1);
     vector<pii> segs;
     int ans = 0;
     forn(i, ev.size() - 1) {
         int oa = get<2>(ev[i]);
         int ob = get<2>(ev[i + 1]);
         int d = get<0>(ev[i + 1]) - get<1>(ev[i]);
         if (oa == ob) {
             if (d != 0)
                 segs.emplace_back(d, oa);
         } else {
             // segs.emplace_back(d, 0);
             ans++;
         }
     }
     sort(segs.begin(), segs.end());
     for (const pii& q : segs) {
         int oa = q.second;
         if (oa == 1) {
             if (left1 < q.first) ans += 2;
             else left1 -= q.first;
         }
         if (oa == 2) {
             if (left2 < q.first) ans += 2;
             else left2 -= q.first;
         }
     }
     printf("%d\n", ans);
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
