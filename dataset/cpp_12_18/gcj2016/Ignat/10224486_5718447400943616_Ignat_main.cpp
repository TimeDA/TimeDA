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
     freopen("1.in", "r", stdin);
     freopen("1.out", "w", stdout);
 }
 
 typedef vector<vector<bool>> Graph;
 
 void dfs(int u, int color, const Graph& g, vector<int>& colors) {
     colors[u] = color;
     for (int i = 0; i < g.size(); ++i) {
         if (g[u][i] && colors[i] != color) {
             dfs(i, color, g, colors);
         }
     }
 }
 
 vector<vector<int>> findConnectedComponents(const Graph& g) {
     int color = 0;
     vector<int> colors(g.size(), 0);
     for (int i = 0; i < g.size(); ++i) {
         if (colors[i] == 0) {
             dfs(i, ++color, g, colors);
         }
     }
 
     vector<vector<int>> components(color, vector<int>());
     for (int i = 0; i < g.size(); ++i) {
         components[colors[i] - 1].pb(i);
     }
     return components;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST " << tt << endl;
         int n;
         cin >> n;
 
         Graph g(2 * n, vector<bool>(2 * n, false));
 
         for (int i = 0; i < n; ++i) {
             string s;
             cin >> s;
             for (int j = 0; j < n; ++j) {
                 if (s[j] == '1') {
                     g[i][n + j] = g[n + j][i] = true;
                 }
             }
         }
 
 
         int bestSum = n * n;
         for (int mask = 0; mask < (1 << (n * n)); ++mask) {
             Graph h(g);
             int sum = 0;
             for (int i = 0; i < n; ++i) {
                 for (int j = 0; j < n; ++j) {
                     int shift = i * n + j;
                     if ((mask & (1 << shift)) > 0) {
                         h[i][n + j] = h[n + j][i] = true;
                         sum += 1;
                     }
                 }
             }
 
 
             //cerr << "MASK " << mask << endl;
 
             bool ok = true;
             auto components = findConnectedComponents(h);
             for (int i = 0; i < components.size(); ++i) {
                 //cerr << "COMPONENT(" << components[i].size() << ") ";
                 //for (int j = 0; j < components[i].size(); ++j) {
                 //    cerr << components[i][j] << " ";
                 //}
                 //cerr << endl;
                 if (components[i].size() % 2 != 0) {
                     ok = false;
                     break;
                 }
                 int left = 0;
                 int right = 0;
                 set<int> vertices;
                 for (int j = 0; j < components[i].size(); ++j) {
                     int u = components[i][j];
                     vertices.insert(u);
                     if (u >= n) {
                         right += 1;
                     } else {
                         left += 1;
                     }
                 }
                 if (left != right) {
                     ok = false;
                     break;
                 }
 
                 for (int i = 0; i < h.size() / 2 && ok; ++i) {
                     for (int j = h.size() / 2; j < h.size() && ok; ++j) {
                         if (vertices.find(i) != vertices.end() && vertices.find(j) != vertices.end() && !h[i][j]) {
                             ok = false;
                             //cerr << "i = " << i << " " << "j = " << j << endl;
                         }
                     }
                 }
             }
 
             if (ok) {
                 bestSum = min(bestSum, sum);
             }
         }
 
         cout << "Case #" << tt << ": " << bestSum << endl; 
     }
     
     return 0;
 }
