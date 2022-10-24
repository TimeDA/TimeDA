#include<cstdio>
 #include<utility>
 #include<queue>
 #include<vector>
 #include<algorithm>
 
 using namespace std;
 
 typedef pair<int, int> P;
 
 P getP(int r, int q){
 	
 	/*int lb = 1200200, ub = 0;
 	for(int i = 1; i <= 1200200; ++i){
 		long long a = (long long)r * i;
 		if(9 * a <= 10ll * q && 10ll * q <= 11 * a){
 			lb = min(lb, i);
 			ub = max(ub, i);
 		}
 	}
 	if(lb > ub) return P(0, 0);
 	return P(lb, ub);*/
 	int lb = (double)q / (1.1 * r);
 	int ub = (double)q / (0.9 * r);
 	int tmpl = lb + 3;
 	bool okl = false;
 	for(int i = -3; i <= 3; ++i){
 		if(lb + i <= 0) continue;
 		int cur = lb + i;
 		long long a = (long long)r * cur;
 		if(9 * a <= 10ll * q && 10ll * q <= 11 * a){
 			tmpl = cur;
 			okl = true;
 			break;
 		}
 	}
 	int tmpr = ub - 3;
 	bool okr = false;
 	for(int i = 3; i >= -3; --i){
 		int cur = ub + i;
 		if(cur <= 0) continue;
 		long long a = (long long)r * cur;
 		if(9 * a <= 10ll * q && 10ll * q <= 11 * a){
 			tmpr = cur;
 			okr = true;
 			break;
 		}
 	}
 	if(tmpr < 0) return P(0, 0);
 	if(tmpl > tmpr){
 		return P(0, 0);
 //		fprintf(stderr, "a\n");
 	}
 	if((!okl) || (!okr)) return P(0, 0);	
 	return P(tmpl, tmpr);
 }
 
 vector<P> ps[55];
 int it[55];
 int N;
 int Pnum;
 
 priority_queue<int, vector<int>, greater<int> > que[55];
 
 int rs[55];
 int qs[55][55];
 
 int solve(){
 	for(int i = 0; i < N; ++i){
 		ps[i].clear();
 		while(que[i].size() > 0) que[i].pop();
 		it[i] = 0;
 		for(int j = 0; j < Pnum; ++j){
 			P p = getP(rs[i], qs[i][j]);
 			if(p.second <= 0) continue;
 			ps[i].push_back(p);
 			//printf("%d %d\n", p.first, p.second);
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		sort(ps[i].begin(), ps[i].end());
 	}
 	int ans = 0;
 	for(int l = 1; l < 1200100; ++l){
 		for(int i = 0; i < N; ++i){
 			for(; it[i] < ps[i].size(); ++it[i]){
 				if(ps[i][it[i]].first > l) break;
 				que[i].push(ps[i][it[i]].second);
 			}
 		}
 		while(true){
 			bool found = false;
 			for(int i = 0; i < N; ++i){
 				if(!que[i].empty()){
 					if(que[i].top() == l){
 						found = true;
 						bool flg = true;
 						for(int j = 0; j < N; ++j){
 							if(que[j].empty()){
 								flg = false;
 								break;
 							}
 						}
 						if(flg){
 							for(int j = 0; j < N; ++j){
 								que[j].pop();
 							}
 							ans++;
 						}else{
 							que[i].pop();
 						}
 					}
 				}
 			}
 			if(!found) break;
 		}
 	}
 	return ans;
 }
 
 void input(){
 	scanf("%d%d", &N, &Pnum);
 	for(int i = 0; i < N; ++i){
 		scanf("%d", rs + i);
 	}
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < Pnum; ++j){
 			scanf("%d", &(qs[i][j]));
 		}
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		int ans = solve();
 		printf("Case #%d: %d\n", datano + 1, ans);
 	}
 	return 0;
 }
