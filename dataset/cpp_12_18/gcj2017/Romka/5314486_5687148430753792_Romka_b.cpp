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
 
 int n, c, m;
 vector<int> mt;
 vector<vector<int>> g;
 vector<bool> used;
 
 int dfs(int x) {
     // cerr << "dfs " << x << endl;
     if (x == -1) return 1;
     if (used[x]) return 0;
     used[x] = 1;
     for (int y : g[x]) {
         int z = mt[y];
         mt[y] = x;
         if (dfs(z)) return 1;
         mt[y] = z;
     }
     return 0;
 }
 
 void solve() {
     scanf("%d %d %d", &n, &c, &m);
     int pos, owner;
     vector<int> o1, o2;
     forn(i, m) {
         scanf("%d %d", &pos, &owner);
         if (owner == 1) o1.push_back(pos);
         else o2.push_back(pos);
     }
 
     cerr << "a1" << endl;
     g.assign(o1.size(), vector<int>());
     mt.assign(o2.size(), -1);
     forn(i, o1.size())
         forn(j, o2.size())
             if (o1[i] != o2[j])
                 g[i].push_back(j);
 
     cerr << "a2" << endl;
     forn(i, o1.size()) {
         used.assign(o1.size(), false);
         dfs(i);
     }
 
     cerr << "a3" << endl;
 
     used.assign(o1.size(), false);
     int rides = 0, promo = 0, rc1 = 0, row = -1, rc2 = 0;
     forn(j, o2.size())
         if (mt[j] != -1) {
             rides++;
             used[mt[j]] = true;
         } else {
             rc2++;
             row = o2[j];
         }
 
     forn(j, o1.size())
         if (!used[j]) {
             rc1++;
             row = o1[j];
         }
 
     if (row == 1) {
         rides += rc1 + rc2;
     } else {
         promo = min(rc1, rc2);
         rides += max(rc1, rc2);
     }
 
     printf("%d %d\n", rides, promo);
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
