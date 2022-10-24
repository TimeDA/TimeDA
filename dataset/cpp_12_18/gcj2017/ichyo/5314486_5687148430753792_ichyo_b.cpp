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
 
 int search(int L, int N, int C, const vector<pair<int, int>>& ps) {
     vector<set<int>> cv(L);
     vector<set<int>> yv(L);
     REP(i, L) REP(j, N) yv[i].insert(j+1);
     REP(i, L) REP(j, C) cv[i].insert(j+1);
 
     int ans = 0;
     for(auto p : ps) {
         bool ok = false;
         vector<int> perm(L);
         REP(i, L) perm[i] = i;
         random_shuffle(perm.begin(), perm.end());
         for(int i : perm) {
             if(yv[i].count(p.first) && cv[i].count(p.second)) {
                 cv[i].erase(p.second);
                 yv[i].erase(p.first);
                 ok = true;
                 break;
             }
         }
         if(!ok) {
             random_shuffle(perm.begin(), perm.end());
             for(int i : perm) {
                 if(cv[i].count(p.second) && yv[i].size() > 0 && *yv[i].begin() <= p.first) {
                     cv[i].erase(p.second);
                     yv[i].erase(*yv[i].begin());
                     ok = true;
                     ans++;
                     break;
                 }
             }
         }
         if(!ok) {
             return INT_MAX;
         }
     }
     return ans;
 }
 void solve() {
     int N, C, M;
     cin >> N >> C >> M;
     vector<pair<int, int>> ps(M);
     REP(i, M) {
         cin >> ps[i].first >> ps[i].second;
     }
     sort(ps.begin(), ps.end());
     int lb = 0, ub = 1000;
     while(ub - lb > 1) {
         int mid = (lb + ub) / 2;
         if(search(mid, N, C, ps) != INT_MAX) {
             ub = mid;
         } else {
             lb = mid;
         }
     }
     cout << ub << " " << search(ub, N, C, ps) << endl;
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
 
