// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define dump(x) 
 #endif
 
 class range {
     struct Iterator {
         int val, inc;
         int operator*() {return val;}
         bool operator!=(Iterator& rhs) {return val < rhs.val;}
         void operator++() {val += inc;}
     };
     Iterator i, n;
     public:
     range(int e) : i({0, 1}), n({e, 1}) {}
     range(int b, int e) : i({b, 1}), n({e, 1}) {}
     range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
     Iterator& begin() {return i;}
     Iterator& end() {return n;}
 };
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(6);
 }
 //}}}
 const double INF = 1e128;
 double calc2(int V, int X, int R, int C) {
     if(C == X) {
         return 1.0 * V / R;
     } else {
         return INF;
     }
 }
 double calc(int V, int X, int R0, int R1, int C0, int C1) {
     if(C1 == C0) {
         if(X != C0) return INF;
         int R = R0 + R1;
         return 1.0 * V / R;
     }
     if(min(C0, C1) <= X && X <= max(C0, C1)) {
         double a1 = 1.0 * V * (1.0 * C1 - X);
         double a2 = 1.0 * R0 * (1.0 * C1 - C0);
         double a = a1 / a2;
         double b = (1.0 * V - 1.0 * a * R0) / R1;
         if(a < -1e-9 || b < -1e-9) {
             cout << a << " " << b << endl;
             assert(false);
         }
         return max(a, b);
     } else {
         return INF;
     }
 }
 int parse() {
     string s;
     cin >> s;
     string t;
     REP(i, s.size()) if(s[i] != '.') t += s[i];
     return stoi(t);
 }
 void small() {
     int N;
     cin >> N;
     int V = parse();
     int X = parse();
     vector<int> R(N);
     vector<int> C(N);
     REP(i, N) {
         R[i] = parse();
         C[i] = parse();
         // cout <<"!" <<  R[i] << " " << C[i] << endl;
     }
     double res = INF;
     REP(i, N) REP(j, N) if (i != j) {
         res = min(res, calc(V, X, R[i], R[j], C[i], C[j]));
         assert(abs(calc(V, X, R[i], R[j], C[i], C[j]) - calc(V, X, R[j], R[i], C[j], C[i])) < 1e-6);
     }
     REP(i, N) {
         res = min(res, calc2(V, X, R[i], C[i]));
     }
     if(res == INF) {
         cout << "IMPOSSIBLE" << endl;
     } else {
         cout << res << endl;
     }
 }
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int testcase = 1; testcase <= TESTCASE; testcase++) {
         cout << "Case #" << testcase << ": ";
         small();
     }
     return 0;
 }
 
 /* vim:set foldmethod=marker: */
 
