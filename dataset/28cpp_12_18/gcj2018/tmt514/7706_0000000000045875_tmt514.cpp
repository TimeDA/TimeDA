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


vector<int> g[100005];
int xy[100005], yx[100005];

int S=0, T=0;
int a[105][105];
int lid[105][105];
int rid[105][105];

int used[10005];
int uid[10005];
int u;
const int N = 128;


int gused[100005];
bool dfs(int x) {
	gused[x] = u;
	for(auto &&y: g[x]) {
		if(yx[y] == -1) {
			yx[y] = x;
			return true;
		}
	}
	for(auto &&y: g[x]) {
		if(yx[y] != -1 && (gused[yx[y]] != u) && dfs(yx[y]) == true) {
			yx[y] = x;
			return true;
		}
	}
	return false;
}

void solve() {
	static int cs = 0;
	printf("Case #%d:", ++cs);

	int n ;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &a[i][j]);

	int L=0;
	for(int i=1;i<=n;i++) {
		++u;
		for(int j=1;j<=n;j++) {
			if(used[a[i][j]+N] != u) {
				used[a[i][j]+N] = u;
				uid[a[i][j]+N] = ++L;
			}
			lid[i][j] = uid[a[i][j]+N];
		}
	}
	int R=0;
	for(int j=1;j<=n;j++) {
		++u;
		for(int i=1;i<=n;i++) {
			if(used[a[i][j]+N] != u) {
				used[a[i][j]+N] = u;
				uid[a[i][j]+N] = ++R;
			}
			rid[i][j] = uid[a[i][j]+N];
		}
	}
	

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			g[lid[i][j]].push_back(rid[i][j]);
		}

	for(int i=1;i<=R;i++) yx[i] = -1;
	int ok = 0;
	for(int i=1;i<=L;i++) {
		++u;
		if(dfs(i)) {
			++ok;
		}
	}
	printf(" %d\n", n*n-ok);
	
	// clear
	for(int i=1;i<=L;i++) g[i] = vector<int>();
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
