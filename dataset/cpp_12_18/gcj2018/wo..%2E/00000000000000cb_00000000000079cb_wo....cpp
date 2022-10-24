#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vec[2];

int vals[100100];
int N;

int a[100100];

int solve(){
	for(int i = 0; i < 2; ++i){
		vec[i].clear();
	}
	for(int i = 0; i < N; ++i){
		vec[i % 2].push_back(vals[i]);
	}
	for(int i = 0; i < 2; ++i){
		sort(vec[i].begin(), vec[i].end());
	}
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < vec[i].size(); ++j){
			int id = i + j * 2;
			a[id] = vec[i][j];
		}
	}
	int ans = -1;
	for(int i = 0; i + 1 < N; ++i){
		if(a[i] > a[i + 1]){
			ans = i;
			break;
		}
	}
	return ans;
}


int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) scanf("%d", vals + i);
		int ans = solve();
		printf("Case #%d: ", t + 1);
		if(ans == -1) printf("OK\n");
		else printf("%d\n", ans);
	}
	return 0;
}
