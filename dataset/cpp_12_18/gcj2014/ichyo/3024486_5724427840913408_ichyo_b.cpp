#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 int N;
 int P, Q;
 int G[105];
 int H[105];
 int memo[105][205][20000 + 5];
 int rec(const int idx, const int hp, const int turn) {
     if(idx == N) return 0;
     if(hp <= 0) {
         return rec(idx + 1, H[idx + 1], turn);
     }
     if(memo[idx][hp][turn] != -1) return memo[idx][hp][turn];
     int nturn = turn + (hp + Q - 1) / Q;
     if(nturn > 20000) nturn = 20000;
     int res = rec(idx + 1, H[idx + 1], nturn);
     if(hp - P <= 0) {
         if(turn > 0) {
             res = max(res, G[idx] + rec(idx + 1, H[idx + 1], turn - 1));
         }
         res = max(res, G[idx] + rec(idx + 1, H[idx + 1] - Q, turn));
     }
     if(turn > 0 && hp - P > 0) {
         res = max(res, rec(idx, hp - P, turn - 1));
     }
     if(hp - P - Q > 0) {
         res = max(res, rec(idx, hp - P - Q, turn));
     }
     if(hp - Q > 0) {
         int nturn = turn + 1;
         if(nturn > 20000) nturn = 20000;
         res = max(res, rec(idx, hp - Q, nturn));
     }
     return memo[idx][hp][turn] = res;
 }
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++){
         printf("Case #%d: ", casenum);
         memset(memo, -1, sizeof(memo));
         cin >> P >> Q >> N;
         REP(i, N) cin >> H[i] >> G[i];
         cout << rec(0, H[0], 0) << endl;
     }
     return 0;
 }
 
