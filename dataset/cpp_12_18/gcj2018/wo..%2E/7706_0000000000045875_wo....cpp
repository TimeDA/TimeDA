#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int vals[4][4];
int N;

int getId(int i, int j){
	return i * N + j;
}

bool con[16][16];

int solve(){
	if(N > 4) return 0;
	memset(con, false, sizeof(con));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			for(int k = 0; k < N; ++k){
				if(vals[i][j] == vals[k][j] && i != k) con[getId(i, j)][getId(k, j)] = true;
				if(vals[i][j] == vals[i][k] && j != k) con[getId(i, j)][getId(i, k)] = true;
			}
		}
	}
	int res = 0;
	for(int state = 0; state < (1 << (N * N)); ++state){
		int cnt = 0;
		bool flg = true;
		for(int i = 0; i < N * N; ++i){
			if((state >> i) & 1){
				cnt++;
				for(int j = i + 1; j < N * N; ++j){
					if((state >> j) & 1){
						if(con[i][j]) flg = false;
					}
				}
			}
		}
		if(flg) res = max(res, cnt);
	}
	return N * N - res;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				scanf("%d", &vals[i][j]);
			}
		}
		int ans = solve();
		printf("Case #%d: %d\n", t + 1, ans);
	}
	return 0;
}
