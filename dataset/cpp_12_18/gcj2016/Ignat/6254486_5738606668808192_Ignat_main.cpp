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
 
 int n, j;
 
 vector<int64> numbers;
 vector<int64> res;
 vector<vector<int64>> resdivs;
 
 void add(int x) {
     for (int i = 2; i <= 10; ++i) {
         numbers[i] = numbers[i] * i + x;
     }
 }
 
 void remove(int x) {
     for (int i = 2; i <= 10; ++i) {
         numbers[i] = numbers[i] / i;
     }
 }
 
 bool prime(int64 num, int64& div) {
     for (int64 x = 2; x * x <= num; ++x) {
         if (num % x == 0) {
             div = x;
             return false;
         }
     }
     return true;
 }
 
 void generate(int pos) {
     if (pos == n - 1) {
         add(1);
         bool ok = true;
         int notOk = 0;
         vector<int64> divs;
         for (int i = 2; i <= 10; ++i) {
             divs.pb(0);
             if (prime(numbers[i], divs[divs.size() - 1])) {
                 ok = false;
                 break;
             }
         }
         if (ok) {
             res.pb(numbers[10]);
             resdivs.pb(divs);
         }
         remove(1);
         return;
     }
 
     if (res.size() == j) {
         return;
     }
 
     for (int a = 0; a <= 1; ++a) {
         add(a);
         generate(pos + 1);
         remove(a);
     }
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     assert(T == 1);
     cout << "Case #1:" << endl;
 
     cin >> n >> j;
     numbers.resize(11);
     for (int i = 2; i <= 10; ++i) {
         numbers[i] = 1;
     }
 
     generate(1);
 
     for (int i = 0; i < j; ++i) {
         cout << res[i];
         for (auto x : resdivs[i]) {
             cout << " " << x;
         }
         cout << endl;
 
     }
 
     return 0;
 }
