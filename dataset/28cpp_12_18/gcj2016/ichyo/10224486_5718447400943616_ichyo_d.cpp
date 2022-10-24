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
 
 void solve() {
     int N;
     cin >> N;
     assert(N <= 4);
     string input[4];
     REP(i, N) {
         cin >> input[i];
     }
     int igrid[4][4] = {};
     REP(i, N) REP(j, N) igrid[i][j] = (input[i][j] == '1');
     int answer = INT_MAX;
     REP(s, (1 << N * N)) {
         int grid[4][4];
         REP(i, N) REP(j, N) {
             int id = i * N + j;
             grid[i][j] = (s >> id & 1);
         }
         bool valid = true;
         REP(i, N) REP(j, N) if(igrid[i][j] && !grid[i][j]) valid = false;
         if(!valid) continue;
         int cost = 0;
         REP(i, N) REP(j, N) if(!igrid[i][j] && grid[i][j]) cost ++;
 
         bool worker[4] = {};
         bool pc[4] = {};
         function<bool(int)> dfs = [&](int k){
             if(k == N) {
                 return true;
             }
             REP(i, N) if(!worker[i]) {
                 bool ok = false;
                 REP(j, N) if(!pc[j] && grid[i][j]) {
                     ok = true;
                 }
                 if(!ok) return false;
             }
             REP(i, N) if(!worker[i]) {
                 REP(j, N) if(!pc[j] && grid[i][j]) {
                     worker[i] = true;
                     pc[j] = true;
                     if(!dfs(k+1)) return false;
                     worker[i] = false;
                     pc[j] = false;
                 }
             }
             return true;
         };
         bool ret = dfs(0);
         if(ret) {
             answer = min(answer, cost);
         }
     }
     cout << answer << endl;
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
 
