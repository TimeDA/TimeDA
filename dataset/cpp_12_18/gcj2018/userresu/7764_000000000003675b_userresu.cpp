#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;
#define MAXN 100003

int c[MAXN][2];
int n[MAXN][2], dp[MAXN][2];
void main2 () {
	int mx = 0, mxcnt = 0;
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;++i) {
		int d, a, b;
		scanf("%d %d %d",&d,&a,&b);
		c[i][0] = d + a;
		c[i][1] = d - b;
	}
	n[N][0] = n[N][1] = N+1;
	for (int i=N-1;i>=1;--i) {
		for (int j=0;j<2;++j) {
			n[i][j] = i+1;
			if (c[i+1][j] == c[i][j]) n[i][j] = n[i+1][j];
		}
	}
	dp[N-1][0] = dp[N-1][1] = N+1;
	for (int i=N-2;i>=1;--i) {
		for (int j=0;j<2;++j) {
			int col = c[i][j];
			int col2 = c[i+1][1-j];
			int k = n[i+1][1-j];
			if (k <= N && c[k][j] == col) dp[i][j] = dp[k-1][1-j];
			else dp[i][j] = k;
		}
	}
	for (int i=1;i<=N;++i) {
		int mxnow = 0;
		for (int j=0;j<2;++j) {
			int col = c[i][j];
			int l = n[i][j];
			if (l <= N) l = dp[l-1][j];
			mxnow = max(mxnow, l - i);
		}
		if (mx < mxnow) mx = mxnow, mxcnt = 1;
		else if (mx == mxnow) ++mxcnt;
	}
	printf("%d %d\n",mx,mxcnt);
}

int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		printf("Case #%d: ", z);
		main2();
	}
	return 0;
}
