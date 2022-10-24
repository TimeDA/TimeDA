
 #include <cassert>
 #include <cstring>
 #include <cstdio>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <algorithm>
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
 using namespace std;
 typedef long long ll;
 
 
 // 0 <= vL < nL
 // 0 <= vR < nR
 
 class Matching {
 private:
   int nL, nR;
   vector<vector<int> > g; // g[vL][i] = vR
   vector<int> matching, dist;
   bool dfs(int vL) {
     REP(i, g[vL].size()){
       int vR = g[vL][i];
       int nextL = matching[vR];
       if(nextL == -1 || (dist[nextL] == dist[vL] + 1 && dfs(nextL))){
         matching[vR] = vL;
         matching[vL] = vR;
         return true;
       }
     }
     dist[vL] = -3;
     return false;
   }
   bool bfs() {
     bool res = false;
     queue<int> q;
     dist.assign(nL, -3);
     REP(vL, nL)
       if(matching[vL] == -1)
         q.push(vL), dist[vL] = 0;
     while(!q.empty()){
       int vL = q.front(); q.pop();
       REP(i, g[vL].size()){
         int nextL = matching[g[vL][i]];
         if(nextL == -1)
           res = true;
         else if(dist[nextL] == -3)
           q.push(nextL), dist[nextL] = dist[vL]+1;
       }
     }
     return res;
   }
 public:
   Matching(int nL, int nR) : nL(nL), nR(nR), g(nL) {}
   void addEdge(int vL, int vR) { g[vL].push_back(nL+vR); }
   int match() {
     int res = 0;
     for(matching.assign(nL+nR, -1); bfs(); )
       REP(vL, nL)
         res += matching[vL] == -1 && dfs(vL);
     return res;
   }
   int partner(int vR) { return matching[nL+vR]; }
 };
 
 int n;
 int ans;
 char buf[30][30];
 vector<int> vs;
 
 bool g[30][30];
 bool isOk() {
   REP(i, n) REP(j, n) {
     g[i][j] = buf[i][j] == '1' || ((vs[i]>>j)&1) == 1;
   }
   {
     Matching m(n, n);
     REP(i2, n) REP(j2, n){
       if(g[i2][j2]) {
         m.addEdge(i2, j2);
       }
     }
     if(m.match() != n)
       return false;
   }
   
   REP(i, n) {
     REP(j, n) {
       if (!g[i][j]) {
         Matching m(n, n);
         REP(i2, n) REP(j2, n){
           if(i2 == i || j2 == j)
             continue;
           if(g[i2][j2]) {
             m.addEdge(i2, j2);
           }
         }
         if(m.match() == n-1)
           return false;
       }
     }
   }
   return true;
 }
 
 void solve(int i, int cur) {
   if(cur >= ans)
     return;
   if(i == n){
     if(isOk()){
       ans = cur;
       REP(k, n){
         cerr << vs[k] << " ";
       }
       cerr << endl;
     }
   } else {
     REP(pat, 1 << n) {
       vs.push_back(pat);
       solve(i+1, cur + __builtin_popcount(pat));
       vs.pop_back();
     }
   }
 }
 
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     cerr << "case " << iCase+1 << endl;
     scanf("%d", &n);
     REP(i, n){
       scanf("%s", buf[i]);
     }
     vs.clear();
     ans = n*n;
     solve(0, 0);
     printf("Case #%d: %d\n", iCase+1, ans);
   }
   return 0;
 }
