#include<cstdio>
 #include<vector>
 #include<utility>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int, int> P;
 
 int ids[55][55];
 int R, C;
 char field[55][55];
 
 void input(){
 	char ch[55];
 	scanf("%d%d", &R, &C);
 	for(int i = 0; i <= R + 1; ++i){
 		for(int j = 0; j <= C + 1; ++j){
 			field[i][j] = '#';
 		}
 	}
 	for(int i = 0; i < R; ++i){
 		scanf("%s", ch);
 		for(int j = 0; j < C; ++j){
 			field[i + 1][j + 1] = ch[j];
 		}
 	}
 }
 
 char ans[55][55];
 
 vector<int> G[55 * 55 * 2];
 vector<int> rG[55 * 55 * 2];
 
 const int di[] = {1, 0, -1, 0};
 const int dj[] = {0, 1, 0, -1};
 
 P go(int ci, int cj, int cd){
 	if(field[ci][cj] == '#') return P(-1, -1);
 	if(ids[ci][cj] != -1) return P(ids[ci][cj], cd);
 	if(field[ci][cj] == '|') return P(-2, -2);
 	if(field[ci][cj] == '-') return P(-2, -2);
 	if(field[ci][cj] == '/'){
 		int nd = 3 - cd;
 		return go(ci + di[nd], cj + dj[nd], nd);
 	}
 	if(field[ci][cj] == '\\'){
 		int nd = cd ^ 1;
 		return go(ci + di[nd], cj + dj[nd], nd);
 	}
 	if(field[ci][cj] == '.'){
 		return go(ci + di[cd], cj + dj[cd], cd);
 	}
 	fprintf(stderr, "error!\n");
 	return P(-3, -3);
 }
 
 bool check(int ci, int cj, int cd){
 	//printf("%d %d %d\n", ci, cj, cd);
 	if(field[ci][cj] == '#'){
 		//printf("true\n");
 		return true;
 	}
 	if(field[ci][cj] == '|') return false;
 	if(field[ci][cj] == '-') return false;
 	if(field[ci][cj] == '/'){
 		int nd = 3 - cd;
 		return check(ci + di[nd], cj + dj[nd], nd);
 	}
 	if(field[ci][cj] == '\\'){
 		int nd = cd ^ 1;
 		return check(ci + di[nd], cj + dj[nd], nd);
 	}
 	if(field[ci][cj] == '.'){
 		return check(ci + di[cd], cj + dj[cd], cd);
 	}
 	fprintf(stderr, "error!\n");
 	return false;
 }
 
 void add_edge(int from, int to){
 	//printf("%d %d\n", from, to);
 	G[from].push_back(to);
 	rG[to].push_back(from);
 }
 
 vector<int> vs;
 bool used[55 * 55 * 2];
 int cmp[55 * 55 * 2];
 int N;
 
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
 	for(int i = 0; i < rG[v].size(); ++i){
 		if(!used[rG[v][i]]){
 			rdfs(rG[v][i], k);
 		}
 	}
 }
 
 int scc(){
 	vs.clear();
 	for(int i = 0; i < N; ++i){
 		used[i] = false;
 	}
 	for(int v = 0; v < N; ++v){
 		if(!used[v]){
 			dfs(v);
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		used[i] = false;
 	}
 	int k = 0;
 	for(int i = vs.size() - 1; i >= 0; --i){
 		if(!used[vs[i]]){
 			rdfs(vs[i], k++);
 		}
 	}
 	return k;
 }
 
 void clear_graph(){
 	for(int i = 0; i < 55 * 55 * 2; ++i){
 		G[i].clear();
 		rG[i].clear();
 	}
 }
 
 bool solve(){
 	clear_graph();
 	int cnt = 0;
 	for(int i = 1; i <= R; ++i){
 		for(int j = 1; j <= C; ++j){
 			ids[i][j] = -1;
 		}
 	}
 	for(int i = 1; i <= R; ++i){
 		for(int j = 1; j <= C; ++j){
 			if(field[i][j] == '|' || field[i][j] == '-'){
 				ids[i][j] = cnt++;
 			}
 		}
 	}
 	N = cnt * 2;
 	for(int i = 1; i <= R; ++i){
 		for(int j = 1; j <= C; ++j){
 			if(field[i][j] != '.') continue;
 			P ps[4];
 			for(int k = 0; k < 4; ++k){
 				ps[k] = go(i, j, k);
 			}
 			P ps2[2];
 			if(ps[0].first >= 0 && ps[2].first >= 0){
 				return false;
 			}else{
 				ps2[0] = max(ps[0], ps[2]);
 			}
 			if(ps[1].first >= 0 && ps[3].first >= 0){
 				return false;
 			}else{
 				ps2[1] = max(ps[1], ps[3]);
 			}
 			if(ps2[0] > ps2[1]) swap(ps2[0], ps2[1]);
 			if(ps2[1].first < 0){
 				return false;
 			}else if(ps2[0].first < 0){
 				int x = ps2[1].first;
 				int y = ps2[1].second % 2;
 				add_edge(x * 2 + (y ^ 1), x * 2 + y);
 			}else{
 				int x0 = ps2[0].first;
 				int y0 = ps2[0].second % 2;
 				int x1 = ps2[1].first;
 				int y1 = ps2[1].second % 2;
 				add_edge(x0 * 2 + (y0 ^ 1), x1 * 2 + y1);
 				add_edge(x1 * 2 + (y1 ^ 1), x0 * 2 + y0);
 			}
 		}
 	}
 //	printf("b\n");
 	for(int i = 1; i <= R; ++i){
 		for(int j = 1; j <= C; ++j){
 			if(ids[i][j] < 0) continue;
 			int x = ids[i][j];
 			bool tok = check(i + di[1], j + dj[1], 1) & check(i + di[3], j + dj[3], 3);
 			bool fok = check(i + di[0], j + dj[0], 0) & check(i + di[2], j + dj[2], 2);
 			if((!tok) & (!fok)) return false;
 			else if(!tok){
 				add_edge(x * 2 + 1, x * 2);
 			}else if(!fok){
 				add_edge(x * 2, x * 2 + 1);
 			}else{
 				// do nothing
 			}
 		}
 	}
 //	printf("c\n");
 	scc();
 	for(int i = 0; i < R; ++i){
 		for(int j = 0; j < C; ++j){
 			if(ids[i + 1][j + 1] < 0){
 				ans[i][j] = field[i + 1][j + 1];
 			}else{
 				int x = ids[i + 1][j + 1];
 				if(cmp[x * 2] == cmp[x * 2 + 1]){
 //					printf("%d %d\n", x, cmp[x * 2]);
 					return false;
 				}else if(cmp[x * 2] < cmp[x * 2 + 1]){
 					// true
 					ans[i][j] = '-';
 				}else{
 					ans[i][j] = '|';
 				}
 			}
 		}
 		ans[i][C] = '\0';
 	}
 	return true;
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		bool flg = solve();
 		if(!flg){
 			printf("Case #%d: IMPOSSIBLE\n", datano + 1);
 		}else{
 			printf("Case #%d: POSSIBLE\n", datano + 1);
 			for(int i = 0; i < R; ++i){
 				printf("%s\n", ans[i]);
 			}
 		}
 	}
 	return 0;
 }
