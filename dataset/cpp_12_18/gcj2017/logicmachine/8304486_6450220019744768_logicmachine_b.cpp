#include <iostream>
 #include <string>
 #include <vector>
 #include <unordered_set>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 using pii = pair<int, int>;
 static const int INF = 1000000000;
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n, m;
 		cin >> n >> m;
 		vector<vector<pii>> conn(n);
 		vector<pii> edges(m);
 		for(int i = 0; i < m; ++i){
 			int a, b;
 			cin >> a >> b;
 			--a; --b;
 			conn[a].push_back(pii(b,  i));
 			conn[b].push_back(pii(a, ~i));
 			edges[i] = pii(a, b);
 		}
 
 		bool possible = true;
 		for(int i = 0; i < m; ++i){
 			const int s = edges[i].first, t = edges[i].second;
 			vector<int> d(n, INF);
 			queue<int> q;
 			d[s] = 0;
 			q.push(s);
 			while(!q.empty()){
 				const int u = q.front();
 				q.pop();
 				for(const auto& e : conn[u]){
 					if(e.second == i){ continue; }
 					const int v = e.first;
 					if(d[v] < INF){ continue; }
 					d[v] = d[u] + 1;
 					q.push(v);
 				}
 			}
 			if(d[t] >= INF){ possible = false; }
 		}
 		if(!possible){
 			cout << "Case #" << case_num << ": " << "IMPOSSIBLE" << endl;
 			continue;
 		}
 
 		vector<int> w(m, 0);
 		for(int i = 0; i < m; ++i){
 			if(w[i] != 0){ continue; }
 			const int s = edges[i].first, t = edges[i].second;
 			vector<int> d(n, INF);
 			vector<pii> p(n, pii(-1, -1));
 			queue<int> q;
 			d[t] = 0;
 			q.push(t);
 			while(!q.empty()){
 				const int u = q.front();
 				q.pop();
 				for(const auto& e : conn[u]){
 					if(e.second == i || e.second == ~i){ continue; }
 					const int v = e.first;
 					if(d[v] < INF){ continue; }
 					d[v] = d[u] + 1;
 					p[v] = pii(u, e.second);
 					q.push(v);
 				}
 			}
 			unordered_set<int> wset, eset;
 			eset.insert(i);
 			wset.insert(0);
 			for(int v = s; v != t; v = p[v].first){
 				const int e = p[v].second;
 				eset.insert(e);
 				wset.insert(e >= 0 ? -w[e] : w[~e]);
 			}
 			int pos = 0, neg = 0;
 			for(int i = 1; i <= n * n; ++i){
 				if(wset.find(i) == wset.end()){
 					pos = i;
 					break;
 				}
 			}
 			for(int i = 1; i <= n * n; ++i){
 				if(wset.find(-i) == wset.end()){
 					neg = i;
 					break;
 				}
 			}
 			const int diff = (pos <= neg ? pos : -neg);
 			for(const auto e : eset){
 				if(e >= 0){
 					w[e] += diff;
 				}else{
 					w[~e] -= diff;
 				}
 			}
 		}
 
 		cout << "Case #" << case_num << ":";
 		for(const auto& x : w){ cout << " " << x; }
 		cout << endl;
 	}
 	return 0;
 }
 
