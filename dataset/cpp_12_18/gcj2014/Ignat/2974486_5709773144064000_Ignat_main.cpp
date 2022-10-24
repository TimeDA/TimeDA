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
 
 int main()
 {
     initialize();
     
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         double c, f, x;
         cin >> c >> f >> x;
 
         double speed = 2.0;
         double res = x / speed;
         double t = 0.0;
         for (int i = 0; i < 1000000; ++i) {
             t += c / speed;
             speed += f;
             res = min(res, t + (x / speed));
         }
         printf("Case #%d: %.10lf\n", tt, res);
     }
 
     return 0;
 }
