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
 
 const int MAX = 1000 + 5;
 int dyn[MAX][MAX][2];
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n;
         cin >> n;
         vector<int> seq;
         vector<int> sorted;
         for (int i = 0; i < n; ++i) {
             int num;
             cin >> num;
             seq.pb(num);
             sorted.pb(num);
         }
         sort(all(sorted));
 
         for (int i = 0; i < n; ++i) {
             seq[i] = lower_bound(all(sorted), seq[i]) - sorted.begin();
         }
 
 
         int l = -1, r = n;
         int res = 0;
         for (int i = 0; i < n; ++i) {
             int pos = -1;
             for (int j = 0; j < n; ++j) {
                 if (seq[j] == i) {
                     pos = j;
                 }
             }
             if ((pos - l) > (r - pos)) {
                 for (int j = pos; j + 1 < r; ++j) {
                     swap(seq[j], seq[j + 1]);
                     res += 1;
                 }
                 r -= 1;
             } else {
                 for (int j = pos; j - 1 > l; --j) {
                     swap(seq[j], seq[j - 1]);
                     res += 1;
                 }
                 l += 1;
             }
         }
 
         cout << "Case #" << tt << ": " << res << endl;
     }
     
     return 0;
 }
