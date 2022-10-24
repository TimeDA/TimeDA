#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 int N;
 vector<int> G[1010];
 vector<int> rG[1010];
 
 vector<int> vs;
 bool used[1010];
 int cmp[1010];
 
 vector<int> cc_vs[1010];
 
 void init(){
 	for(int i = 0; i < 1010; ++i){
 		G[i].clear();
 		rG[i].clear();
 		used[i] = false;
 		cmp[i] = 0;
 		cc_vs[i].clear();
 	}
 	vs.clear();
 }
 
 void dfs(int v){
 	used[v] = true;
 	for(int i = 0; i < G[v].size(); ++i){
 		if(!used[G[v][i]]) dfs(G[v][i]);
 	}
 	vs.push_back(v);
 }
 
 void rdfs(int v, int k){
 	used[v] = true;
 	cmp[v] = k;
 	cc_vs[k].push_back(v);
 	for(int i = 0; i < rG[v].size(); ++i){
 		if(!used[rG[v][i]]) rdfs(rG[v][i], k);
 	}
 }
 
 int scc(){
 	for(int i = 0; i < N; ++i) used[i] = false;
 	for(int v = 0; v < N; ++v){
 		if(!used[v]) dfs(v);
 	}
 	for(int i = 0; i < N; ++i) used[i] = false;
 	int k = 0;
 	for(int i = (int)vs.size() - 1; i >= 0; --i){
 		if(!used[vs[i]]) rdfs(vs[i], k++);
 	}
 	return k;
 }
 
 vector<int> rs;
 
 int dfs2(int v, int p){
 	int x = 0;
 	for(int i = 0; i < rG[v].size(); ++i){
 		int u = rG[v][i];
 		if(u == p) continue;
 		int tmp = dfs2(u, v);
 		x = max(x, tmp);
 	}
 	return x + 1;
 }
 
 int solve(){
 	rs.clear();
 	int cnum = scc();
 	int ans = 0;
 	for(int i = 0; i < cnum; ++i){
 		ans = max(ans, (int)cc_vs[i].size());
 		if(cc_vs[i].size() == 2) rs.push_back(i);
 	}
 	vector<int> vals;
 	for(int i = 0; i < rs.size(); ++i){
 		int id = rs[i];
 		int u = cc_vs[id][0];
 		int v = cc_vs[id][1];
 		int x1 = dfs2(u, v);
 		int x2 = dfs2(v, u);
 		int x = x1 + x2;
 		vals.push_back(x);
 	}
 	sort(vals.begin(), vals.end());/*
 	if(vals.size() == 1){
 		ans = max(ans,vals[0]);
 	}else if(vals.size() >= 2){
 		reverse(vals.begin(), vals.end());
 		ans = max(ans, vals[0] + vals[1]);
 	}*/
 	int tmp = 0;
 	for(int i = 0; i < vals.size(); ++i) tmp += vals[i];
 	ans = max(ans, tmp);
 	return ans;
 }
 
 void input(){
 	scanf("%d", &N);
 	for(int i = 0; i < N; ++i){
 		int v;
 		scanf("%d", &v);
 		v--;
 		G[i].push_back(v);
 		rG[v].push_back(i);
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 1; datano <= T; ++datano){
 		init();
 		input();
 		int ans = solve();
 		printf("Case #%d: %d\n", datano, ans);
 	}
 	return 0;
 }
