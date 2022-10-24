#include<stdio.h>
#include<vector>
using namespace std;
int G[101][101];
int cnt[201][201];
bool used[201][201];
int vis[202],rem[201];
vector<int> E[201];
int T,N;
int last;
bool Aug(int x){
	vis[x]=last;
	if(x>N){
		if(rem[x]){
			--rem[x];
			return true;
		}
		for(auto &&y:E[x]) if(vis[y]!=last&&used[y][x]){
			if(Aug(y)){
				used[y][x]=false;
				return true;
			}
		}
	}
	else{
		for(auto &&y:E[x]) if(vis[y]!=last&&!used[x][y]){
			if(Aug(y)){
				used[x][y]=true;
				return true;
			}
		}
	}
	return false;
}
int solve(int id){
	for(int i=1;i<=2*N;++i) E[i].clear();
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) if(G[i][j]==id){
		if(cnt[i][id]>1&&cnt[j+N][id]>1) E[i].push_back(j+N),E[j+N].push_back(i);
	}
	int ret=0;
	for(int i=1;i<=2*N;++i) rem[i]=max(0,cnt[i][id]-1),ret+=rem[i];
	for(int i=1;i<=N;++i){
		while(++last,rem[i]&&Aug(i)) --ret,--rem[i];
	}
	return ret;
}
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d",&N);
		for(int i=1;i<=2*N;++i) for(int j=0;j<=2*N;++j){
			cnt[i][j]=0;
			used[i][j]=false;
		}
		for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){
			scanf("%d",G[i]+j);
			G[i][j]+=N;
			cnt[i][G[i][j]]++;
			cnt[j+N][G[i][j]]++;
		}
		int ans=0;
		for(int nn=0;nn<=2*N;++nn){
			ans+=solve(nn);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
