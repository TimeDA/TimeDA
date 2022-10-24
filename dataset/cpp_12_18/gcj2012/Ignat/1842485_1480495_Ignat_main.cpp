#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define DEBUG(x)
 #endif
 
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <string>
 #include <cstring>
 #include <sstream>
 #include <algorithm>
 #include <memory.h>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cassert>
 using namespace std;
 
 
 // Enlarge MSVS stack size
 #pragma comment(linker, "/STACK:16777216")
 
 #define pb push_back
 #define all(c) c.begin(), c.end()
 #define mp(x, y) make_pair(x, y)
 #define sz(x) static_cast<int>(x.size())
 typedef long long int64;
 typedef  pair<int, int> ii;
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("1.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 const int MAX = 100;
 int dx[4] = {1, 0,  0, -1};
 int dy[4] = {0, -1, 1,  0};
 int n, m;
 int a[MAX][MAX];
 
 ii apply(ii pos, int ind) {
     ii newPos(pos.first + dx[ind], pos.second + dy[ind]);
     if (a[newPos.first][newPos.second] == -1) {
         return pos;
     }
     else {
         return newPos;
     }
 }
 
 set<ii> apply(const set<ii>& x, int ind) {
     set<ii> res;
     for (const auto& el: x) {
         res.insert(apply(el, ind));
     }
     return res;
 }
 
 bool isGood(const set<ii>& x, const set<ii>& good) {
     for (const auto& el: x) {
         if (good.find(el) == good.end()) return false;
     }
     return true;
 }
 
 void print(const set<ii>& s) {
     cerr << "{";
     for (const auto& el: s) {
         cerr << "(" << el.first << ", " << el.second << ") ";
     }
     cerr << "}" << endl;
 }
 
 pair<int, bool> solve(ii start) {
     vector<ii> passable;
     set<ii> visited;
     vector<ii> q(5000);
     int en = 0, st = 0;
     q[en++] = start;
     visited.insert(start);
     while (st < en) {
         ii pos = q[st++];
         passable.pb(pos);
         for (int i = 1; i < 4; ++i) {
             auto newPos = apply(pos, i);
             if (visited.find(newPos) != visited.end()) continue;
             q[en++] = newPos;
             visited.insert(newPos);
         }
     }
 
     bool lucky = false;
     set<ii> goodSet(passable.begin(), passable.end());
 
     set< set<ii> > vv;
     vector< set<ii> > ss(20000);
     en = st = 0;
     ss[en++] = goodSet;
     vv.insert(goodSet);
     while (st < en) {
         const set<ii>& pos = ss[st++];
         //cerr << "START!" << endl;
         //print(pos);
         if (pos.size() == 1 && *pos.begin() == start) {
             lucky = true;
             break;
         }
         for (int i = 0; i < 3; ++i) {
             //cerr << "i = " << i << endl;
             set<ii> newPos = apply(pos, i);
             if (!isGood(newPos, goodSet)) continue;
             if (vv.find(newPos) != vv.end()) continue;
             //cerr << "Found!" << endl;
             //print(newPos);
             vv.insert(newPos);
             ss[en++] = newPos;
         }
     }
     return make_pair((int)goodSet.size(), lucky);
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST " << tt << endl;
         cin >> n >> m;
         ii starts[10];
         int startsSize = 0;
 
         for (int i = 0; i < n; ++i) {
             string str;
             cin >> str;
             for (int j = 0; j < m; ++j) {
                 if (str[j] == '#') a[i][j] = -1;
                 else a[i][j] = 0;
                 if (str[j] >= '0' && str[j] <= '9') {
                     startsSize = max(startsSize, str[j] - '0' + 1);
                     starts[str[j] - '0'] = ii(i, j);
                 }
             }
         }
 
         printf("Case #%d:\n", tt);
         for (int i = 0; i < startsSize; ++i) {
             int num;
             bool pass;
             std::tie(num, pass) = solve(starts[i]);
             printf("%d: %d %s\n", i, num, pass ? "Lucky" : "Unlucky");
         }
     }
     
     return 0;
 }
