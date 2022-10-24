#include <cstdio>
 #include <cstring>
 int i,t,p,q,n,h[105],g[105],dp[105][1005];
 inline int max(int a, int b){return a>b?a:b;}
 int f(int i, int free){
 	if(i==n) return 0;
 	if(dp[i][free]>=0) return dp[i][free];
 	int tower=(h[i]-1)/q,mary=(h[i]-tower*q-1)/p+1;
 	dp[i][free]=f(i+1,tower+1+free);
 	if(g[i]==0||mary>tower+free) return dp[i][free];
 	return dp[i][free]=max(dp[i][free],f(i+1,tower+free-mary)+g[i]);
 }
 int main(){
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d %d %d",&p,&q,&n);
 		for(int x=0;x<n;x++) scanf("%d %d",&h[x],&g[x]);
 		memset(dp,-1,sizeof(dp));
 		printf("Case #%d: %d\n",++i,f(0,1));
 	}
 	return 0;
 }
 	
