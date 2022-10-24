#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <vector>
 #include <algorithm>
 #define SZ(x) ((int)(x).size())
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
 using namespace std;
 typedef long long LL;
 
 int cs;
 const int M = 1005;
 int A[M], B[M], sum[M];
 int cur[M];
 int N, K;
 
 void solve() {
   memset(A, 0, sizeof(A));
   memset(B, 0, sizeof(B));
   memset(cur, 0, sizeof(cur));
   memset(sum, 0, sizeof(sum));
 
   scanf("%d%d", &N, &K);
   for(int i=K;i<=N;i++)
     scanf("%d", &sum[i]);
   
   for(int i=K+1;i<=N;i++) {
     int t = (i-1)%K;
     cur[t] += (sum[i] - sum[i-1]);
     A[t] = max(A[t], cur[t]);
     B[t] = min(B[t], cur[t]);
   }
 
   int target = sum[K];
   for(int i=0;i<K;i++) {
     target -= B[i];
     A[i] -= B[i];
   }
   target = (target%K+K)%K;
   
   int mis = 0;
   int mxs = 0;
   for(int i=0;i<K;i++) mxs = max(mxs, A[i]);
   for(int i=0;i<K;i++) mis += mxs - A[i];
   int ans = 0;
   if (target <= mis) ans = mxs;
   else { ans = mxs+1; }
   
   printf("Case #%d: ", cs);
   printf("%d\n", ans);
   //printf("%d\n", dp[target]);
   fprintf(stderr, "Case #%d: ", cs);
   fprintf(stderr, "%d\n", ans);
   //fprintf(stderr, "%d\n", dp[target]);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
