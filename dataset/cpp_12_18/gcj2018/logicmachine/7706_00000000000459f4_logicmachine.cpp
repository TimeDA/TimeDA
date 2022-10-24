#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
using pii = pair<int, int>;
static const int dx[] = { 0, 1, 0, -1 };
static const int dy[] = { 1, 0, -1, 0 };

inline bool between(int a, int b, int c){
	return a <= b && b < c;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> pattern(n);
	for(int i = 0; i < n; ++i){ cin >> pattern[i]; }
	vector<vector<int>> p(n, vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){ p[i][j] = (pattern[i][j] == 'B' ? 0 : 1); }
	}

	vector<int> table(1 << 4);
	// H=1, W=2
	for(int i = 0; i < n; ++i){
		for(int j = 0; j + 1 < m; ++j){
			int bits = 0;
			bits = (bits << 1) | p[i + 0][j + 0];
			bits = (bits << 1) | p[i + 0][j + 1];
			bits = (bits << 1) | p[i + 0][j + 0];
			bits = (bits << 1) | p[i + 0][j + 1];
			table[bits] = 1;
		}
	}
	// H=2, W=1
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j < m; ++j){
			int bits = 0;
			bits = (bits << 1) | p[i + 0][j + 0];
			bits = (bits << 1) | p[i + 0][j + 0];
			bits = (bits << 1) | p[i + 1][j + 0];
			bits = (bits << 1) | p[i + 1][j + 0];
			table[bits] = 1;
		}
	}
	// H=2, W=2
	for(int i = 0; i + 1 < n; ++i){
		for(int j = 0; j + 1 < m; ++j){
			int bits = 0;
			bits = (bits << 1) | p[i + 0][j + 0];
			bits = (bits << 1) | p[i + 0][j + 1];
			bits = (bits << 1) | p[i + 1][j + 0];
			bits = (bits << 1) | p[i + 1][j + 1];
			table[bits] = 1;
		}
	}

	int answer = 1;
	for(int b = 0; b < table.size(); ++b){
		if(!table[b]){ continue; }
		for(int y = 0; y <= n; ++y){
			for(int x = 0; x <= m; ++x){
				vector<vector<int>> valid(n, vector<int>(m));
				for(int i = 0; i < n; ++i){
					for(int j = 0; j < m; ++j){
						const int key = (i < y ? 2 : 0) | (j < x ? 1 : 0);
						const int value = (b >> key) & 1;
						if(p[i][j] == value){ valid[i][j] = 1; }
					}
				}
				for(int i = 0; i < n; ++i){
					for(int j = 0; j < m; ++j){
						if(!valid[i][j]){ continue; }
						int size = 0;
						queue<pii> q;
						q.emplace(i, j);
						valid[i][j] = 0;
						while(!q.empty()){
							const pii u = q.front();
							q.pop();
							++size;
							for(int d = 0; d < 4; ++d){
								const int a = u.first  + dy[d];
								const int b = u.second + dx[d];
								if(!between(0, a, n) || !between(0, b, m)){ continue; }
								if(valid[a][b]){
									q.emplace(a, b);
									valid[a][b] = 0;
								}
							}
						}
						answer = max(answer, size);
					}
				}
			}
		}
	}
	cout << answer << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int case_num = 1; case_num <= T; ++case_num){
		cout << "Case #" << case_num << ": ";
		solve();
	}
	return 0;
}

