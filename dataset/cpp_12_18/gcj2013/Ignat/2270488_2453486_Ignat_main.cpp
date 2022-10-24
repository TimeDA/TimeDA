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
     freopen("A-small-attempt0.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 int check(const vector<char>& v) {
     int oC = 0, xC = 0, dC = 0;
     for (int i = 0; i < v.size(); ++i) {
         if (v[i] == '.') dC ++;
         if (v[i] == 'O') oC ++;
         if (v[i] == 'X') xC ++;
     }
     if (dC != 0) {
         return -1;
     }
     if (oC >= 3 && xC == 0) return 1;
     if (xC >= 3 && oC == 0) return 0;
     return -1;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     vector<vector<char>> table(4, vector<char>(4, 0));
     for (int tt = 1; tt <= T; ++tt) {
         bool full = true;
         for (int i = 0; i < 4; ++i) {
             string str;
             cin >> str;
             for (int j = 0; j < 4; ++j) {
                 table[i][j] = str[j];
                 if (str[j] == '.') full = false;
             }
         }
         int res = -1, c;
         for (int i = 0; i < 4; ++i) {
             c = check(table[i]);
             if (c != -1) res = c;
 
             vector<char> vert;
             for (int j = 0; j < 4; ++j) {
                 vert.push_back(table[j][i]);
             }
             c = check(vert);
             if (c != -1) res = c;
         }
         
         vector<char> diag1, diag2;
         for (int i = 0; i < 4; ++i) {
             diag1.pb(table[i][i]);
             diag2.pb(table[i][3 - i]);
         }
         c = check(diag1);
         if (c != -1) res = c;
         c = check(diag2);
         if (c != -1) res = c;
 
         string r;
         if (res == -1) {
             r = full ? "Draw" : "Game has not completed";
         }
         else if (res == 0) {
             r = "X won";
         }
         else {
             r = "O won";
         }
         printf("Case #%d: %s\n", tt, r.c_str());
     }
     
     return 0;
 }
