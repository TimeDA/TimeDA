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
 
 const int LEVEL_MAX = 13;
 const int HAND = 3;
 unsigned long long memo[LEVEL_MAX][HAND] = {};
 unsigned long long rec(int level, int hand) {
     unsigned long long & res = memo[level][hand];
     if(level == 0) {
         return (1UL << (16 * hand));
     }
     if(res != ULONG_MAX) {
         return res;
     }
     unsigned long long ans1 = rec(level-1, hand);
     unsigned long long ans2 = rec(level-1, (hand + 2) % 3);
     return res = ans1 + ans2;
 }
 
 const string base = "RPS";
 string create(int level, int hand) {
     if(level == 0) {
         return string(1, base[hand]);
     }
     string A = create(level-1, hand);
     string B = create(level-1, (hand+2)%3);
     if(A < B) {
         return A + B;
     } else {
         return B + A;
     }
 }
 
 void solve() {
     memset(memo, -1, sizeof(memo));
     int N, A, B, C;
     cin >> N >> A >> B >> C;
     unsigned long long input = ((unsigned long long)C << 32) | ((unsigned long long)B << 16) | A;
     string ans;
     for(int hand = 0; hand < 3; hand++) {
         unsigned long long check = rec(N, hand);
         if(input == check) {
             string opt = create(N, hand);
             if(ans == "" || opt < ans) {
                 ans = opt;
             }
         }
     }
     if(ans == "") {
         cout << "IMPOSSIBLE" << endl;
     } else {
         cout << ans << endl;
         int cnt[3] = {};
         REP(i, ans.size()) REP(j, 3) if(ans[i] == base[j]) cnt[j]++;
         assert(cnt[0] == A);
         assert(cnt[1] == B);
         assert(cnt[2] == C);
     }
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     REP(casenum, T) {
         cout << "Case #" << casenum + 1 << ": ";
         solve();
     }
 
     return 0;
 }
 
