#include <iostream>
 #include <sstream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <bitset>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 typedef int F;
 #define F_INF (1<<29)
 #define MAXV 410
 #define MAXE 30000 // E*2!
 
 F cap[MAXE],flow[MAXE];
 int to[MAXE],prev[MAXE],last[MAXV],used[MAXV],level[MAXV];
 
 struct MaxFlow{
 	int V,E;
 
 	MaxFlow(int n){
 		int i;
 		V = n; E = 0;
 		REP(i,V) last[i] = -1;
 	}
 
 	void add_edge(int x, int y, F f){
 		cap[E] = f; flow[E] = 0; to[E] = y; prev[E] = last[x]; last[x] = E; E++;
 		cap[E] = 0; flow[E] = 0; to[E] = x; prev[E] = last[y]; last[y] = E; E++;
 	}
 
 	bool bfs(int s, int t){
 		int i;
 		REP(i,V) level[i] = -1;
 		queue <int> q;
 		q.push(s); level[s] = 0;
 		while(!q.empty()){
 			int x = q.front(); q.pop();
 			for(i=last[x];i>=0;i=prev[i]) if(level[to[i]] == -1 && cap[i] > flow[i]) {q.push(to[i]); level[to[i]] = level[x] + 1;}
 		}
 		return (level[t] != -1);
 	}
 
 	F dfs(int v, int t, F f){
 		int i;
 		if(v == t) return f;
 		for(i=used[v];i>=0;used[v]=i=prev[i]) if(level[to[i]] > level[v] && cap[i] > flow[i]){
 			F tmp = dfs(to[i],t,min(f,cap[i]-flow[i]));
 			if(tmp > 0) {flow[i] += tmp; flow[i^1] -= tmp; return tmp;}
 		}
 		return 0;
 	}
 	
 	vector <pair <int, int> > positive_edges(void){
 		int i,j;
 		vector <pair <int, int> > ans;
 		REP(i,V) for(j=last[i];j>=0;j=prev[j]) if(flow[j] > 0) ans.push_back(make_pair(i, to[j]));
 		return ans;
 	}
 
 	F maxflow(int s, int t){
 		int i;
 		while(bfs(s,t)){
 			REP(i,V) used[i] = last[i];
 			while(dfs(s,t,F_INF) != 0);
 		}
 		F ans = 0;
 		for(i=last[s];i>=0;i=prev[i]) ans += flow[i];
 		return ans;
 	}
 
 };
 
 // 1: vertical, 2: diagonal
 int N;
 int a[110][110],b[110][110];
 bool usedl[210],usedr[210];
 
 void get_vert(void){
 	int i,j;
 	
 	REP(i,N) usedl[i] = usedr[i] = false;
 	REP(i,N) REP(j,N) if(a[i][j] & 1){
 		usedl[i] = true;
 		usedr[j] = true;
 	}
 	
 	MaxFlow mf(2*N+2);
 	REP(i,N) mf.add_edge(2*N, i, 1);
 	REP(i,N) mf.add_edge(N+i, 2*N+1, 1);
 	REP(i,N) REP(j,N) if(!(a[i][j] & 1)) if(!usedl[i] && !usedr[j]) mf.add_edge(i, N+j, 1);
 	
 	mf.maxflow(2*N, 2*N+1);
 	vector <pair <int, int> > v = mf.positive_edges();
 	REP(i,v.size()){
 		int s = v[i].first;
 		int t = v[i].second - N;
 		if(s >= 0 && s < N && t >= 0 && t < N) b[s][t] |= 1;
 	}
 }
 
 void get_diag(void){
 	int i,j;
 	
 	REP(i,2*N) usedl[i] = usedr[i] = false;
 	REP(i,N) REP(j,N) if(a[i][j] & 2){
 		usedl[i+j] = true;
 		usedr[i-j+N] = true;
 	}
 	
 	MaxFlow mf(4*N+2);
 	REP(i,2*N) mf.add_edge(4*N, i, 1);
 	REP(i,2*N) mf.add_edge(2*N+i, 4*N+1, 1);
 	REP(i,N) REP(j,N) if(!(a[i][j] & 2)) if(!usedl[i+j] && !usedr[i-j+N]) mf.add_edge(i+j, i-j+N+2*N, 1);
 	
 	mf.maxflow(4*N, 4*N+1);
 	vector <pair <int, int> > v = mf.positive_edges();
 	REP(i,v.size()){
 		int s = v[i].first;
 		int t = v[i].second - 2 * N;
 		if(s >= 0 && s < 2*N && t >= 0 && t < 2*N) b[(s+t-N)/2][(s-t+N)/2] |= 2;
 	}
 }
 
 void main2(void){
 	int i,j;
 	
 	cin >> N;
 	REP(i,N) REP(j,N) a[i][j] = b[i][j] = 0;
 	
 	int M;
 	cin >> M;
 	REP(i,M){
 		char type;
 		int x,y;
 		cin >> type >> x >> y;
 		if(type == 'o' || type == 'x') a[x-1][y-1] |= 1;
 		if(type == 'o' || type == '+') a[x-1][y-1] |= 2;
 	}
 	
 	REP(i,N) REP(j,N) b[i][j] = a[i][j];
 	get_vert();
 	get_diag();
 	
 	int ans = 0;
 	REP(i,N) REP(j,N) ans += __builtin_popcount(b[i][j]);
 	int cnt = 0;
 	REP(i,N) REP(j,N) if(a[i][j] != b[i][j]) cnt++;
 	cout << ans << ' ' << cnt << endl;
 	
 	REP(i,N) REP(j,N) if(a[i][j] != b[i][j]) printf("%c %d %d\n", ".x+o"[b[i][j]], i+1, j+1);
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc + 1);
 		main2();
 	}
 	return 0;
 }
