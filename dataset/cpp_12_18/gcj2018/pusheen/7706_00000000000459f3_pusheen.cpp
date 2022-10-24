#include<stdio.h>
#include<math.h>
#include<algorithm>

int dp[501][501];
int main(){
	int i,j,k;
	int n=500, m=500;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			dp[i][j]=0;
		}
	}
	int p=1,q=0;
	while(q+p<=m){
		dp[0][q+p]=p;
		q+=p++;
	}
	//int ans=p;
	
	for(k=1;k<=n;k++){
		for(i=n;i>=0;i--){
			for(j=m;j>=0;j--){
				p=0,q=0;
				int x=0;
				while(q+p<=j&&k*(p+1)<=i){
					dp[i][j]=std::max(dp[i][j],dp[i-k*(p+1)][j-(p+q)] + p + 1);
					q+=p++;
				}
			}
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i) dp[i][j]=std::max(dp[i][j],dp[i-1][j]);
			if(j) dp[i][j]=std::max(dp[i][j],dp[i][j-1]);
			//ans=std::max(ans,dp[i][j]);
		}
	}
	
	int T,TN;
	scanf("%d",&TN);
	for(T=1;T<=TN;T++){
		printf("Case #%d: ", T);
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b){
			int k=a;
			a=b;
			b=k;
		}
		printf("%d\n",dp[a][b]);
	}
}