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
         set<int> first;
         set<int> res;
         int row;
         
         cin >> row; row -= 1;
         for (int i = 0; i < 4; ++i) {
             for (int j = 0; j < 4; ++j) {
                 int num;
                 cin >> num;
                 if (i == row) {
                     first.insert(num);
                 }
             }
         }
         
         cin >> row; row -= 1;
         for (int i = 0; i < 4; ++i) {
             for (int j = 0; j < 4; ++j) {
                 int num;
                 cin >> num;
                 if (i == row && first.count(num) > 0) {
                     res.insert(num);
                 }
             }
         }
 
         printf("Case #%d: ", tt);
         if (res.empty()) {
             printf("Volunteer cheated!\n");
         } else if (res.size() > 1) {
             printf("Bad magician!\n");
         } else {
             printf("%d\n", *res.begin());
         }
     }
     
     return 0;
 }
