#include<cstdio>
 #include<vector>
 #include<utility>
 #include<queue>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int,int> P;
 
 long long S[1100100],M[1100100];
 
 int par[1100100];
 int sal[1100100];
 int N;
 int D;
 
 vector<int> ch[1100100];
 
 vector<P> vec;
 
 long long S0,AS,CS,RS;
 long long M0,AM,CM,RM;
 
 void gen(){
 	S[0]=S0;
 	M[0]=M0;
 	for(int i=1;i<N;i++){
 		S[i]=S[i-1]*AS+CS;
 		S[i]%=RS;
 		M[i]=M[i-1]*AM+CM;
 		M[i]%=RM;
 	}
 	for(int i=0;i<N;i++){
 		ch[i].clear();
 	}
 	for(int i=0;i<N;i++){
 		sal[i]=S[i];
 		if(i!=0){
 			par[i]=M[i]%i;
 			ch[par[i]].push_back(i);
 		}
 	}
 /*	for(int i=0;i<N;i++) printf("%d ",sal[i]);
 	printf("\n");
 	for(int i=0;i<N;i++) printf("%d ",par[i]);
 	printf("\n");*/
 }
 
 int mi[1100100],Ma[1100100];
 
 queue<int> que;
 int solve(){
 	vec.clear();
 	while(!que.empty()) que.pop();
 	mi[0]=sal[0],Ma[0]=sal[0];
 	que.push(0);
 	while(!que.empty()){
 		int v=que.front();
 		que.pop();
 		for(int i=0;i<ch[v].size();i++){
 			int u=ch[v][i];
 			mi[u]=min(sal[u],mi[v]);
 			Ma[u]=max(sal[u],Ma[v]);
 			que.push(u);
 		}
 	}
 	for(int i=0;i<N;i++){
 		int l=Ma[i]-D,r=mi[i];
 		if(r<l) continue;
 		vec.push_back(P(l,1));
 		vec.push_back(P(r+1,-1));
 	}
 	sort(vec.begin(),vec.end());
 	int res=0;
 	int cur=0;
 	for(int i=0;i<vec.size();i++){
 		cur+=vec[i].second;
 		res=max(res,cur);
 	}
 	return res;
 }
 
 int main(){
 	int T;
 	scanf("%d",&T);
 	for(int datano=1;datano<=T;datano++){
 		scanf("%d%d",&N,&D);
 		scanf("%lld%lld%lld%lld",&S0,&AS,&CS,&RS);
 		scanf("%lld%lld%lld%lld",&M0,&AM,&CM,&RM);
 		gen();
 		int ans=solve();
 		printf("Case #%d: %d\n",datano,ans);
 	}
 	return 0;
 }
