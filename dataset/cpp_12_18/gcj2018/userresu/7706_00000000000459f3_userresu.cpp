#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

int dp[110][110][110][110];
void main2 () {
	int R, B;
	scanf("%d %d",&R,&B);
	int S = R+B;
	for (int r=0;r<=R;++r) for (int b=0;b<=B;++b) {
		for (int d=1;d<=S;++d) {
			for (int x=d;x>=0;--x) {
				int y = d - x;
				if (x < d) dp[r][b][d][x] = dp[r][b][d][x+1];
				else dp[r][b][d][x] = dp[r][b][d-1][0];
				if (x > r || y > b) continue;
				if (x < d) dp[r][b][d][x] = max(dp[r][b][d][x], 1 + dp[r-x][b-y][d][x+1]);
				else dp[r][b][d][x] = max(dp[r][b][d][x], 1 + dp[r-x][b-y][d-1][0]);
			}
		}
	}
	printf("%d\n",dp[R][B][S][0]);
}

int main () {
	int T = 1;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		printf("Case #%d: ", z);
		main2();
	}
	return 0;
}
