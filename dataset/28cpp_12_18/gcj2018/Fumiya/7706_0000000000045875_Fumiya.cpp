#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

vector<vector<int>> g;
vector<int> match;
vector<int> visit;

bool search(int u){
	if(u < 0) return true;
	for(int i=0;i<g[u].size();i++){
		int next = g[u][i];
		if(visit[next]) continue;
		visit[next] = 1;
		if(search(match[next])){
			match[u] = next, match[next] = u;
			return true;
		}
	}
	return false;
}

int maximumMatch(int L, int R){
	int res = 0;
	match.assign(L+R, -1);
	for(int i=0;i<L;i++){
		visit.assign(L+R, false);
		res += search(i);
	}
	return res;
}

int solve(const vector<vector<int>>& A){
	const int N = A.size();
	int res = 0;
	for(int v=-N;v<=N;v++){
		g.assign(2*N, vector<int>());
		int cnt = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(A[i][j] != v) continue;
				++cnt;
				g[i].push_back(j+N);
				g[j+N].push_back(i);
			}
		}
		res += cnt - maximumMatch(N, N);
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int N; cin >> N;
		vector<vector<int>> A(N, vector<int>(N));
		for(auto& v : A){
			for(auto& i : v) cin >> i;
		}
		printf("Case #%d: %d\n", t, solve(A));
	}
}
