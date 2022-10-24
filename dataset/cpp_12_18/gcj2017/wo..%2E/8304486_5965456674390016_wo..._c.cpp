#include<cstdio>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int, int> P;
 typedef pair<int, P> PP;
 
 vector<int> comps[1010];
 
 vector<PP> from[1010], to[1010];
 //vector<P> from[1010], to[1010];
 int costs[1010];
 bool used[1010][2];
 int N;
 int walking_time;
 int must_wait;
 
 void input(){
 	for(int i = 0; i < 1010; ++i){
 		from[i].clear();
 		to[i].clear();
 	}
 	walking_time = 0;
 	scanf("%d", &N);
 	for(int i = 0; i < N * 2; ++i){
 		int t, s, d;
 		scanf("%d%d%d", &t, &s, &d);
 		t--;
 		int x = (s + d) % 24;
 		walking_time += d;
 		from[t].push_back(PP(i, P(i / 2, x)));
 		to[i / 2].push_back(PP(i, P(t, s)));
 //		from[t].push_back(P(i / 2, x));
 	//	to[i / 2].push_back(P(t, s));
 	//	printf("%d %d %d, %d %d %d\n", t, i / 2, x, i / 2, t, s);
 	}
 	//printf("walking_time = %d\n", walking_time);
 }
 
 inline int wait_time(int x, int y){
 	if(y >= x) return y - x;
 	else return y - x + 24;
 }
 
 void get_costs(){
 	// i = 0
 	must_wait = 0;
 	int i = 0;
 	int a = wait_time(from[i][1].second.second, to[i][1].second.second) + to[i][0].second.second;
 	int b = wait_time(from[i][0].second.second, to[i][1].second.second) + to[i][0].second.second;
 	if(a > b){
 		swap(from[i][0], from[i][1]);
 		swap(a, b);
 	}
 //	printf("a = %d, b = %d\n", a, b);
 	costs[0] = b - a;
 	must_wait += a;
 	for(int i = 1; i < N; ++i){
 		int a = wait_time(from[i][0].second.second, to[i][0].second.second) + wait_time(from[i][1].second.second, to[i][1].second.second);
 		int b = wait_time(from[i][0].second.second, to[i][1].second.second) + wait_time(from[i][1].second.second, to[i][0].second.second);
 		if(a > b){
 			swap(to[i][0], to[i][1]);
 			swap(a, b);
 		}
 		//printf("a = %d, b = %d\n", a, b);
 		must_wait += a;
 		costs[i] = b - a;
 	}
 	//printf("must_wait = %d\n", must_wait);
 }
 
 int decide_greedy(){
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < 2; ++j){
 			used[i][j] = false;
 		}
 	}
 	int c = 0;
 	for(int s = 0; s < N; ++s){
 		for(int i = 0; i < 2; ++i){
 			if(!used[s][i]){
 				int v = s;
 				int id = i;
 				while(true){
 					if(used[v][id]) break;
 				//	printf("%d %d\n", c, v);
 					int nv = to[v][id].second.first;
 					comps[v].push_back(c);
 			//		printf("%d.pb%d\n", v, c);
 					used[v][id] = true;
 					if(from[nv][0].first == to[v][id].first) id = 0;
 					else id = 1;
 //					if(from[nv][0].first == v) id = 0;
 	//				else id = 1;
 					v = nv;
 				}
 				c++;
 			}
 		}
 	}
 	return c;
 }
 
 struct MST{
 	struct UnionFind{
 		int par[1010];
 		void init(int N){
 			for(int i = 0; i < N; ++i) par[i] = i;
 		}
 		int find(int v){
 			if(par[v] == v) return v;
 			return par[v] = find(par[v]);
 		}
 		void unite(int u, int v){
 			u = par[u];
 			v = par[v];
 			if(u == v) return;
 			par[u] = v;
 		}
 		bool same(int u, int v){
 			return find(u) == find(v);
 		}
 	};
 	UnionFind uf;
 	vector<PP> pps;
 	void init(){
 		pps.clear();
 	}
 	void add_edge(int u, int v, int c){
 		pps.push_back(PP(c, P(u ,v)));
 	}
 	int calc(int N){
 		sort(pps.begin(), pps.end());
 		uf.init(N);
 		int res = 0;
 		for(int i = 0; i < pps.size(); ++i){
 			int u = pps[i].second.first, v = pps[i].second.second;
 			if(uf.same(u, v)) continue;
 			uf.unite(u, v);
 			res += pps[i].first;
 		}
 		return res;
 	}
 };
 
 MST mst;
 
 int solve(int t){
 	int ans = -1;
 	for(int stage = 0; stage < 2; ++stage){
 		mst.init();
 		get_costs();
 		for(int i = 0; i < N; ++i){
 			comps[i].clear();
 		}
 		int x = decide_greedy();
 		int cur = walking_time + must_wait;
 		for(int i = 0; i < N; ++i){
 			if(comps[i].size() != 2){
 				fprintf(stderr, "error %d\n", t);
 				exit(0);
 			}
 			if(comps[i][0] != comps[i][1]){
 				mst.add_edge(comps[i][0], comps[i][1], costs[i]);
 			}
 		}
 	//	printf("%d\n", cur);
 		cur += mst.calc(x);
 		//printf("%d\n", cur);
 		if(ans == -1 || ans > cur) ans = cur;
 		swap(to[0][0], to[0][1]);
 	}
 	return ans;
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		int ans = solve(datano);
 		printf("Case #%d: %d\n", datano + 1, ans);
 	}
 	return 0;
 }
