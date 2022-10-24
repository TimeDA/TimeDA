#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define PRINT(x)
 #define PRINT_CONT(x)
 #define PRINT_MSG(x)
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
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("B-small-attempt0.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n, m;
         cin >> n >> m;
         vector<vector<int>> a(n);
         vector<int> x(n, 0), y(m, 0);
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 int num;
                 cin >> num;
                 a[i].pb(num);
                 x[i] = max(x[i], num);
                 y[j] = max(y[j], num);
             }
         }
 
         bool ok = true;
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (a[i][j] != min(x[i], y[j])) ok = false;
             }
         }
         printf("Case #%d: %s\n", tt, ok ? "YES" : "NO");
     }
     
     return 0;
 }
