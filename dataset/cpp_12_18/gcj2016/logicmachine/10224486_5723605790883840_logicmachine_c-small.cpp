#include <iostream>
 #include <string>
 #include <vector>
 #include <queue>
 #include <algorithm>
 
 using namespace std;
 static const int INF = 1000000000;
 static const int dx[] = { 0, 1, 0, -1 };
 static const int dy[] = { -1, 0, 1, 0 };
 inline bool between(int a, int b, int c){
 	return a <= b && b < c;
 }
 
 int translate(int x, int r, int c){
 	if(x < c){
 		const int t = x;
 		return (0 * c + t) * 4 + 0;
 	}else if(x < c + r){
 		const int t = x - c;
 		return (t * c + (c - 1)) * 4 + 1;
 	}else if(x < c + r + c){
 		const int t = (c - 1) - (x - c - r);
 		return ((r - 1) * c + t) * 4 + 2;
 	}else{
 		const int t = (r - 1) - (x - c - r - c);
 		return (t * c + 0) * 4 + 3;
 	}
 }
 
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int r, c;
 		cin >> r >> c;
 		const int n = 2 * (r + c);
 		vector<int> a(n);
 		for(int i = 0; i < n; ++i){
 			cin >> a[i];
 			--a[i];
 		}
 		const int m = r * c;
 		vector<vector<int>> base_conn(m * 4);
 		for(int i = 0; i < r; ++i){
 			for(int j = 0; j < c; ++j){
 				for(int d = 0; d < 4; ++d){
 					const int u = (i * c + j) * 4 + d;
 					const int ii = i + dy[d], jj = j + dx[d];
 					if(!between(0, ii, r) || !between(0, jj, c)){ continue; }
 					const int v = (ii * c + jj) * 4 + (d ^ 2);
 					base_conn[u].push_back(v);
 				}
 			}
 		}
 		int answer = -1;
 		for(int w = 0; w < (1 << m); ++w){
 			vector<vector<int>> conn(base_conn);
 			for(int i = 0; i < r; ++i){
 				for(int j = 0; j < c; ++j){
 					const int b = i * c + j;
 					const int u0 = b * 4;
 					if((w & (1 << b)) == 0){
 						conn[u0 + 0].push_back(u0 + 1);
 						conn[u0 + 1].push_back(u0 + 0);
 						conn[u0 + 2].push_back(u0 + 3);
 						conn[u0 + 3].push_back(u0 + 2);
 					}else{
 						conn[u0 + 0].push_back(u0 + 3);
 						conn[u0 + 3].push_back(u0 + 0);
 						conn[u0 + 1].push_back(u0 + 2);
 						conn[u0 + 2].push_back(u0 + 1);
 					}
 				}
 			}
 			vector<int> reachability(n);
 			for(int i = 0; i < n; ++i){
 				vector<int> d(m * 4, INF);
 				queue<int> q;
 				const int s = translate(i, r, c);
 				d[s] = 0;
 				q.push(s);
 				while(!q.empty()){
 					const int u = q.front();
 					q.pop();
 					for(const auto v : conn[u]){
 						if(d[v] >= INF){
 							d[v] = d[u];
 							q.push(v);
 						}
 					}
 				}
 				for(int j = 0; j < n; ++j){
 					if(d[translate(j, r, c)] < INF){
 						reachability[i] |= (1 << j);
 					}
 				}
 			}
 			bool valid = true;
 			for(int i = 0; i < n; ++i){
 				const int ti = a[i];
 				const int tj = a[i ^ 1];
 				if(reachability[a[i]] != ((1 << ti) | (1 << tj))){ valid = false; }
 			}
 			if(valid){
 				answer = w;
 				break;
 			}
 		}
 		cout << "Case #" << case_num << ":" << endl;
 		if(answer < 0){
 			cout << "IMPOSSIBLE" << endl;
 		}else{
 			for(int i = 0; i < r; ++i){
 				for(int j = 0; j < c; ++j){
 					const int t = (i * c + j);
 					cout << "\\/"[(answer >> t) & 1];
 				}
 				cout << endl;
 			}
 		}
 	}
 	return 0;
 }
 
