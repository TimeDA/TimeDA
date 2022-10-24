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
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         //cerr << "TEST: " << tt << endl;
         int64 n, k;
         cin >> n >> k;
         
         int64 s = n;
         int64 c1 = 1, c2 = 0;
 
         int64 next_s = -1;
         int64 next_c1 = 0, next_c2 = 0;
 
         auto init = [&] {
             c1 = next_c1;
             c2 = next_c2;
             s = next_s;
             next_s = -1;
             next_c1 = 0;
             next_c2 = 0;
         };
 
         auto add = [&] (int64 value, int64 am) {
             //cerr << "ADD: " << value << ", " << am << endl;
             if (value == next_s) {
                 next_c1 += am;
             } else {
                 next_c2 += am;
             }
         };
 
         int64 last;
         while (k > 0) {
             //cerr << "k: " << k << endl;
 
             int64 cur;
             if (c1 > 0) {
                 cur = c1;
                 last = s;
                 c1 = 0;
             } else if (c2 > 0) {
                 cur = c2;
                 last = s - 1;
                 c2 = 0;
             } else {
                 init();
                 continue;
             }
 
             k -= cur;
             int64 x = last / 2;
             int64 y = (last - 1) / 2;
             if (next_s == -1) {
                 next_s = x;
             }
             add(x, cur);
             add(y, cur);
         }
 
         cout << "Case #" << tt << ": " << last / 2 << " " << (last - 1) / 2 << "\n";
 
     }
     
     return 0;
 }
