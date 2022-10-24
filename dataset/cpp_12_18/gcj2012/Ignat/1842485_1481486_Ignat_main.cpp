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
 typedef pair<int, int> ii;
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("1.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 const int MAX = 10000 + 10;
 
 int pos[MAX];
 int len[MAX];
 ii positions[MAX * MAX];
 
 int main()
 {
     initialize();
     len[0] = (int)2e9;
     pos[0] = 0;
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         //cerr << "TEST " << tt << endl;
         int n;
         cin >> n;
         vector<ii> a;
         for (int i = 0; i < n; ++i) {
             ii x;
             cin >> x.first >> x.second;
             a.pb(x);
         }
         sort(all(a));
         for (int i = 1; i <= n; ++i) {
             pos[i] = a[i - 1].first;
             len[i] = a[i - 1].second;
         }
 
         int D;
         cin >> D;
         map<ii, bool> visited;
 
         int st = 0, en = 0;
         visited[ii(0, 1)] = true;
         positions[st++] = ii(0, 1);
 
         bool ok = false;
         while (en < st && !ok) {
             ii p = positions[en++];
             int l = pos[p.second];
             int r = pos[p.second] + min(len[p.second], pos[p.second] - pos[p.first]);
             //cerr << "Position(" << p.first << ", " << p.second << "): left = " << l << ", right = " << r << endl;
             if (r >= D) ok = true;
 
             int iL = lower_bound(pos, pos + n + 1, l) - pos, iR = upper_bound(pos, pos + n + 1, r) - pos;
             for (int i = iL; i < iR; ++i) {
                 ii newPos = ii(p.second, i);
                 if (visited[newPos]) continue;
                 visited[newPos] = true;
                 positions[st++] = newPos;
             }
         }
         printf("Case #%d: ", tt);
         if (ok)  {
             printf("YES\n");
         }
         else {
             printf("NO\n");
         }
     }
     
     return 0;
 }
