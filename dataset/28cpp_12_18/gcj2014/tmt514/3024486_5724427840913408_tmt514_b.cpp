#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 typedef long long LL;
 
 int cs;
 int P, Q, N;
 int H[105], G[105];
 int dp[2][105][505][12];
 inline void update(int &x, int v) {
   if(x<v) x=v;
 }
 
 int mh[105][2];
 void solve() {
   scanf("%d%d%d", &P, &Q, &N);
   for(int i=0;i<N;i++) scanf("%d%d", &H[i], &G[i]);
   int u = 0;
   int rlim = 0;
   for(int i=0;i<N;i++) rlim += (H[i]+Q-1)/Q;
   for(int i=0;i<N;i++) {
     mh[i][0] = ((H[i]-1)%(P+Q) + P-1)/ P;
     mh[i][1] = (H[i]<=Q? -1: ((H[i]-Q-1)%(P+Q) + P-1)/P);
   }
   
   int ans = 0;
   memset(dp, -1, sizeof(dp));
   dp[0][0][0][0] = 0;
   for(int r=1;r<=1;r++, u=1-u) {
     memset(dp[1-u], -1, sizeof(dp[1-u]));
     for(int i=0;i<N;i++) {
       for(int t=0;t<=rlim;t++) {
         for(int z=0;z<=11;z++) {
           if(dp[u][i][t][z] == -1) continue;
           int rem = H[i] - z * Q;
           if(rem <= 0) {
             if(i==N-1) ans=max(ans, dp[u][i][t][z]);
             //if(i==N-1 && z-(H[i]+Q-1)/Q==0) ans=max(ans, dp[u][i][t][z]);
             update(dp[u][i+1][t][z-(H[i]+Q-1)/Q], dp[u][i][t][z]);
           }
           if((H[i]+P-1)/P <= t) {
             if(i==N-1) ans=max(ans, dp[u][i][t][z]+G[i]);
             //if(i==N-1 && z==0) ans=max(ans, dp[u][i][t][z]+G[i]);
             update(dp[u][i+1][t-(H[i]+P-1)/P][z], dp[u][i][t][z]+G[i]);
           }
           for(int w=0;w<=z;w++) {
             /*if(H[i]-w*Q>0 && H[i]-w*Q <= P*t+P) {
               if(i==N-1 && z==w) ans=max(ans, dp[u][i][t][z] + G[i]);
               update(dp[1-u][i+1][t+1-(H[i]-w*Q+P-1)/P][z-w +1 ], dp[u][i][t][z] + G[i]);
             }*/
             if(H[i]-w*Q>0 && H[i]-w*Q <= P*t) {
               if(i==N-1) ans=max(ans, dp[u][i][t][z] + G[i]);
               update(dp[u][i+1][t-(H[i]-w*Q+P-1)/P][z-w], dp[u][i][t][z] + G[i]);
             }
           }
           if(rem > 0) update(dp[u][i][t+1][z+1], dp[u][i][t][z]);
         }
       }
     }
   }
 
   printf("Case #%d: %d\n", cs, ans);
   fprintf(stderr, "Case #%d: %d\n", cs, ans);
 }
 
 int main(void) {
   int T;
   scanf("%d", &T);
   for(cs=1;cs<=T;cs++) solve();
   return 0;
 }
