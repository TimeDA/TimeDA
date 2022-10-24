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
 
 void solve() {
     ll n, k;
     cin >> n >> k;
     map<ll, ll> ss;
     ss.emplace(-n, 1);
     while (true) {
         // cerr << k << endl;
         auto cur = *ss.begin();
         ss.erase(ss.begin());
         if (cur.second >= k) {
             cout << (-cur.first) / 2 << " " << (-cur.first - 1) / 2 << endl;
             return;
         } else {
             ss[-((-cur.first) / 2)] += cur.second;
             ss[-((-cur.first - 1) / 2)] += cur.second;
             k -= cur.second;
         }
     }
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
