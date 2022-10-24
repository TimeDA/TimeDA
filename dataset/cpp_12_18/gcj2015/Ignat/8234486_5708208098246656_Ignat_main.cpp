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
 
 int dx[4] = {0, 1, 0, -1};
 int dy[4] = {1, 0, -1, 0};
 
 const int MAX = 100 + 5;
 int table[MAX][MAX];
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt  <= T; ++tt) {
         int n, m;
         cin >> n >> m;
         for (int i = 0; i < n; ++i) {
             string str;
             cin >> str;
             for (int j = 0; j < m; ++j) {
                 if (str[j] == '>') {
                     table[i][j] = 0;
                 }
                 else if (str[j] == '<') {
                     table[i][j] = 2;
                 }
                 else if (str[j] == 'v') {
                     table[i][j] = 1;
                 }
                 else if (str[j] == '^') {
                     table[i][j] = 3;
                 } else {
                     table[i][j] = 4;
                 }
 
             }
         }
 
         bool ok = true;
 
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (table[i][j] == 4) {
                     continue;
                 }
 
                 bool has = false;
                 for (int d = 0; d < 4 && !has; ++d) {
                     for (int k = 1; k < max(n, m) && !has; ++k) {
                         int x = i + k * dx[d];
                         int y = j + k * dy[d];
                         if (x >= 0 && x < n && y >= 0 && y < m && table[x][y] != 4) {
                             //newDirection[i][j] = d;
                             has = true;
                             break;
                         }
                     }
                 }
                 if (!has) {
                     ok = false;
                 }
             }
         }
 
         int res = 0;
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (table[i][j] == 4) {
                     continue;
                 }
                 int d = table[i][j];
                 bool has = false;
                 for (int k = 1; k < max(n, m) && !has; ++k) {
                     int x = i + k * dx[d];
                     int y = j + k * dy[d];
                     if (x >= 0 && x < n && y >= 0 && y < m && table[x][y] != 4) {
                         has = true;
                         break;
                     }
                 }
                 if (!has) {
                     res += 1;
                 }
             }
         }
 
         cout << "Case #" << tt << ": ";
         if (ok) {
             cout << res << "\n";
         } else {
             cout << "IMPOSSIBLE" << "\n";
         }
     }
     
     return 0;
 }
