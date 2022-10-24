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
 
 bool canSolve(int bound, vector<vector<int>> p, int& k)
 {
     int add = 0;
     k = 0;
     for (int i = p.size() - 1; i >= 0; --i) {
         if (p[i].size() > bound) {
             add += p[i].size() - bound;
         } else {
             int d = min(add, bound - (int)p[i].size());
             add -= d;
             k += d;
         }
     }
     return (add == 0);
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
 
     for (int tt = 1; tt <= T; ++tt) {
         int n, c, m;
         cin >> n >> c >> m;
         vector<vector<int>> p(n, vector<int>());
         vector<int> bCount(c);
 
         for (int i = 0; i < m; ++i) {
             int pos, buyer;
             cin >> pos >> buyer;
             pos -= 1;
             p[pos].pb(buyer);
             bCount[buyer] += 1;
         }
 
         int maxCount = 0;
         for (auto x : bCount) {
             maxCount = max(maxCount, x);
         }
 
         int down = maxCount - 1;
         int up = m;
 
         int k = 0;
         while (up - down > 1) {
             int med = (down + up) / 2;
             if (canSolve(med, p, k)) {
                 up = med;
             } else {
                 down = med;
             }
         }
         canSolve(up, p, k);
 
         cout << "Case #" << tt << ": " << up << " " << k << endl;
     }
     
     return 0;
 }
