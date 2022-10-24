#include<cstdio>
 #include<algorithm>
 
 using namespace std;
 
 const int inf=1<<29;
 
 int dp[100][100];
 
 int v[100];
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		int E,R,N;
 		scanf("%d%d%d",&E,&R,&N);
 		for(int i=0;i<N;i++) scanf("%d",v+i);
 		for(int i=0;i<100;i++) for(int j=0;j<100;j++) dp[i][j]=-inf;
 		dp[0][E]=0;
 		for(int i=0;i<N;i++)
 		{
 			for(int j=0;j<=E;j++)
 			{
 				for(int s=0;s<=j;s++)
 				{
 					int tmp=dp[i][j]+s*v[i];
 					int nenergy=j-s+R;
 					nenergy=min(nenergy,E);
 					dp[i+1][nenergy]=max(dp[i+1][nenergy],tmp);
 				}
 			}
 		}
 		int ans=-inf;
 		for(int i=0;i<=E;i++) ans=max(ans,dp[N][i]);
 		printf("Case #%d: %d\n",datano+1,ans);
 	}
 	return 0;
 }
