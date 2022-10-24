#include<cstdio>
#include<utility>
#include<cstring>

using namespace std;

typedef pair<int, int> P;

bool field[20][20];

const int O = 100;

const int di[] = {1, 0, -1};
const int dj[] = {1, 0, -1};

int put(int i, int j){
	printf("%d %d\n", i + O, j + O);
	fflush(stdout);
}

P get(){
	int i, j;
	scanf("%d%d", &i, &j);
	if(i == 0 && j == 0) return P(-1, -1);
	return P(i, j);
}

void solve(){
	memset(field, false, sizeof(field));
	for(int i = 1; i <= 13; ++i){
		for(int j = 1; j <= 12; ++j){
			int cnt = 0;
			for(int x = 0; x < 3; ++x){
				for(int y = 0; y < 3; ++y){
					if(!field[i + di[x]][j + dj[y]]) cnt++;
				}
			}
			while(cnt > 0){
				put(i, j);
				P p = get();
				if(p.first == -1) return;
				int ci = p.first - O;
				int cj = p.second - O;
				if(!field[ci][cj]){
					field[ci][cj] = true;
					cnt--;
				}
			}
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int A;
		scanf("%d", &A);
		solve();
	}
	return 0;
}
