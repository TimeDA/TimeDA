// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;


int dp[2][505][505];
int u = 0;
void solve() {
	static int cs = 0;
	printf("Case #%d: ", ++cs);

	int R, B;
	scanf("%d%d", &R, &B);
	printf("%d\n", dp[u][R][B]-1);
}

void inline update(int &x, int v) {
	if(x<v) x=v;
}

void pre() {
	memset(dp, 0, sizeof(dp));
	u = 0;
	const int N = 500;
	int tri[505]={};
	for(int i=1;i<=N;i++) tri[i] = tri[i-1] + i;

	for(int i=0;i<=N;i++) {
		memset(dp[1-u], 0, sizeof(dp[1-u]));
		for(int r=0;r<=N;r++) {
			for(int b=0;b<=N;b++) {
				update(dp[1-u][r][b], dp[u][r][b]);
				for(int g=0;b+tri[g]<=N && r+i*(g+1)<=N;g++) {
				//	printf("(%d, %d, %d) -> (%d, %d, %d) \n", i, r, b, i+1, r+i*(g+1), b+tri[g]);
					update(dp[1-u][r+i*(g+1)][b+tri[g]], dp[u][r][b] + g + 1);
				}
			}
		}
		u = 1-u;
	}

}

int main(void) {
	int T;
	pre();
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
