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
     freopen("0.in", "r", stdin);
     freopen("0.out", "w", stdout);
 }
 
 struct Rect {
     Rect() { };
     Rect(int x_, int y_) {
         x[0] = x[1] = x_;
         y[0] = y[1] = y_;
     }
 
     int x[2];
     int y[2];
 };
 
 int dx[4] = {0, 1, 0, -1};
 int dy[4] = {1, 0, -1, 0};
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n, m;
         cin >> n >> m;
         vector<vector<int>> a(n, vector<int>(m, 0));
         vector<Rect> rects;
         for (int i = 0; i < n; ++i) {
             string str;
             cin >> str;
             for (int j = 0; j < m; ++j) {
                 char c = str[j];
                 if (c != '?') {
                     rects.pb(Rect(i, j));
                     a[i][j] = c;
                 }
             }
         }
 
         auto check = [&] (Rect r) -> bool {
             if (r.x[0] < 0 || r.x[1] >= n || r.y[0] < 0 || r.y[1] >= m) {
                 return false;
             }
 
             set<int> colors;
             for (int i = r.x[0]; i <= r.x[1]; ++i) {
                 for (int j = r.y[0]; j <= r.y[1]; ++j) {
                     if (a[i][j] != 0) {
                         colors.insert(a[i][j]);
                     }
                 }
             }
 
             return colors.size() == 1;
         };
         
         auto apply = [&] (Rect r) {
             int c = 0;
             for (int i = r.x[0]; i <= r.x[1] && c == 0; ++i) {
                 for (int j = r.y[0]; j <= r.y[1] && c == 0; ++j) {
                     if (a[i][j] != 0) {
                         c = a[i][j];
                     }
                 }
             }
             
             for (int i = r.x[0]; i <= r.x[1]; ++i) {
                 for (int j = r.y[0]; j <= r.y[1]; ++j) {
                     a[i][j] = c;
                 }
             }
         };
 
         for (int i = 0; i < rects.size(); ++i) {
             for (int d = 0; d < 4; ++d) {
                 while (true) {
                     auto r = rects[i];
                     auto newR = r;
                     if (dx[d] != 0) {
                         newR.x[(dx[d] + 1) / 2] += dx[d];
                     }
                     if (dy[d] != 0) {
                         newR.y[(dy[d] + 1) / 2] += dy[d];
                     }
                     if (!check(newR)) {
                         //cerr << "newR NO: (" << newR.x[0] << ", " << newR.y[0] << "), (" << newR.x[1] << ", " << newR.y[1] << ")\n";
                         break;
                     } else {
                         //cerr << "newR YES: (" << newR.x[0] << ", " << newR.y[0] << "), (" << newR.x[1] << ", " << newR.y[1] << ")\n";
                         apply(newR);
                         rects[i] = newR;
                     }
                 }
             }
         }
 
         cout << "Case #" << tt << ":\n";
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 cout << char(a[i][j]);
             }
             cout << "\n";
         }
 
     }
     
     return 0;
 }
