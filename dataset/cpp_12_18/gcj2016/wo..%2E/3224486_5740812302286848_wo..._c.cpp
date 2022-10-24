#include<cstdio>
 #include<set>
 #include<utility>
 #include<cmath>
 #include<queue>
 #include<algorithm>
 
 using namespace std;
 
 typedef double Real;
 
 typedef pair<int, int> P;
 typedef pair<Real, P> PP;
 
 const Real eps = 1e-8;
 const Real inf = 1e100;
 
 template<class T> bool eq_(T a, T b){
 	return abs(a - b) < eps;
 }
 
 template<class T> bool lt_(T a, T b){
 	if(eq_(a, b)) return false;
 	return a < b;
 }
 
 template<class T> bool le_(T a, T b){
 	if(eq_(a, b)) return true;
 	return a < b;
 }
 
 bool graph[1010][1010];
 bool ok[1010];
 int deg[1010];
 Real iso[1010];
 
 int N;
 int xs[1010], ys[1010], zs[1010];
 int vxs[1010], vys[1010], vzs[1010];
 
 Real as[1010][1010], bs[1010][1010], cs[1010][1010];
 
 Real S;
 
 void initCoe(){
 	for(int i = 0; i < N; ++i){
 		for(int j = 0; j < N; ++j){
 			if(i == j) continue;
 			as[i][j] = 0;
 			bs[i][j] = 0;
 			cs[i][j] = 0;
 			int q = xs[i] - xs[j];
 			int p = vxs[i] - vxs[j];
 			as[i][j] += p * p;
 			bs[i][j] += p * q * 2;
 			cs[i][j] += q * q;
 			q = ys[i] - ys[j];
 			p = vys[i] - vys[j];
 			as[i][j] += p * p;
 			bs[i][j] += p * q * 2;
 			cs[i][j] += q * q;
 			q = zs[i] - zs[j];
 			p = vzs[i] - vzs[j];
 			as[i][j] += p * p;
 			bs[i][j] += p * q * 2;
 			cs[i][j] += q * q;
 			
 		//	printf("(%d %d): (%f %f %f)\n", i, j, as[i][j], bs[i][j], cs[i][j]);
 		}
 	}
 }
 
 vector<PP> pps;
 
 Real D2;
 
 void getEvent(int i, int j, bool debug = false){
 	Real a = as[i][j], b = bs[i][j], c = cs[i][j];
 	//at^2 + bt + c = D2
 	c -= D2;
 	if(eq_(a, (Real)0)){
 		if(eq_(b, (Real)0)){
 			if(le_(c, (Real)0)){
 				pps.push_back(PP(0, P(i, j)));
 				pps.push_back(PP(inf, P(i, j)));
 			}
 		}else{
 			Real t = - c / b;
 			if(lt_((Real)0, t)){
 				pps.push_back(PP(0, P(i, j)));
 				pps.push_back(PP(t, P(i, j)));
 			}
 		}
 	}else{
 		Real det = b * b - 4.0 * a * c;
 		if(lt_(det, (Real)0.0)) return;
 		det = max(det, (Real)0.0);
 		Real t1 = (-b-sqrt(det)) / (2.0 * a);
 		Real t2 = (-b+sqrt(det)) / (2.0 * a);
 	/*	if(i == 0 && j == 4 && debug){
 			printf("--- %f %f ---\n", t1, t2);
 		}*/
 		if(le_(t2, (Real)0)) return;
 		pps.push_back(PP(t1, P(i, j)));
 		pps.push_back(PP(t2, P(i, j)));
 	}
 }
 
 bool check(Real d, bool debug = false){
 	D2 = d * d;
 	pps.clear();
 	for(int i = 0; i < N; ++i){
 		for(int j = i + 1; j < N; ++j){
 			getEvent(i, j, debug);
 		}
 	}
 	sort(pps.begin(), pps.end());
 	for(int i = 0; i < N; ++i){
 		ok[i] = false;
 		deg[i] = 0;
 		iso[i] = -inf;
 		for(int j = 0; j < N; ++j){
 			graph[i][j] = false;
 		}
 	}
 	ok[0] = true;
 	iso[0] = 0;
 	
 	set<int> se;
 	for(int i = 1; i < N; ++i) se.insert(i);
 	
 	for(int i = 0; i < pps.size(); ++i){
 		PP pp = pps[i];
 		int u = pp.second.first;
 		int v = pp.second.second;
 		Real t = pp.first;
 	//	if(debug) printf("(%f %d %d)\n", t, u, v);
 		if(!graph[u][v]){
 			graph[u][v] = true;
 			graph[v][u] = true;
 			deg[v]++;
 			deg[u]++;
 			if(ok[v] && (deg[v] == 1)){
 				if(lt_(S, t - iso[v])){
 					ok[v] = false;
 					se.insert(v);
 				}
 			}
 			if(ok[u] && (deg[u] == 1)){
 				if(lt_(S, t - iso[u])){
 					ok[u] = false;
 					se.insert(u);
 				}
 			}
 			
 			if(ok[v] && (!ok[u])){
 				swap(u, v);
 			}
 			if(ok[u] && (!ok[v])){
 				//from u to v
 				queue<int> que;
 				que.push(u);
 				while(!que.empty()){
 					int u = que.front();
 					que.pop();
 					for(set<int> :: iterator it = se.begin(); it != se.end();){
 						int v = (*it);
 						if(graph[u][v]){
 							que.push(v);
 							ok[v] = true;
 							se.erase(it++);
 						}else{
 							it++;
 						}
 					}
 				}
 			}
 		}else{
 			graph[v][u] = false;
 			graph[u][v] = false;
 			deg[u]--;
 			deg[v]--;
 			if(deg[u] == 0){
 				iso[u] = t;
 			}
 			if(deg[v] == 0){
 				iso[v] = t;
 			}
 		}
 	}
 	return ok[1];
 }
 
 Real solve(){
 	initCoe();
 	Real lb = 0, ub = 1e5;
 	for(int stage = 0; stage < 40; stage++){
 		Real mid = (ub + lb) / 2;
 		bool flg = check(mid);
 		if(flg) ub = mid;
 		else lb = mid;
 	}
 	check(5, true);
 	return lb;
 }
 
 void input(){
 	int S_;
 	scanf("%d%d", &N, &S_);
 	S = S_;
 	for(int i = 0; i < N; ++i){
 		scanf("%d%d%d%d%d%d", xs + i, ys + i, zs + i, vxs + i, vys + i, vzs + i);
 	}
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 0; datano < T; ++datano){
 		input();
 		Real ans = solve();
 		printf("Case #%d: %.9f\n", datano + 1, ans);
 	}
 	return 0;
 }
