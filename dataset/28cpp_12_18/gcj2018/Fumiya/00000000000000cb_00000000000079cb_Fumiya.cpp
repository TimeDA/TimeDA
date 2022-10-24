#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void solve(){
	int N; cin >> N;
	vector<vector<int>> v(2, vector<int>());
	for(int i=0;i<N;i++){
		int t; scanf("%d", &t);
		v[i%2].push_back(t);
	}
	for(auto& t : v) sort(t.begin(), t.end());
	vector<int> a(N);
	for(int i=0;i<N;i++){
		a[i] = v[i%2][i/2];
	}
	for(int i=0;i+1<N;i++){
		if(a[i] > a[i+1]){
			cout << i << endl;
			return;
		}
	}
	cout << "OK" << endl;
}

int main(){
	int T; cin >> T;
	for(int i=1;i<=T;i++){
		printf("Case #%d: ", i);
		solve();
	}
}
