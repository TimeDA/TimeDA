#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int root[400];
int size[400];
int valid[400];
int getRoot(int v){ return root[v] == -1 ? v : root[v] = getRoot(root[v]); }

int solve(const vector<string>& D){
	vector<int> pattern(16, 0);
	const int R = D.size();
	const int C = D[0].size();
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			int p = (D[min(R-1, i+1)][min(C-1, j+1)] == 'B' ? 0 : 1);
			p = 2 * p + (D[min(R-1, i+1)][j] == 'B' ? 0 : 1);
			p = 2 * p + (D[i][min(C-1, j+1)] == 'B' ? 0 : 1);
			p = 2 * p + (D[i][j] == 'B' ? 0 : 1);
			pattern[p] = 1;
		}
	}
	int res = 0;
	for(int i=0;i<16;i++){
		if(!pattern[i]) continue;
		for(int thrI = 0;thrI<=R;thrI++){
			for(int thrJ=0;thrJ<=C;thrJ++){
				memset(valid, 0, sizeof(valid));
				memset(root, -1, sizeof(root));
				fill(size, size+R*C, 1);
				for(int r=0;r<R;r++){
					for(int c=0;c<C;c++){
						int chk = 2 * (r >= thrI ? 1 : 0) + (c >= thrJ ? 1 : 0);
						if(D[r][c] == ((i&(1<<chk)) ? 'W' : 'B')) valid[r*C+c] = 1;
					}
				}
				auto check = [&](int a, int b){
					if(!valid[a] || !valid[b]) return;
					int p = getRoot(a);
					int q = getRoot(b);
					if(p != q){
						size[p] += size[q];
						root[q] = p;
					}
				};
				for(int r=0;r<R;r++){
					for(int c=0;c<C;c++){
						if(c+1 < C) check(r*C+c, r*C+c+1);
						if(r+1 < R) check(r*C+c, (r+1)*C+c);
					}
				}
				for(int j=0;j<R*C;j++) res = max(res, size[j]);
			}
		}
	}
	return res;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int R, C; cin >> R >> C;
		vector<string> D(R);
		for(auto& s : D) cin >> s;
		printf("Case #%d: %d\n", t, solve(D));
	}
}
