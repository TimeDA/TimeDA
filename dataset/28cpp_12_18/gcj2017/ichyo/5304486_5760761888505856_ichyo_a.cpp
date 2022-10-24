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
 
 void solve() {
     cout << endl;
     int H, W;
     cin >> H >> W;
     string grid[50];
     REP(y, H) cin >> grid[y];
 
     map<int, vector<int>> points;
     REP(y, H){
         REP(x, W) {
             if(grid[y][x] != '?') {
                 points[y].push_back(x);
             }
         }
     }
     vector<int> rows;
     for(auto ps : points) { rows.push_back(ps.first); }
 
     auto get_chars = [&](int y1) {
         vector<char> chars(W);
         vector<int> cols = points[y1];
         cols.push_back(W);
         for(int i = 0; i+1 < cols.size(); i++) {
             for(int x = cols[i]; x < cols[i+1]; x++) {
                 chars[x] = grid[y1][cols[i]];
             }
         }
         for(int x = 0; x < cols[0]; x++) {
             chars[x] = grid[y1][cols[0]];
         }
         return chars;
     };
 
     vector<vector<char>> answer(H, vector<char>(W));
     {
         int y1 = rows[0];
         auto chars = get_chars(y1);
         for(int y = 0; y < y1; y++) {
             answer[y] = chars;
         }
     }
     rows.push_back(H);
     for(int i = 0; i+1 < rows.size(); i++) {
         int y1 = rows[i];
         int y2 = rows[i+1];
         auto chars = get_chars(y1);
         for(int y = y1; y < y2; y++) {
             answer[y] = chars;
         }
     }
     for(int i = 0; i < H; i++) {
         string s;
         REP(x, W) s += answer[i][x];
         cout << s << endl;
     }
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
 
