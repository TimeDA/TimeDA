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
 #include <deque>
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
     freopen("1.in", "r", stdin);
     freopen("_.out", "w", stdout);
 }
 
 struct Position {
     Position(int pos_, int64 count_, bool start_):
         pos(pos_), count(count_), start(start_)
     { }
     int pos;
     int64 count;
     bool start;
 };
 
 bool operator < (const Position& x, const Position& y) {
     if (x.pos != y.pos) {
         return x.pos < y.pos;
     }
     return x.start > y.start;
 }
 
 int64 calc(int64 a, int64 b, int64 c, int64 n) {
     int64 d = b - a;
     return c * (n * d  - (d * (d - 1)) / 2);
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         int64 initialCost = 0;
         std::vector<Position> positions;
         int n, m;
         cin >> n >> m;
         for (int i = 0; i < m; ++i) {
             int a, b;
             int64 c;
             cin >> a >> b >> c;
             initialCost += calc(a, b, c, n);
 
             positions.push_back(Position(a, c, true));
             positions.push_back(Position(b, c, false));
         }
         sort(all(positions));
 
         int64 minCost = 0;
         deque<Position> q;
         for (auto pos: positions) {
             if (pos.start) {
                 q.push_back(pos);
             }
             else {
                 while (pos.count > 0) {
                     int64 amount = std::min(pos.count, q.back().count);
                     minCost += calc(q.back().pos, pos.pos, amount, n);
                     pos.count -= amount;
 
                     q.back().count -= amount;
                     if (q.back().count == 0) {
                         q.pop_back();
                     }
                 }
             }
         }
         cout << "Case #" << tt << ": " << initialCost - minCost << "\n";
     }
     
     return 0;
 }
