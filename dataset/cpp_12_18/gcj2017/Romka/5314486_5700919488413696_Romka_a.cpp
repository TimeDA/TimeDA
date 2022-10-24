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
 
 int n, p;
 map<vector<int>, int> mm;
 
 int get(vector<int> key) {
     if (mm.find(key) != mm.end()) return mm[key];
     int& res = mm[key];
 
     res = 0;
     bool b = false;
     for (int i = 1; i < p; i++)
         if (key[i] > 0) {
             b = true;
             vector<int> nxt = key;
             nxt[i]--;
             nxt[0] = (nxt[0] + i) % p;
             int z = get(nxt);
             if (z > res) res = z;
         }
 
     if (key[0] == 0 && b) res++;
 
     return res;
 }
 
 void solve() {
     scanf("%d %d", &n, &p);
     int x;
     vector<int> cc(p);
     forn(i, n) {
         scanf("%d", &x);
         cc[x % p]++;
     }
 
     int w = cc[0];
     cc[0] = 0;
     printf("%d\n", w + get(cc));
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
