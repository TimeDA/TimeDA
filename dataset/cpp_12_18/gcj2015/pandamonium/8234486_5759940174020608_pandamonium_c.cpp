#include <bits/stdc++.h>
 #define INF 1000000000
 using namespace std;
 int t,n,f;
 char str[15],ch;
 map <string,int> m;
 int color[4005],p[8005];
 int res[8005][8005];
 vector <int> v,dist,adj[8005];
 queue <int> q;
 void augment(int k, int minEdge){
 	if(k==0) f=minEdge;
 	else if(p[k]>=0){
 		augment(p[k],min(minEdge,res[p[k]][k]));
 		res[p[k]][k]-=f;
 		res[k][p[k]]+=f;
 	}
 }
 int main(){
 	scanf("%d\n",&t);
 	for(int a=1;a<=t;a++){
 		int cnt=2,ans=0;
 		m.clear();
 		for(int x=0;x<8000;x++) adj[x].clear();
 		memset(color,-1,sizeof(color));
 		memset(res,0,sizeof(res));
 		scanf("%d\n",&n);
 		n-=2;
 		while(1){
 			scanf("%s%c",str,&ch);
 			if(m.find(str)==m.end()){
 				m[str]=cnt;
 				color[cnt]=0;
 				cnt++;
 			}
 			if(ch=='\n') break;
 		}
 		while(1){
 			scanf("%s%c",str,&ch);
 			if(m.find(str)==m.end()){
 				m[str]=cnt;
 				color[cnt]=1;
 				cnt++;
 			}
 			else{
 				color[m[str]]=2;
 				ans++;
 			}
 			if(ch=='\n') break;
 		}
 		for(int x=2;x<cnt;x++){
 			if(color[x]==0){
 				adj[0].push_back(x);
 				res[0][x]=INF;
 			}
 			else if(color[x]==1){
 				adj[x].push_back(1);
 				res[x][1]=INF;
 			}
 		}
 		while(n--){
 			v.clear();
 			while(1){
 				scanf("%s%c",str,&ch);
 				if(m.find(str)==m.end()){
 					m[str]=cnt;
 					v.push_back(cnt);
 					cnt++;
 				}
 				else{
 					int c=m[str];
 					if(color[c]!=2) v.push_back(m[str]);
 				}
 				int s=v.size()-1;
 				for(int x=0;x<s;x++){
 					adj[v[x]].push_back(v[s]);
 					adj[v[s]].push_back(v[x]);
 				}
 				if(ch=='\n') break;
 			}
 		}
 		for(int x=2;x<cnt;x++){
 			for(int y=0;y<adj[x].size();y++){
 				adj[x+cnt].push_back(adj[x][y]);
 				res[x+cnt][adj[x][y]]=INF;
 			}
 			adj[x].clear();
 			adj[x].push_back(x+cnt);
 			res[x][x+cnt]=1;
 		}
 		while(1){
 			f=0;
 			dist.clear();
 			dist.resize(cnt*2,INF);
 			dist[0]=0;
 			while(!q.empty()) q.pop();
 			q.push(0);
 			memset(p,-1,sizeof(p));
 			while(!q.empty()){
 				int u=q.front();
 				q.pop();
 				if(u==1) break;
 				for(int x=0;x<adj[u].size();x++){
 					int n=adj[u][x];
 					if(res[u][n]>0&&dist[n]==INF){
 						dist[n]=dist[u]+1;
 						q.push(n);
 						p[n]=u;
 					}
 				}
 			}
 			augment(1,INF);
 			if(f==0) break;
 			ans+=f;
 		}
 		printf("Case #%d: %d\n",a,ans);
 	}
 	return 0;
 }
