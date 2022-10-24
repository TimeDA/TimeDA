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
         string str;
         int k;
         cin >> str >> k;
 
         int res = 0;
         for (int i = 0; i + k <= str.size(); ++i) {
             if (str[i] == '-') {
                 res += 1;
                 for (int j = 0; j < k; ++j) {
                     str[i + j] = (str[i + j] == '-') ? '+' : '-';
                 }
             }
         }
 
         bool ok = true;
         for (int i = 0; i < str.size(); ++i) {
             if (str[i] == '-') {
                 ok = false;
                 break;
             }
         }
 
         cout << "Case #" << tt << ": ";
         if (ok) {
             cout << res;
         } else {
             cout << "IMPOSSIBLE";
         }
         cout << "\n";
     }
     
     return 0;
 }
