// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define error(args...) 
 #endif
 
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
 
 pair<LL, LL> slow(LL N, LL K) {
     set<LL> s;
     s.insert(0);
     s.insert(N + 1);
     // 1..N
     pair<LL, LL> last_opt;
     REP(iter, K) {
         pair<LL, LL> opt = make_pair(-1, -1);
         LL idx = -1;
         for(LL i = 1; i <= N; i++) {
             // find x (<= i)
             LL l = *(--s.upper_bound(i));
             LL ld = i - l - 1;
             // find x (>= i)
             LL r = *(s.lower_bound(i));
             LL rd = r - i - 1;
             if(ld != -1 && rd != -1) {
                 auto p = make_pair(min(ld, rd), max(ld, rd));
                 if(opt < p) {
                     opt = p;
                     idx = i;
                 }
             }
         }
         assert(idx != -1);
         // error(iter, idx, opt.first, opt.second, N);
         // cerr << opt.first << " " << opt.second << endl;
         s.insert(idx);
         last_opt = opt;
     }
     return last_opt;
 }
 
 pair<LL, LL> fast(LL N, LL K) {
     map<LL, LL> m;
     set<LL> s;
     s.insert(N);
     m[N] = 1;
     while(s.size() > 0) {
         LL k = *(--s.end());
         LL v = m[k];
         s.erase(k);
         auto next = make_pair((k-1)/2, (k-1) - (k-1)/2);
         if(v >= K) {
             return next;
         } else {
             K -= v;
         }
         m[next.first] += v;
         m[next.second] += v;
         s.insert(next.first);
         s.insert(next.second);
     }
     assert(false);
 }
 
 pair<LL, LL> solve(LL N, LL K) {
     //return slow(N, K);
     return fast(N, K);
 }
 
 void solve() {
     LL N, K;
     cin >> N >> K;
     auto answer = solve(N, K);
     cout << answer.second << " " << answer.first << endl;
 }
 
 int main(){
     iostream_init();
     // assert(fast(11851, 123) == slow(11851, 123));
     // REP(_, 10) {
     //     int n = rand() % 10000 + 1;
     //     int k = rand() % n + 1;
     //     assert(fast(n, k) == slow(n, k));
     // }
     int TESTCASE;
     cin >> TESTCASE;
     for(int testcase = 1; testcase <= TESTCASE; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
     return 0;
 }
 
