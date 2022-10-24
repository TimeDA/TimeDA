#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int solve(const vector<pair<int, int>>& vp){
	const int N = vp.size();
	int min_f = 2000000000, max_f = -2000000000, min_s = 2000000000, max_s = -2000000000;
	for(const auto& p : vp){
		min_f = min(min_f, p.first);
		max_f = max(max_f, p.first);
		min_s = min(min_s, p.second);
		max_s = max(max_s, p.second);
	}
	return max((max_f - min_f + 1)/2, (max_s - min_s + 1)/2);
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int N; cin >> N;
		vector<pair<int,int>> vp(N);
		for(auto& p : vp) cin >> p.first >> p.second;
		printf("Case #%d: %d\n", t, solve(vp));
	}
}
