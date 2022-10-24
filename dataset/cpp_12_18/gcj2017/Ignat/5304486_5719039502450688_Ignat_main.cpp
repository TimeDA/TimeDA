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
 #include <unordered_map>
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
 
 struct State {
     State() { }
     State(int hd_, int dd_, int he_, int de_)
         : hd(hd_), dd(dd_), he(he_), de(de_)
     { }
     int hd, dd, he, de;
 };
 
 bool operator == (const State& lhs, const State& rhs) {
     return lhs.hd == rhs.hd && lhs.dd == rhs.dd && lhs.he == rhs.he && lhs.de == rhs.de;
 }
 
 namespace std {
 template<>
 struct hash<State> {
     size_t operator () (const State& s) const {
         return (((s.hd * 167 + s.dd) * 23179 + s.he) * 17923) + s.de;
     }
 };
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST " << tt << endl;
         int hd, dd, he, de, b, d;
         cin >> hd >> dd >> he >> de >> b >> d;
 
         unordered_map<State, int> states;
         states.insert(make_pair(State(hd, dd, he, de), 0));
 
         auto insert = [&] (const State& s, int r) {
             auto it = states.find(s);
             if (it != states.end()) {
                 return;
             }
             //cerr << s.hd << " " << s.dd << " " << s.he << " " << s.de << " with res " << r << endl;
             states.insert(make_pair(s, r));
         };
 
         int res = 0;
         bool ok = false;
         while (!ok) {
             res += 1;
             bool have = false;
             auto copyStates = states;
             for (auto pair : copyStates) {
                 if (pair.second < res - 1) {
                     continue;
                 }
 
                 have = true;
 
                 auto s = pair.first;
 
                 if (s.dd >= s.he) {
                     //cerr << "WIN STATE: " << s.hd << " " << s.dd << " " << s.he << " " << s.de << " with res " << res << endl;
                     ok = true;
                     break;
                 }
                 
                 if (s.hd > s.de) {
                     insert(State(s.hd - s.de, s.dd, s.he - s.dd, s.de), res);
                     insert(State(s.hd - s.de, s.dd + b, s.he, s.de), res);
                 }
                 if (hd > s.de) {
                     insert(State(hd - s.de, s.dd, s.he, s.de), res);
                 }
 
                 int newDe = max(0, s.de - d);
                 if (s.hd > newDe) {
                     insert(State(s.hd - newDe, s.dd, s.he, newDe), res);
                 }
             }
 
             if (!have) {
                 break;
             }
         }
 
         cout << "Case #" << tt << ": ";
         if (!ok) {
             cout << "IMPOSSIBLE";
         } else {
             cout << res;
         }
         cout << endl;
     }
     
     return 0;
 }
