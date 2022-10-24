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
 
 bool dfs(int u, int target, const vector<vector<bool>>& a, vector<bool>& visited) {
     visited[u] = true;
     if (u == target) {
         return true;
     }
     for (int i = 0; i < a.size(); ++i) {
         if (!visited[i] && a[u][i]) {
             if (dfs(i, target, a, visited)) {
                 return true;
             }
         }
     }
     return false;
 }
 
 bool check(const vector<vector<int>>& distance, double d) {
     //cerr << d << endl;
     int n = distance.size();
     vector<vector<bool>> a(n, vector<bool>(n, false));
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
             if (d * d >= distance[i][j]) {
                 a[i][j] = true;
                 //cerr << i << " " << j << endl;
             }
         }
     }
     vector<bool> visited(n, false);
     bool res = dfs(1, 0, a, visited);
     //,wwcerr << "RES: " << res << endl;
     return res;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >>T;
     for (int tt = 1; tt <= T; ++tt) {
         int n, s;
         cin >> n >> s;
         vector<int> x(n), y(n), z(n);
         for (int i = 0; i < n; ++i) {
             int fake;
             cin >> x[i] >> y[i] >> z[i] >> fake >> fake >> fake;
         }
 
         vector<vector<int>> distance(n, vector<int>(n));
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < n; ++j) {
                 distance[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]);
             }
         }
 
         double down = 0.0, up = 1e6;
         while (up - down > 1e-6) {
             double med = (down + up) / 2.0;
             if (check(distance, med)) {
                 up = med;
             } else {
                 down = med;
             }
         }
 
         printf("Case #%d: %.15lf\n", tt, down);
     }
     
     return 0;
 }
