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
 
 int check(int num) {
     set<int> digits;
     for (int c = 1; c <= 100; ++c) {
         int newNum = c * num;
         if (newNum == 0) {
             digits.insert(0);
         }
         while (newNum > 0) {
             digits.insert(newNum % 10);
             newNum /= 10;
         }
         if (digits.size() == 10) {
             return c * num;
         }
     }
     return -1;
 }
 
 int main()
 {
     initialize();
 
     //for (int i = 1; i < 1000; ++i) {
     //    if (check(i) == -1) {
     //        cerr << "AAAAAAAAA: " << i << endl;
     //    }
     //}
 
     int T;
     cin >>T; 
     for (int tt = 1; tt <= T; ++tt) {
         int num;
         cin >> num;
         int res = check(num);
         cout << "Case #" << tt << ": ";
         if (res == -1) {
             cout << "INSOMNIA";
         } else {
             cout << res;
         }
         cout << endl;
     }
     
     return 0;
 }
