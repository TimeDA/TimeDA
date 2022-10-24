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
     cout.precision(12);
 }
 //}}}
 int R, C;
 // ModInt (ref. anta) {{{
 template<int MOD>
 struct ModInt{
     static const int Mod = MOD;
     unsigned val;
     ModInt():val(0){}
     ModInt(unsigned x):val(x%MOD){}
     ModInt(signed x) {
         int y = x % MOD;
         if(y < 0) y += MOD;
         val = y;
     }
     ModInt(signed long long x) {
         int y = x % MOD;
         if(y < 0) y += MOD;
         val = y;
     }
 
     ModInt &operator+=(ModInt rhs) {
         val += rhs.val;
         if(val >= MOD) val -= MOD;
         return *this;
     }
     ModInt &operator-=(ModInt rhs) {
         val += MOD - rhs.val;
         if(val >= MOD) val -= MOD;
         return *this;
     }
     ModInt &operator*=(ModInt rhs) {
         val = (unsigned long long)val * rhs.val % MOD;
         return *this;
     }
     ModInt &operator/=(ModInt rhs) {
         return *this *= rhs.inv();
     }
 
     ModInt inv() const {
         signed a = val, b = MOD, u = 1, v = 0;
         while(b) {
             signed t = a / b;
             a -= t * b; std::swap(a, b);
             u -= t * v; std::swap(u, v);
         }
         if(u < 0) u += MOD;
         ModInt res;
         res.val = u;
         return res;
     }
 
     ModInt operator+(ModInt rhs) const {
         return ModInt(*this) += rhs;
     }
     ModInt operator-(ModInt rhs) const {
         return ModInt(*this) -= rhs;
     }
     ModInt operator*(ModInt rhs) const {
         return ModInt(*this) *= rhs;
     }
     ModInt operator/(ModInt rhs) const {
         return ModInt(*this) /= rhs;
     }
 
     // compare
     bool operator==(ModInt rhs) const {
         return val == rhs.val;
     }
     bool operator!=(ModInt rhs) const {
         return val != rhs.val;
     }
     bool operator< (ModInt rhs) const {
         return val <  rhs.val;
     }
     bool operator<=(ModInt rhs) const {
         return val <= rhs.val;
     }
     bool operator> (ModInt rhs) const {
         return val >  rhs.val;
     }
     bool operator>=(ModInt rhs) const {
         return val >= rhs.val;
     }
 };
 template<int MOD>
 ostream& operator << (ostream& os, const ModInt<MOD> m) {
     return os << m.val;
 }
 template<int MOD, typename T>
 ModInt<MOD> pow(ModInt<MOD> a, T b) {
     if(b == 0) {
         return 1;
     } else {
         auto w = pow(a*a, b/2);
         if(b&1) w *= a;
         return w;
     }
 }
 // }}}
 typedef ModInt<1000000007> mint;
 mint ans;
 int grid[10][10];
 bool check(int x, int y) {
     int cnt = 0;
     REP(r, 4) {
         int nx = (x + dx[r] + C) % C;
         int ny = y + dy[r];
         if(valid(nx, C) && valid(ny, R)) {
             if(grid[ny][nx] == grid[y][x]) {
                 cnt++;
             }
         }
     }
     return cnt == grid[y][x];
 }
 void rec(int x, int y) {
     if(y == R) {
         bool ok = true;
         REP(y, R) REP(x, C) ok &= check(x, y);
         REP(bx, C) {
             ok &= check(bx, R-1);
         }
         if(ok) {
             ans += 1;
         }
     } else {
         for(int c = 1; c <= 3; c++) {
             grid[y][x] = c;
             bool ok = true;
             if(y - 1 >= 0) ok &= check(x, y-1);
             int nx = x + 1;
             int ny = y;
             if(nx == C) { nx = 0; ny = y + 1; }
             if(ok) rec(nx, ny);
         }
     }
 }
 void solve() {
     cin >> R >> C;
     ans = 0;
     rec(0, 0);
     cout << ans.val << endl;
 }
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int testcase = 1; testcase <= TESTCASE; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
     return 0;
 }
 
 /* vim:set foldmethod=marker: */
 
