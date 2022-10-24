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
 
 pair<int, int> get_range(int unit, int x) {
     int ub = (10 * x) / (9 * unit);
     int lb = (10 * x + 11 * unit - 1) / (11 * unit);
     if(lb <= 0) lb = 1;
     return make_pair(lb, ub);
 }
 void solve() {
     int N, P;
     cin >> N >> P;
     vector<int> unit(N);
     REP(i, N) cin >> unit[i];
     vector<vector<int>> packs(N);
     REP(i, N) REP(_, P) {
         int x;
         cin >> x;
         packs[i].push_back(x);
     }
 
     vector<vector<pair<int, int>>> ranges(N);
     for(int i = 0; i < N; i++) {
         for(int j = 0; j < P; j++) {
             auto r = get_range(unit[i], packs[i][j]);
             if(r.first <= r.second) {
                 ranges[i].push_back(r);
             }
         }
     }
 
     set<int> all_units;
     REP(i, N) for(auto r : ranges[i]) {
         all_units.insert(r.first);
         all_units.insert(r.second);
     }
     
     map<int, vector<int>> cache[100];
     REP(i, N) {
         for(auto r : ranges[i]) {
             auto& v = cache[i][r.first];
             v.push_back(r.second);
         }
     }
 
     multiset<int> que[100];
     int answer = 0;
     for(auto u : all_units) {
         REP(i, N) {
             while(que[i].size() > 0 && *que[i].begin() < u) {
                 que[i].erase(que[i].begin());
             }
         }
 
         REP(i, N) for(auto s : cache[i][u]) {
             que[i].insert(s);
         }
         int min_size = INT_MAX;
         REP(i, N) min_size = min(min_size, (int)que[i].size());
         answer += min_size;
 
         REP(i, N) REP(_, min_size) {
             assert(que[i].size() > 0);
             que[i].erase(que[i].begin());
         }
     }
     cout << answer << endl;
 }
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int test = 1; test <= TESTCASE; test++) {
         cout << "Case #" << test << ": ";
         solve();
     }
     return 0;
 }
 
