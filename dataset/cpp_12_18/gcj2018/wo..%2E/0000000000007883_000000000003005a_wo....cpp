#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int vals[110][110];
int sum[110][110];

int all;

int R, C;
int H, V;

char ch[200];

void input(){
	scanf("%d%d", &R, &C);
	scanf("%d%d", &H, &V);
	for(int i = 0; i < R; ++i){
		scanf("%s", ch);
		for(int j = 0; j < C; ++j){
			if(ch[j] == '@') vals[i + 1][j + 1] = 1;
			else vals[i + 1][j + 1] = 0;
		}
	}
}

bool solve(){
	for(int i = 1; i <= R; ++i){
		for(int j = 1; j <= C; ++j){
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + vals[i][j];
		}
	}
	all = sum[R][C];
	if(all == 0) return true;
	int num = (H + 1) * (V + 1);
	if(all % num != 0) return false;
	vector<int> hs, vs;
	int prv = 0;
	int each = all / (H + 1);
	for(int i = 1; i <= R; ++i){
		if(sum[i][C] == (prv + 1) * each){
			hs.push_back(i);
			prv++;
		}
	}
	if(prv != H + 1) return false;
	prv = 0;
	each = all / (V + 1);
	for(int j = 1; j <= C; ++j){
		if(sum[R][j] == (prv + 1) * each){
			vs.push_back(j);
			prv++;
		}
	}
	if(prv != V + 1) return false;
	each = all / num;
	for(int i = 0; i <= H; ++i){
		for(int j = 0; j <= V; ++j){
			int tmp = sum[hs[i]][vs[j]];
			if(tmp != each * (i + 1) * (j + 1)) return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		input();
		bool ans = solve();
		printf("Case #%d: ", t + 1);
		if(ans) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
