#include<stdio.h>
#include<algorithm>
using std::max;
int dp[501][501];
int T,A,B;
int main(){
	for(int i=0;i<=500;++i){
		for(int j=0;j<=500;++j) if(i||j){
			int I=(j+1)*(i*(i+1)/2);
			int J=(i+1)*(j*(j+1)/2);
			if(I>=500||J>=500) break;
			for(int k=500;k>=I;--k) for(int l=500;l>=J;--l){
				dp[k][l]=max(dp[k][l],dp[k-i][l-j]+1);
			}
		}
	}
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d",&A,&B);
		printf("Case #%d: %d\n",tt,dp[A][B]);
	}
	return 0;
}
