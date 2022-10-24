#include<stdio.h>
 #include<algorithm>
 double p[10001], a[10001];
 double dp[201][201];
 int main(){
 	int i,j,k;
 	int t;
 	int T,TN;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		int N,M;
 		scanf("%d%d",&N,&M);
 		for(i=0;i<N;i++){
 			scanf("%lf",&p[i]);
 		}
 		std::sort(p,p+N);
 		double ans=0;
 		for(t=0;t<=M;t++){
 			for(i=j=0;i<t;i++){
 				a[j++]=p[i];
 			}
 			for(i=t+N-M;i<N;i++){
 				a[j++]=p[i];
 			}
 			//printf("%d\n",j);
 			int HM=M/2;
 			for(i=0;i<=M;i++){
 				for(j=0;j<=HM;j++){
 					dp[i][j]=0;
 				}
 			}
 			dp[0][0]=1;
 			
 			for(i=0;i<M;i++){
 				for(j=0;j<=HM&&j<=i+1;j++){
 					dp[i+1][j]=dp[i][j]*(1-a[i]);
 					if(j) dp[i+1][j]+=dp[i][j-1]*(a[i]);
 				}
 			}
 			for(i=0;i<=M;i++){
 				for(j=0;j<=HM;j++){
 					//printf("%d %d: %f\n",i,j,dp[i][j]);
 				}
 			}
 			if(ans<dp[M][HM]) ans=dp[M][HM];
 			
 		}
 		printf("Case #%d: %f\n",T,ans);
 		//fprintf(stderr,"select %d\n",sel);
 	}
 
 }
