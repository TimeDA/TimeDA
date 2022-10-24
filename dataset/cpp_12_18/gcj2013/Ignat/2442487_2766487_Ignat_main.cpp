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
     freopen("_.out", "w", stdout);
 }
 
 int64 calcWorstPlace(int64 n, int64 num) {
     int64 res = 0;
     while (num > 0) {
         n -= 1;
         res += (1 << n);
         num = (num - 1) / 2;
     }
     return res;
 }
 
 int64 calcBestPlace(int64 n, int64 num) {
     num = (1 << n) - num - 1;
     int64 res = (1 << n) - 1;
     while (num > 0) {
         n -= 1;
         res -= (1 << n);
         num = (num - 1) / 2;
     }
     return res;
 }
 
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int64 n, p;
         cin >> n >> p;
 
         int64 x, y;
         {
             int64 l = 0, u = (1 << n);
             while (l + 1 < u) {
                 int64 med = (l + u) / 2;
                 if (calcWorstPlace(n, med) >= p) {
                     u = med;
                 }
                 else {
                     l = med;
                 }
             }
             x = l;
         }
         {
             int64 l = 0, u = (1 << n);
             while (l + 1 < u) {
                 int64 med = (l + u) / 2;
                 if (calcBestPlace(n, med) >= p) {
                     u = med;
                 }
                 else {
                     l = med;
                 }
             }
             y = l;
         }
         cout << "Case #" << tt << ": " << x << " " << y << "\n";
     }
 
     return 0;
 }
