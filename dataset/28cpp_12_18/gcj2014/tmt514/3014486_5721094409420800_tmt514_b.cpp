#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 #include <cassert>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int n, cs;
 int a[1005], srt[1005];
 bool cmp(int x, int y) { return a[x] < a[y]; }
 int dp[1005][1005];
 int left[1005];
 
 int solve(int L, int R) {
   if(L==R) return abs(L-srt[n-1]);
   if(L>R) return 0;
   if(dp[L][R]!=-1) return dp[L][R];
   int &v = dp[L][R], cur = n-(R-L+1);
   int vL = solve(L+1, R), vR = solve(L, R-1);
   vL += left[srt[cur]];
   vR += (R-L) - left[srt[cur]];
   v = min(vL, vR);
   return v;
 }
 
 void solve() {
   scanf("%d", &n);
   for(int i=0;i<n;i++) scanf("%d", &a[i]);
   for(int i=0;i<n;i++) srt[i] = i;
   sort(srt, srt+n, cmp);
   for(int i=0;i<n;i++) left[i] = 0;
   for(int i=0;i<n;i++) for(int j=0;j<i;j++) left[i] += (a[j] > a[i]);
   //memset(dp, -1, sizeof(dp));
   //int ans = solve(0, n-1);
   int ans = 0;
   for(int i=0;i<n;i++) ans += min(left[srt[i]], n-i-1-left[srt[i]]);
   printf("Case #%d: %d\n", cs, ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
