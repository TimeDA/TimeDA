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
     freopen("C.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 bool palin(int64 num) {
     vector<int> digits;
     while (num > 0) {
         digits.pb(num % 10);
         num /= 10;
     }
     for (int i = 0; i < digits.size() / 2; ++i) {
         if (digits[i] != digits[digits.size() - i - 1]) return false;
     }
     return true;
 }
 
 int main()
 {
     initialize();
 
     vector<int64> numbers;
 
     for (int64 i = 1; i <= 10000000; ++i) {
         if (!palin(i)) {
             continue;
         }
         if (palin(i * i)) {
             numbers.pb(i * i);
         }
     }
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int64 a, b;
         cin >> a >> b;
         a -= 1;
         printf("Case #%d: %d\n", tt, upper_bound(all(numbers), b) - upper_bound(all(numbers), a));
     }
     
     return 0;
 }
