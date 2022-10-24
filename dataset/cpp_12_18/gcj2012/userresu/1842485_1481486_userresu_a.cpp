#include <cstdio>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 typedef long long ll;
 
 int N,x[10001],l[10001],D;
 int dp[10001];
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     int T;
     scanf("%d",&T);
     for (int z=1;z<=T;++z){
     scanf("%d",&N);
     for (int i=1;i<=N;++i) scanf("%d %d",&x[i],&l[i]);
     scanf("%d",&D);
     printf("Case #%d: ",z);
     if (l[1]<x[1]) printf("NO\n");
     else {
          dp[1]=x[1];
          if (dp[1]>=D-x[1]) printf("YES\n");
          else {
               bool ok=0;
               for (int i=2;i<=N;++i) {
                   dp[i]=0;
                   for (int j=i-1;j>=1;--j) if (dp[j]>=x[i]-x[j]) {
                       dp[i]=max(dp[i],min(x[i]-x[j],l[i]));
                   }
                   if (dp[i]>=D-x[i]) {
                      printf("YES\n");
                      ok=1;
                      break;
                   }
               }
               if (!ok) printf("NO\n");
          }
     }}
     return 0;
 }
