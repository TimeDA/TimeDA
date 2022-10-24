
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <iostream>
 #include <string>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 
 int n;
 
 struct K {
   int to, at, cost;
 };
 
 K ks[1010][2];
 bool used[1010][2];
 
 const int INF = 1000000000;
 int solve(int pos, int t, int len, string route) {
   if(pos == 0 && len == 2*n) {
     return t;
   }
     // cerr << "> " << t << " " << route << endl;
   int res = INF;
   REP(i, 2) {
     if(!used[pos][i]) {
       used[pos][i] = true;
       int newT = t + (ks[pos][i].at - t % 24);
       if(newT < t) {
         newT += 24;
       }
       route.push_back('0'+i);
       res = min(res, solve(ks[pos][i].to, newT + ks[pos][i].cost, len+1, route));
       route.pop_back();
       used[pos][i] = false;
     }
   }
   return res;
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     scanf("%d", &n);
     REP(i, n) {
       REP(j, 2) {
         scanf("%d%d%d", &ks[i][j].to, &ks[i][j].at, &ks[i][j].cost);
         ks[i][j].to--;
       }
     }
     memset(used, 0, sizeof used);
     int res = solve(0, 0, 0, "");
     printf("Case #%d: %d\n", iCase+1, res);
   }
   return 0;
 }
 
