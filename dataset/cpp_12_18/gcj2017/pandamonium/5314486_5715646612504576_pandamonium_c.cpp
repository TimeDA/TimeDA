#include <bits/stdc++.h>
 using namespace std;
 int dfscnt=1,dfs_num[10005],dfs_low[10005],dfs_parent[10005];
 int visited[10005],scccnt,scc[10005],ass[10005],num[55][55],must[10005];
 stack<int>s;
 vector <int> adj[10005],hit[10005];
 int n,t,r,c;
 char grid[55][55];
 void dfs(int v){
 	dfs_low[v]=dfs_num[v]=dfscnt++;
 	visited[v]=1;
 	s.push(v);
 	for(int i=0;i<int(adj[v].size());i++){
 		if(!dfs_num[adj[v][i]]){
 			dfs_parent[adj[v][i]]=v;
 			dfs(adj[v][i]);
 			dfs_low[v]=min(dfs_low[v],dfs_low[adj[v][i]]);
 		}
 		if(visited[adj[v][i]]) dfs_low[v]=min(dfs_low[v],dfs_low[adj[v][i]]);
 	}
 	if(dfs_low[v]==dfs_num[v]){
 		while(1){
 			int u=s.top();
 			s.pop();
 			visited[u]=0;
 			scc[u]=scccnt;
 			if(u==v) break;
 		}
 		ass[scccnt]=-1;
 		scccnt++;
 	}
 }
 int dx[]={0,1,0,-1};
 int dy[]={1,0,-1,0};
 int main(){
 	scanf("%d\n",&t);
 	for(int tc=1;tc<=t;tc++){
 		scanf("%d %d\n",&r,&c);
 		int holecnt=0,tcnt=0;
 		for(int x=0;x<r;x++){
 			scanf("%s",grid[x]);
 			for(int y=0;y<c;y++){
 				if(grid[x][y]=='.'){
 					num[x][y]=holecnt;
 					hit[holecnt].clear();
 					adj[2*holecnt].clear();
 					adj[2*holecnt+1].clear();
 					holecnt++;
 				}
 				else if(grid[x][y]=='-'||grid[x][y]=='|'){
 					num[x][y]=tcnt;
 					must[tcnt]=-1;
 					tcnt++;
 				}
 			}
 		}
 		bool epicfail=0;
 		for(int x=0;x<r;x++){
 			for(int y=0;y<c;y++){
 				if(grid[x][y]=='-'||grid[x][y]=='|'){
 					int curx=x,cury=y,dir=0;
 					bool fail=0,failcnt=0;
 					vector <int> v;
 					v.clear();
 					while(!fail){
 						curx+=dx[dir];
 						cury+=dy[dir];
 						//printf("%d %d %d %d\n",x,y,curx,cury);
 						if(curx<0||curx>=r||cury<0||cury>=c||grid[curx][cury]=='#') break;
 						else if(grid[curx][cury]=='.') v.push_back(num[curx][cury]);
 						else if(grid[curx][cury]=='/') dir=3-dir;
 						else if(grid[curx][cury]=='\\') dir^=1;
 						else fail=1;
 					}
 					curx=x,cury=y,dir=2;
 					while(!fail){
 						curx+=dx[dir];
 						cury+=dy[dir];
 						//printf("%d %d %d %d\n",x,y,curx,cury);
 						if(curx<0||curx>=r||cury<0||cury>=c||grid[curx][cury]=='#') break;
 						else if(grid[curx][cury]=='.') v.push_back(num[curx][cury]);
 						else if(grid[curx][cury]=='/') dir=3-dir;
 						else if(grid[curx][cury]=='\\') dir^=1;
 						else fail=1;
 					}
 					if(!fail){
 						for(int i:v){
 							hit[i].push_back(2*num[x][y]);
 						}
 					}
 					else{
 						must[num[x][y]]=1;
 						failcnt=1;
 					}
 					curx=x,cury=y,dir=1;
 					fail=0;
 					v.clear();
 					while(!fail){
 						curx+=dx[dir];
 						cury+=dy[dir];
 						//printf("%d %d %d %d\n",x,y,curx,cury);
 						if(curx<0||curx>=r||cury<0||cury>=c||grid[curx][cury]=='#') break;
 						else if(grid[curx][cury]=='.') v.push_back(num[curx][cury]);
 						else if(grid[curx][cury]=='/') dir=3-dir;
 						else if(grid[curx][cury]=='\\') dir^=1;
 						else fail=1;
 					}
 					curx=x,cury=y,dir=3;
 					while(!fail){
 						curx+=dx[dir];
 						cury+=dy[dir];
 						//printf("%d %d %d %d\n",x,y,curx,cury);
 						if(curx<0||curx>=r||cury<0||cury>=c||grid[curx][cury]=='#') break;
 						else if(grid[curx][cury]=='.') v.push_back(num[curx][cury]);
 						else if(grid[curx][cury]=='/') dir=3-dir;
 						else if(grid[curx][cury]=='\\') dir^=1;
 						else fail=1;
 					}
 					if(!fail){
 						for(int i:v){
 							hit[i].push_back(2*num[x][y]+1);
 						}
 					}
 					else if(failcnt==1){
 						epicfail=1;
 						break;
 					}
 					else{
 						must[num[x][y]]=0;
 					}
 				}
 			}
 		}
 		bool fail=0;
 		for(int x=0;x<holecnt;x++){
 			if(hit[x].size()==0){
 				fail=1;
 				break;
 			}
 			else if(hit[x].size()==1){
 				if(must[hit[x][0]/2]==-1){
 					must[hit[x][0]/2]=hit[x][0]%2;
 				}
 				else if(must[hit[x][0]/2]!=hit[x][0]%2){
 					fail=1;
 					break;
 				}
 			}
 			else if(hit[x][0]/2!=hit[x][1]/2){
 				adj[hit[x][0]^1].push_back(hit[x][1]);
 				adj[hit[x][1]^1].push_back(hit[x][0]);
 			}	
 		}
 		if(fail||epicfail){
 			printf("Case #%d: IMPOSSIBLE\n",tc);
 			continue;
 		}
 		for(int x=0;x<tcnt;x++){
 			if(must[x]==0) adj[2*x+1].push_back(2*x);
 			else if(must[x]==1) adj[2*x].push_back(2*x+1);
 		}
 		memset(dfs_low,0,sizeof(dfs_low));
 		memset(dfs_num,0,sizeof(dfs_num));
 		memset(dfs_parent,0,sizeof(dfs_parent));
 		memset(visited,0,sizeof(visited));
 		for(int x=0;x<2*tcnt;x++){
 			if(!dfs_num[x]){
 				dfs(x);
 			}
 		}
 		for(int x=0;x<tcnt;x++){
 			if(scc[2*x]==scc[2*x+1]){
 				fail=1;
 				break;
 			}
 			if(must[x]==0){
 				if(ass[scc[2*x]]==0||ass[scc[2*x+1]]==1){
 					fail=1;
 					break;
 				}
 				else if(ass[scc[2*x]]==-1||ass[scc[2*x+1]]==-1){
 					ass[scc[2*x]]=1;
 					ass[scc[2*x+1]]=0;
 				}
 			}
 			else if(must[x]==1){
 				if(ass[scc[2*x]]==1||ass[scc[2*x+1]]==0){
 					fail=1;
 					break;
 				}
 				else if(ass[scc[2*x]]==-1||ass[scc[2*x+1]]==-1){
 					ass[scc[2*x]]=0;
 					ass[scc[2*x+1]]=1;
 				}
 			}
 		}
 		if(fail){
 			printf("Case #%d: IMPOSSIBLE\n",tc);
 			continue;
 		}
 		for(int x=0;x<tcnt;x++){
 			if(must[x]==-1){
 				if(ass[scc[2*x]]==1) must[x]=0;
 				else if(ass[scc[2*x+1]]==1) must[x]=1;
 				else{
 					must[x]=0;
 					ass[scc[2*x]]=1;
 					ass[scc[2*x+1]]=0;
 				}
 			}
 		}
 		printf("Case #%d: POSSIBLE\n",tc);
 		for(int x=0;x<r;x++){
 			for(int y=0;y<c;y++){
 				if(grid[x][y]!='-'&&grid[x][y]!='|') printf("%c",grid[x][y]);
 				else if(must[num[x][y]]==0) printf("-");
 				else printf("|");
 			}
 			printf("\n");
 		}
 	}
 	return 0;
 }	
