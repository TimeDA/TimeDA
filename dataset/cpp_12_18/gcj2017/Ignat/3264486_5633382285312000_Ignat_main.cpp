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
 
 vector<int> solve(vector<int> digits) {
     for (int i = 0; i + 1 < digits.size(); ++i) {
         if (digits[i + 1] < digits[i]) {
             digits[i] -= 1;
             for (int j = i + 1; j < digits.size(); ++j) {
                 digits[j] = 9;
             }
             return solve(digits);
         }
     }
     return digits;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int64 n;
         cin >> n;
 
         vector<int> digits;
         while (n > 0) {
             digits.pb(n % 10);
             n /= 10;
         }
         reverse(all(digits));
 
         vector<int> solution = solve(digits);
         
         int64 res = 0;
         for (int i = 0; i < solution.size(); ++i) {
             res = res * 10 + solution[i];
         }
 
         cout << "Case #" << tt << ": " << res << "\n";
     }
     
     return 0;
 }
