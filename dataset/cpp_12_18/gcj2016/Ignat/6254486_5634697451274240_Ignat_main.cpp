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
 
 typedef pair<string, bool> sb;
 map<sb, int> solution;
 
 int solve(const string& str, bool plus) {
     if (str.size() == 0) {
         return 0;
     }
     //cerr << str << " " << plus << endl;
     auto p = mp(str, plus);
     if (solution.find(p) != solution.end()) {
         return solution[p];
     }
 
     int res = 0;
     int pos = int(str.size()) - 1;
     while (pos >= 0 && ((plus && str[pos] == '+') || (!plus && str[pos] == '-'))) {
         pos --;
     }
     
     if (pos == str.size() - 1) {
         while (pos >= 0 && ((!plus && str[pos] == '+') || (plus && str[pos] == '-'))) {
             pos --;
         }
         if (pos >= str.size() - 1) {
             cerr << "AAAA: " << str << " " << pos << endl; 
         }
         assert(pos < int(str.size()) - 1);
         res = 1 + solve(str.substr(0, pos + 1), !plus);
     } else {
         if (pos >= str.size() - 1) {
             cerr << "AAAA: " << str << " " << pos << endl; 
         }
         assert(pos < int(str.size()) - 1);
         res = solve(str.substr(0, pos + 1), plus);
     }
     solution[p] = res;
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
         int res = solve(str, true);
         cout << "Case #" << tt << ": " << res << endl;
     }
     
     return 0;
 }
