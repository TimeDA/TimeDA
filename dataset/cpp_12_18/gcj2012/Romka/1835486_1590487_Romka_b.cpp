#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 const int dx[] = {+1, +1, 0, 0, -1, -1};
 const int dy[] = {0, +1, -1, +1, -1, 0};
 
 int S, n, x, y;
 vector<pii> coord;
 vector<int> p, ind;
 vector< vector<int> > g;
 set<int> empty, corners, edges;
 map<pii, int> mm;
 vector<int> u;
 set<int> stones;
 int it;
 
 int isCorner(const pii& c) {
     if (c.first == 1 && c.second == 1) return 0;
     if (c.first == S && c.second == 1) return 1;
     if (c.first == 1 && c.second == S) return 2;
     if (c.first == S && c.second == 2*S-1) return 3;
     if (c.first == 2*S-1 && c.second == S) return 4;
     if (c.first == 2*S-1 && c.second == 2*S-1) return 5;
     return -1;
 }
 
 int isEdge(const pii& c) {
     if (isCorner(c) >= 0) return -1;
     if (c.first == 1) return 0;
     if (c.second == 1) return 1;
     if (c.first - c.second == S-1) return 2;
     if (c.second - c.first == S-1) return 3;
     if (c.first == 2*S-1) return 4;
     if (c.second == 2*S-1) return 5;
     return -1;
 }
 
 int getid(int x, int y, bool add = true) {
     if (x < 1 || y < 1 || x > 2*S-1 || y > 2*S-1 || x-y > S-1 || x-y < -S+1) return -1;
     pii z(x, y);
     if (mm.find(z) != mm.end()) return mm[z];
     if (!add) return -1;
     int res = mm.size();
     g.pb(vector<int>());
     ind.pb(0);
     p.pb(0);
     u.pb(0);
     coord.pb(z);
     return mm[z] = res;
 }
 
 void dfs(int v) {
     pii c = coord[v];
     int z = isCorner(c);
     if (z != -1) corners.insert(z);
     z = isEdge(c);
     if (z != -1) edges.insert(z);
 
     u[v] = it;
 
     forn(i, g[v].size()) {
         int y = g[v][i];
         if (stones.find(y) == stones.end()) empty.insert(y);
         else
             if (u[y] != it) dfs(y);
     }
 }
 
 int findset(int x) {
     return x == p[x] ? x : p[x] = findset(p[x]);
 }
 
 void link(int a, int b) {
     // printf("> link %d %d\n", a, b);
     a = findset(a);
     b = findset(b);
     if (a == b) return;
     if (a & 1) p[a] = b;
     else p[b] = a;
 }
 
 bool checkEmpty() {
     int n = empty.size();
     vector<int> vv(empty.begin(), empty.end());
     forn(i, n) p[i] = i, ind[ vv[i] ] = i;
     // forn(i, n) printf("> %d %d\n", coord[ vv[i] ].first, coord[ vv[i] ].second);
 
     vector<int> sides;
     forn(i, n) {
         pii c = coord[ vv[i] ];
         if (isEdge(c) >= 0 || isCorner(c) >= 0) sides.pb(i);
         forn(q, 6) {
             int y = getid(c.first + dx[q], c.second + dy[q], false);
             if (y == -1) continue;
             if (empty.find(y) != empty.end()) link(ind[y], i);
         }
     }
 
     forn(i, sides.size())
         if (i)
             link(sides[i], sides[i-1]);
 
     int P = findset(0);
     forn(i, n)
         if (findset(i) != P) return true;
 
     if (sides.empty() && !empty.empty() && corners.size() == 6) return true;
 
     return false;
 }
 
 void solve() {
     scanf("%d %d", &S, &n);
     p.clear();
     g.clear();
     mm.clear();
     u.clear();
     stones.clear();
     ind.clear();
     coord.clear();
     bool ansfound = false;
     forn(i, n) {
         fprintf(stderr, "%d turns of %d\n", i, n);
         it++;
         scanf("%d %d", &x, &y);
         if (ansfound) continue;
         int v = getid(x, y);
         stones.insert(v);
         forn(q, 6) {
             int z = getid(x + dx[q], y + dy[q]);
             if (z == -1) continue;
             g[v].pb(z);
             g[z].pb(v);
         }
 
         empty.clear();
         corners.clear();
         edges.clear();
 
         dfs(v);
 
         vector<string> res;
         if (corners.size() > 1) res.pb("bridge");
         if (edges.size() > 2) res.pb("fork");
         if (checkEmpty()) res.pb("ring");
 
         string ans = "";
         forn(qi, res.size())
             ans = ans + "-" + res[qi];
 
         if (ans.size() > 0) {
             printf("%s in move %d\n", ans.substr(1).c_str(), i+1);
             ansfound = true;
         }
     }
     
     if (!ansfound) printf("none\n");
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d: ", q);
         solve();
     }
 }
