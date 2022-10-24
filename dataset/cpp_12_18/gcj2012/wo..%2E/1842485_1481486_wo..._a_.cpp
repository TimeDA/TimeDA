#include<cstdio>
 #include<vector>
 #include<cstring>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++)
 	{
 		int dp[10010];
 		int dis[10010];
 		int len[10010];
 		memset(dp,-1,sizeof(dp));
 		int N;
 		scanf("%d",&N);
 		for(int i=0;i<N;i++)
 		{
 			scanf("%d%d",dis+i,len+i);
 		}
 		for(int i=0;i<N;i++)
 		{
 		//	if(dis[i]<=len[i]) dp[i]=dis[i];
 		}
 		dp[0]=dis[0];
 		for(int i=0;i<N;i++)
 		{
 			long long canreach=dp[i]+dis[i];
 			for(int j=i+1;j<N;j++)
 			{
 				if(canreach<dis[j]) break;
 				int res=min(dis[j]-dis[i],len[j]);
 				dp[j]=max(res,dp[j]);
 			}
 		}
 		int D;
 		scanf("%d",&D);
 		bool flg=false;
 		for(int i=0;i<N;i++)
 		{
 			//printf("%d\n",dp[i]);
 			if(dp[i]+dis[i]>=D) flg=true;
 		}
 		if(flg)
 		{
 			printf("Case #%d: YES\n",datano);
 		}
 		else
 		{
 			printf("Case #%d: NO\n",datano);
 		}
 	}
 	return 0;
 }
