#include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <cmath>
 #include <memory.h>
 using namespace std;
 typedef long long ll;
 
 
 const int V = 1e6+6;
 const int E = V*3;
 int eb[V], peb[V], e[E*2], es[E*2], ed=1;
 int ef[E*2], ec[E*2];
 int S, T, nv;
 int d[V], o[V], r[V];
 
 void init(){
     memset(eb, 0, sizeof eb);
     ed=1;
 }
 
 void add_e(int v, int u, int maxflow){
 	++ed;
 	e[ed] = u;
 	ef[ed] = 0;
 	ec[ed] = maxflow;
 	es[ed] = eb[v];
 	eb[v] = ed;
 	++ed;
 	e[ed] = v;
 	ef[ed] = 0;
 	ec[ed] = maxflow;
 	es[ed] = eb[u];
 	eb[u] = ed;
 }
 
 int dfs(int v, int flow){
 	if(!flow || v==T) return flow;
 	for(int&k = peb[v]; k; k=es[k]){
 		int u = e[k];
 		if(d[v] != d[u]-1) continue;
 		int push = dfs(u, min(flow, ec[k]-ef[k]));
 		if(push){
 			ef[k] += push;
 			ef[k^1] -= push;
 			return push;
 		}
 	}
 	return 0;
 }
 
 bool bfs(){
 	memset(d,0,nv*sizeof(d[0]));
 	int h=0, l=0;
 	o[h++] = S;
 	d[S] = 1;
 	while(l<h){
 		int v = o[l++];
 		for(int u,k=eb[v]; k; k=es[k]){
 			u = e[k];
 			if(!d[u] && ec[k]>ef[k]){
 				d[u] = d[v]+1;
 				o[h++] = u;
 			}
 		}
 	}
 	return d[T];
 }
 
 int dinic(){
 	int flow = 0, inf = 1e9, pushed;
 	while(bfs()){
 		memcpy(peb, eb, nv*sizeof(eb[0]));
 		do{
 			pushed = dfs(S, inf);
 			flow+=pushed;
 		}while(pushed);
 	}
 	return flow;
 }
 
 bool u[555][555];
 bool fl[555][555];
 int id[555][555];
 int fr[555][555][2];
 int q[555*555][2];
 int dx[4] = {-1,0,1,0};
 int dy[4] = {0,-1,0,1};
 int w[555][555];
 int wf[555][555][2];
 
 bool push(int n, int m, int sx, int sy){
     
     
     
     int inf = 1e9;
     for(int i=0;i<n;++i)
     for(int j=0;j<m;++j) w[i][j] = inf, wf[i][j][0]=wf[i][j][1]=-1;
     
     int qn = 0;
     
     q[qn][0] = sx;
     q[qn++][1] = sy;
     w[sx][sy] = 0;
     
     for(int k=0;k<qn;++k){
         int i = q[k][0];
         int j = q[k][1];
         
         for(int l=0;l<4;++l){
             int x = i+dx[l];
             int y = j+dy[l];
             if(y<0 || x<0 || x>=n || y>=m || u[x][y]) continue;
             if(fl[i][j] && !(x==fr[i][j][0] && y==fr[i][j][1])) continue;
             if(w[x][y]>w[i][j]+1){
                 w[x][y] = w[i][j]+1;
                 wf[x][y][0] = i;
                 wf[x][y][1] = j;
                 q[qn][0]=x;
                 q[qn++][1]=y;
             }
         }
     }
     
     
     
     
     for(int j=0;j<m;++j) if(w[n-1][j]<inf){
        // cout<<"!"<<j<<endl;
         int i=n-1;
         
         while(w[i][j]!=0){
             int x = wf[i][j][0];
             int y = wf[i][j][1];
             
             if(!fl[i][j]){
                 fl[i][j] = true;
                 fr[i][j][0] = x;
                 fr[i][j][1] = y;
             }else{
                 int fx = fr[i][j][0];
                 int fy = fr[i][j][1];
                 if(fx!=-1 && fy!=-1 && wf[fx][fy][0]==i && wf[fx][fy][1]==j){
                     fl[i][j] = 0;
                     fr[i][j][0] = -1;
                     fr[i][j][1] = -1;
                 }
                 if(x!=-1 && y!=-1 && !fl[x][y]){
                     fl[i][j] = 1;
                     fr[i][j][0] = x;
                     fr[i][j][1] = y;
                 }
             }
             
             
             
             i = x; j = y;
         }
         
         
         return true;
     }
     return false;
 }
 
 void solve(int test){
     int n,m,q;
     cin>>m>>n>>q;
     
     
     memset(u, 0, sizeof u);
     memset(fl, 0, sizeof fl);
     memset(id, -1, sizeof id);
     memset(fr, -1, sizeof fr);
     for(int k=0;k<q;++k){
         int ax,ay,bx,by;
         cin>>ay>>ax>>by>>bx;
         for(int x=ax;x<=bx;++x)
         for(int y=ay;y<=by;++y) u[x][y]=1;
     }
     /*
     init();
     
     nv = 0;
     S = nv++;
     
     for(int i=0;i<n;++i)
     for(int j=0;j<m;++j) if(!u[i][j]){
         id[i][j] = nv++;
     }
     T = nv++;
     
     for(int j=0;j<m;++j){
         if(!u[0][j])add_e(S, id[0][j], 1);
         if(!u[n-1][j])add_e(id[n-1][j], T, 1);
     }
     
     
     
     for(int i=0;i<n;++i)
     for(int j=0;j<m;++j) if(!u[i][j]){
         int x = id[i][j], y;
         if(i+1<n){
             y = id[i+1][j];
             if(y!=-1) add_e(x, y, 1);
         }
         if(j>0){
             y = id[i][j-1];
             if(y!=-1) add_e(x, y, 1);
         }
         if(j+1<m){
             y = id[i][j+1];
             if(y!=-1) add_e(x, y, 1);
         }
         if(i>0){
             y = id[i-1][j];
             if(y!=-1) add_e(x, y, 1);
         }
     }
     
     int ans = dinic();*/
     
     
     int ans = 0;
     for(;;){
         bool ok=0;
         for(int j=0;j<m;++j) if(!u[0][j] && push(n,m,0,j)) ++ans, ok=1;
         if(!ok) break;
     }
     
     cout<<"Case #"<<test<<": ";
     
     cout<<ans;
     
     cout<<endl;
 }
 
 int main(){
     freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
     
     int tn;
     cin>>tn;
     for(int ti=1;ti<=tn;++ti){
         cerr<<"\t\t"<<ti<<"..."<<endl;
         solve(ti);
         cerr<<"\t\t"<<ti<<" ok."<<endl;
     }
     
     
     return 0;
 }
 
