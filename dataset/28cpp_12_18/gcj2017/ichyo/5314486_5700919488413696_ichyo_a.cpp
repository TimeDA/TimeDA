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
 
 
 const int MAX_N = 101;
 int P;
 int dp[MAX_N][MAX_N][MAX_N];
 int dfs(int a, int b, int c, int cur) {
     if(a + b + c == 0) {
         return 0;
     }
     if(dp[a][b][c] != -1) {
         return dp[a][b][c];
     }
     int base = (cur == 0 ? 1 : 0);
     int res = 0;
     if(a > 0) {
         res = max(res, base + dfs(a-1, b, c, (cur+1)%P));
     }
     if(b > 0) {
         res = max(res, base + dfs(a, b-1, c, (cur+2)%P));
     }
     if(c > 0) {
         res = max(res, base + dfs(a, b, c-1, (cur+3)%P));
     }
     return dp[a][b][c] = res;
 }
 
 void solve() {
     int N;
     cin >> N;
     cin >> P;
     vector<int> G(N);
     REP(i, N) cin >> G[i];
     memset(dp, -1, sizeof(dp));
     map<int, int> cnt;
     REP(i, N) cnt[ G[i] % P ] ++;
     int ans = cnt[0] + dfs(cnt[1], cnt[2], cnt[3], 0);
     cout << ans << endl;
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     for(int testcase = 1; testcase <= T; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
     return 0;
 }
 
