#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int R, C;

bool isValid[22][22];

bool used[22][22];

bool isin_(int i, int j){
	return (i >= 0 && j >= 0 && i < R && j < C);
}

int bfs(int si, int sj){
	queue<int> qi, qj;
	int res = 0;
	used[si][sj] = true;
	res++;
	qi.push(si);
	qj.push(sj);
	while(!qi.empty()){
		int ci = qi.front();
		qi.pop();
		int cj = qj.front();
		qj.pop();
		for(int d = 0; d < 4; ++d){
			int ni = ci + di[d];
			int nj = cj + dj[d];
			if(!isin_(ni, nj)) continue;
			if(!isValid[ni][nj]) continue;
			if(used[ni][nj]) continue;
			used[ni][nj] = true;
			res++;
			qi.push(ni);
			qj.push(nj);
		}
	}
	return res;
}

int calc(){
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			used[i][j] = false;
		}
	}
	int res = 0;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if((!used[i][j]) && isValid[i][j]){
				int tmp = bfs(i, j);
				res = max(res, tmp);
			}
		}
	}
	return res;
}

bool exi[1 << 4];

int field[22][22]; // white: 0, black: 1

int getState(int i0, int j0, int i, int j){
	if(i <= i0 && j <= j0) return 0;
	if(i <= i0) return 1;
	if(j <= j0) return 2;
	return 3;
}

void fillExi(){
	for(int i = 0; i < (1 << 4); ++i) exi[i] = false;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(field[i][j] == 0) exi[0] = true;
			if(field[i][j] == 1) exi[(1 << 4) - 1] = true;
			if(j + 1 < C) exi[field[i][j] * 5 + field[i][j + 1] * 10] = true;
			if(i + 1 < R) exi[field[i][j] * 3 + field[i + 1][j] * 12] = true;
			if(i + 1 < R && j + 1 < C){
				exi[field[i][j] + field[i][j + 1] * 2 + field[i + 1][j] * 4 + field[i + 1][j + 1] * 8] = true;
			}
		}
	}
}

int lfield[22 * 16][22 * 16];

int solve2(){
	int s = 1;
	int ans = 0;
	for(int d = 1; d <= 4; ++d){
		s *= 2;
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j){
				for(int k = 0; k < s; ++k){
					for(int l = 0; l < s; ++l){
						lfield[i * s + k][j * s + l] = field[i][j];
					}
				}
			}
		}
		for(int x = 0; x + R <= R * s; ++x){
			for(int y = 0; y + C <= C * s; ++y){
				for(int i = 0; i < R; ++i){
					for(int j = 0; j < C; ++j){
						isValid[i][j] = (field[i][j] == lfield[x + i][y + j]);
					}
				}
				ans = max(ans, calc());
			}
		}
	}
	return ans;
}

int solve(){
	fillExi();
	int ans = 0;
//	ans = solve2();
	for(int i0 = 0; i0 < R; ++i0){
		for(int j0 = 0; j0 < C; ++j0){
			for(int state = 0; state < (1 << 4); ++state){
				if(!exi[state]) continue;
				for(int i = 0; i < R; ++i){
					for(int j = 0; j < C; ++j){
						int id = getState(i0, j0, i, j);
						int expected = (state >> id) & 1;
						int actual = field[i][j];
						isValid[i][j] = (expected == actual);
					}
				}
				int tmp = calc();
				ans = max(ans, tmp);
			}
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		scanf("%d%d", &R, &C);
		for(int i = 0; i < R; ++i){
			char ch[100];
			scanf("%s", ch);
			for(int j = 0; j < C; ++j){
				if(ch[j] == 'W') field[i][j] = 0;
				else field[i][j] = 1;
			}
		}
		int ans = solve();
		printf("Case #%d: %d\n", t + 1, ans);
	}
	return 0;
}
