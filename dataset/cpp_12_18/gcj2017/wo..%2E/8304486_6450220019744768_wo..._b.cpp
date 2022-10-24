#include<cstdio>
 #include<vector>
 #include<utility>
 #include<cstdlib>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int, int> P;
 
 vector<int> G[1010];
 bool used[1010];
 int N;
 int par[1010];
 int ord[1010];
 
 bool es[1010][1010];
 P ps[1010];
 int M;
 int vals[1010][1010];
 
 int num;
 
 void input(){
 	scanf("%d%d", &N, &M);
 	for(int i = 0; i < M; ++i){
 		int u, v;
 		scanf("%d%d", &u, &v);
 		u--;
 		v--;
 		es[u][v] = true;
 		ps[i] = P(u, v);
 		if(!es[v][u]){
 			G[u].push_back(v);
 			G[v].push_back(u);
 		}
 	}
 }
 
 void init(){
 	num = 0;
 	for(int i = 0; i < 1010; ++i){
 		G[i].clear();
 		used[i] = false;
 		ord[i] = 0;
 		for(int j = 0; j < 1010; ++j){
 			es[i][j] = false;
 			vals[i][j] = 0;
 		}
 	}
 }
 
 void dfs(int v, int p){
 	par[v] = p;
 	used[v] = true;
 	ord[v] = num++;
 	for(int i = 0; i < G[v].size(); ++i){
 		int u = G[v][i];
 		if(u == p) continue;
 		if(used[u]){
 			if(ord[u] > ord[v]) continue;
 			// back edge
 			vals[v][u]++;
 			int w = v;
 			while(w != u){
 				vals[par[w]][w]++;
 				w = par[w];
 			}
 		}else{
 			dfs(u, v);
 		}
 	}
 }
 
 void solve(){
 	for(int i = 0; i < N; ++i){
 		if(!used[i]){
 			dfs(i, -1);
 		}
 	}
 }
 
 void output(int t){
 	bool ok = true;
 	for(int u = 0; u < N; ++u){
 		for(int v = 0; v < N; ++v){
 			if(es[u][v] && es[v][u]){
 				if(vals[u][v] == 0 && vals[v][u] == 0){
 					vals[u][v]++;
 					vals[v][u]++;
 				}else{
 					int x = vals[u][v] + vals[v][u];
 					int c = x > 0 ? 1 : 0;
 					vals[u][v] += c;
 					vals[v][u] += c;
 				}
 			}
 		}
 	}
 	for(int i = 0; i < M; ++i){
 		int u = ps[i].first, v = ps[i].second;
 		if(vals[u][v] == 0 && vals[v][u] == 0) ok = false;
 	}
 	if(!ok){
 		printf("Case #%d: IMPOSSIBLE\n", t);
 		return;
 	}
 	printf("Case #%d: ", t);
 	for(int i = 0; i < M; ++i){
 		int u = ps[i].first, v = ps[i].second;
 		int val = vals[u][v];
 		if(val == 0){
 			val = -vals[v][u];
 		}
 		printf("%d%c", val, i == M - 1 ? '\n' : ' ');
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		init();
 		input();
 		solve();
 		output(datano + 1);
 	}
 	return 0;
 }
