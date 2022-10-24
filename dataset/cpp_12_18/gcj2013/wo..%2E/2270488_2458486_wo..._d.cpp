#include<cstdio>
 #include<vector>
 #include<cstring>
 
 using namespace std;
 
 int toopen[22];
 int in[22][220];
 
 int st[220];
 
 vector<int> G[1<<20];
 
 int nxt[1<<20];
 
 bool used[1<<20];
 bool memo[1<<20];
 
 bool dfs(int N,int stat)
 {
 //	printf("%d %d\n",N,stat);
 	if(stat==(1<<N)-1) return true;
 	if(used[stat]) return memo[stat];
 	used[stat]=true;
 	for(int i=0;i<G[stat].size();i++)
 	{
 		if(dfs(N,G[stat][i])==true)
 		{
 			nxt[stat]=G[stat][i];
 			memo[stat]=true;
 			return true;
 		}
 	}
 	memo[stat]=false;
 	return false;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 //		printf("case%d\n",datano+1);
 		int K,N;
 		scanf("%d%d",&K,&N);
 		memset(st,0,sizeof(st));
 		for(int i=0;i<K;i++)
 		{
 			int in;
 			scanf("%d",&in);
 			st[in-1]++;
 		}
 		memset(in,0,sizeof(in));
 		for(int i=0;i<(1<<20);i++) G[i].clear();
 		for(int i=0;i<N;i++)
 		{
 			scanf("%d",toopen+i);
 			toopen[i]--;
 			int tmp;
 			scanf("%d",&tmp);
 			for(int j=0;j<tmp;j++)
 			{
 				int a;
 				scanf("%d",&a);
 				a--;
 				in[i][a]++;
 			}
 		}
 		for(int i=0;i<(1<<N);i++)
 		{
 			int remain[220];
 			memset(remain,0,sizeof(remain));
 			for(int j=0;j<220;j++) remain[j]+=st[j];
 			for(int j=0;j<N;j++)
 			{
 				if(((i>>j)&1)==1)
 				{
 					remain[toopen[j]]--;
 					for(int k=0;k<220;k++)
 					{
 						remain[k]+=in[j][k];
 					}
 				}
 			}
 			for(int j=0;j<N;j++)
 			{
 				if(((i>>j)&1)==0)
 				{
 					if(remain[toopen[j]]<=0) continue;
 					G[i].push_back(i|(1<<j));
 					//printf("%d %d\n",i,(i|(1<<j)));
 				}
 			}
 		}
 		memset(used,false,sizeof(used));
 		if(dfs(N,0)==false)
 		{
 			printf("Case #%d: IMPOSSIBLE\n",datano+1);
 		}
 		else
 		{
 			printf("Case #%d:",datano+1);
 			int stat=0;
 			while(stat!=(1<<N)-1)
 			{
 				int n=nxt[stat];
 				int a=n-stat;
 				for(int i=0;i<N;i++) if(a==(1<<i))
 				{
 					printf(" %d",i+1);
 					stat|=(1<<i);
 				}
 			}
 			printf("\n");
 		}
 	}
 	return 0;
 }
