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
     
 const int MAX = 15;
 map<vector<int>, string> solution[MAX];
 
 int winner(int a, int b) {
     if (a > b) {
         swap(a, b);
     }
     if (a == 0 && b == 1) {
         return 0;
     }
     if (a == 1 && b == 2) {
         return 1;
     }
     if (a == 0 && b == 2) {
         return 2;
     }
 }
 
 int main()
 {
     initialize();
 
     solution[1][{1, 1, 0, 0}] = "PR";
     solution[1][{0, 1, 1, 1}] = "RS";
     solution[1][{1, 0, 1, 2}] = "PS";
     for (int n = 2; n <= 12; ++n) {
         //cerr << "N = " << n << endl;
         for (auto it = solution[n - 1].begin(); it != solution[n - 1].end(); ++it) {
             for (auto jt = solution[n - 1].begin(); jt != solution[n - 1].end(); ++jt) {
                 const auto& a = it->first;
                 const auto& b = jt->first;
                 if (a[3] == b[3]) {
                     continue;
                 }
                 vector<int> c(4, 0);
                 for (int i = 0; i < 3; ++i) {
                     c[i] = a[i] + b[i];
                 }
                 c[3] = winner(a[3], b[3]);
 
                 auto kt = solution[n].find(c);
                 auto res = it->second + jt->second;
                 if (kt == solution[n].end()) {
                     solution[n][c] = res;
                 } else {
                     solution[n][c] = min(solution[n][c], res);
                 }
             }
         }
         //cerr << "SIZE: " << solution[n].size() << endl;
         //for (auto it = solution[n].begin(); it != solution[n].end(); ++it) {
         //    const auto& a = it->first;
         //    for (int i = 0; i < a.size(); ++i) {
         //        cerr << a[i] << " ";
         //    }
         //    cerr << it->second << endl;
         //}
     }
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int n;
         cin >> n;
         vector<int> x(4, 0);
         for (int i = 0; i < 3; ++i) {
             cin >> x[i];
         }
         swap(x[0], x[1]);
 
         string res;
         for (int j = 0; j < 3; ++j) {
             x[3] = j;
             if (solution[n].find(x) != solution[n].end()) {
                 if (res.empty()) {
                     res = solution[n][x];
                 } else {
                     res = min(res, solution[n][x]);
                 }
             }
         }
 
         if (res.empty()) {
             res = "IMPOSSIBLE";
         }
 
         cout << "Case #" << tt << ": " << res << "\n";
     }
     
     return 0;
 }
