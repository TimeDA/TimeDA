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
 
 int greedy(const string& str) {
     std::vector<char> s;
     int res = 0;
     for (int i = 0; i < str.size(); ++i) {
         if (s.empty()) {
             s.push_back(str[i]);
         }
         else if (s.back() == str[i]) {
             res += 10;
             s.pop_back();
         } else {
             if (s.size() >= str.size() - i) {
                 res += 5;
                 s.pop_back();
             } else {
                 s.push_back(str[i]);
             }
         }
     }
     return res;
 }
 
 int simple(const string& str) {
     int n = str.size();
     int res = 0;
     for (int mask = 0; mask < (1 << str.size()); ++mask) {
         std::vector<char> s;
         int r = 0;
         for (int i = 0; i < n; ++i) {
             if ((mask & (1 << i)) > 0) {
                 s.push_back(str[i]);
             } else {
                 if (s.empty()) {
                     r = 0;
                     break;
                 } else {
                     r += (s.back() == str[i]) ? 10 : 5;
                     s.pop_back();
                 }
             }
         }
         res = max(res, r);
     }
     return res;
 }
 
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
 
     for (int tt = 1; tt <= T; ++tt) {
         string str;
         cin >> str;
         cout << "Case #" << tt << ": " << greedy(str) << "\n";
     }
     
     //for (int mask = 0; mask < (1 << 10); ++mask) {
     //    string str;
     //    for (int i = 0; i < 10; ++i) {
     //        str += (((1 << i) & mask) > 0) ? 'J' : 'C';
     //    }
     //    cerr << str << endl;
     //    if (greedy(str) != simple(str)) {
     //        cout << str << " " << greedy(str) << " " << simple(str) << endl;
     //    }
     //}
     
     return 0;
 }
