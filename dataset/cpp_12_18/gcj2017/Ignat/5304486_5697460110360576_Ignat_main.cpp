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
 
 typedef pair<int, int> ii;
 
 int divUp(int a, int b) {
     int res = a / b;
     if (a % b != 0) {
         res += 1;
     }
     return res;
 }
 
 int divUpStrong(int a, int b) {
     return  a / b + 1;
 }
 
 struct Event {
     Event() {}
     Event(int x_, int t_, bool isOpen_)
         : x(x_), t(t_), isOpen(isOpen_)
     { }
     int x;
     int t;
     bool isOpen;
 };
 
 bool operator < (const Event& lhs, const Event& rhs) {
     if (lhs.x != rhs.x) {
         return lhs.x < rhs.x;
     }
     return lhs.isOpen < rhs.isOpen;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
     for (int tt = 1; tt <= T; ++tt) {
         cerr << "TEST: " << tt << endl;
         int n, m;
         cin >> n >> m;
 
         vector<int> p(n);
         for (int i = 0; i < n; ++i) {
             cin >> p[i];
         }
 
         vector<vector<ii>> segments(n, vector<ii>(m));
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 int num;
                 cin >> num;
 
                 segments[i][j] = 
                     ii(
                         divUp(num * 10, 11 * p[i]),
                         divUpStrong(num * 10, 9 * p[i])
                     );
 
                 //cerr << "i: " << i << ", (" << segments[i][j].first << ", " << segments[i][j].second << ")" << endl;
             }
         }
 
         vector<Event> events;
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 auto s = segments[i][j];
                 events.pb(Event(s.first, i, true));
                 events.pb(Event(s.second, i, false));
             }
         }
 
         sort(all(events));
 
         int nonZero = 0;
         vector<int> counters(n, 0);
         vector<int> skip(n, 0);
 
         auto add = [&] (int t, int val, bool s = false) {
             if (val == -1 && skip[t] && !s) {
                 skip[t] -= 1;
                 return;
             }
             if (counters[t] == 0 && val > 0) {
                 nonZero += 1;
             }
             counters[t] += val;
             if (counters[t] == 0 && val < 0) {
                 nonZero -= 1;
             }
         };
         
         int res = 0;
         for (int i = 0; i < events.size(); ++i) {
             auto e = events[i];
             add(e.t, e.isOpen ? 1 : -1);
             if (nonZero == n) {
                 res += 1;
                 for (int j = 0; j < n; ++j) {
                     add(j, -1, true);
                     skip[j] += 1;
                 }
             }
         }
 
         cout << "Case #" << tt << ": " << res << endl;
 
     }
     
     return 0;
 }
