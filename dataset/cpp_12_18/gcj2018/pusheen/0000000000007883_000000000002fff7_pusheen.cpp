#include<stdio.h>
#include<math.h>
#include<algorithm>
double dp[101][50001];
int w[101],h[101];
double d[101];
double solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	int ws=0;
	int pre=0;
	for(i=0;i<n;i++){
		int W,H;
		scanf("%d%d",&W,&H);
		w[i]=std::min(W,H)*2;
		//h[i]=std::max(W,H);
		d[i]=2*sqrt(W*W+H*H)-w[i];
		m-=W+W+H+H;
		pre+=W+W+H+H;
		ws+=w[i];
	}
	if(m==0) return pre;
	if(ws>m) ws=m;
	for(j=ws;j>=0;j--){
		dp[0][j]=-99999999999999.0;
	}
	dp[0][0]=0;
	dp[0][w[0]]=d[0];
	for(i=1;i<n;i++){
		for(j=ws;j>=0;j--){
			dp[i][j]=dp[i-1][j];
		}
		for(j=ws;j>=w[i];j--){
			dp[i][j]=std::max(dp[i-1][j],dp[i-1][j-w[i]]+d[i]);
		}
	}
	double ans=0;
	for(i=0;i<=ws;i++){
		if(dp[n-1][i]<=0) continue;
		if(i+dp[n-1][i]>=m) return m+pre;
		ans=std::max(ans,i+dp[n-1][i]);
	}
	return ans+pre;
}
int main(){
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		printf("%.9f\n",solve());
	}
}