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

char p[105][105];
int R, C;

int available[16]={};
bool pattern_exist(int mask) {
	return available[mask];
}

int getstate(string blah) {
	int v=0;
	for(int i=0;i<(int)blah.size();i++)
		v = v*2 + (blah[i] == 'B');
	return v;
}

bool allow[105][105]={};
void get_filter_pattern(int mask, int RM, int CM) {
	for(int i=0;i<=R+1;i++)
		for(int j=0;j<=C+1;j++)
			allow[i][j] = false;
	int masks[4]={};
	for(int i=0;i<4;i++) masks[i] = ((mask&(1<<i)) != 0);
	reverse(masks, masks+4);
	
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++) {
			int idx = (i>RM)*2+(j>CM);
			allow[i][j] = (masks[idx]==0? p[i][j]=='W' : p[i][j]=='B');
		}
}

int dfs(int x, int y) {
	int ret=1;
	allow[x][y] = false;
	if(allow[x+1][y]) ret += dfs(x+1, y);
	if(allow[x-1][y]) ret += dfs(x-1, y);
	if(allow[x][y+1]) ret += dfs(x, y+1);
	if(allow[x][y-1]) ret += dfs(x, y-1);
	return ret;
}
int find_largest_component() {
	int ans=0;
	for(int i=1;i<=R;i++)
		for(int j=1;j<=C;j++)
			if(allow[i][j]) {
				int v = dfs(i, j);
				ans = max(ans, v);
			}
	return ans;
}


void solve() {
	static int cs = 0;
	printf("Case #%d:", ++cs);

	memset(p, 0, sizeof(p));
	memset(available, 0, sizeof(available));

	scanf("%d%d", &R, &C);
	for(int i=1;i<=R;i++)
		scanf("%s", p[i]+1);
	
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) {
		if(p[i][j] == 'W') available[getstate("WWWW")] = 1;
		if(p[i][j] == 'B') available[getstate("BBBB")] = 1;
	}
	for(int i=1;i<=R;i++) for(int j=1;j<C;j++) {
		if(p[i][j]=='W' && p[i][j+1] == 'B') available[getstate("WBWB")] = 1;
		if(p[i][j]=='B' && p[i][j+1] == 'W') available[getstate("BWBW")] = 1;
	}
	for(int i=1;i<R;i++) for(int j=1;j<=C;j++) {
		if(p[i][j]=='W' && p[i+1][j] == 'B') available[getstate("WWBB")] = 1;
		if(p[i][j]=='B' && p[i+1][j] == 'W') available[getstate("BBWW")] = 1;
	}
	for(int i=1;i<R;i++)
		for(int j=1;j<C;j++) {
			string blah = "";
			blah += p[i][j];
			blah += p[i][j+1];
			blah += p[i+1][j];
			blah += p[i+1][j+1];
			available[getstate(blah)] = 1;
		}
	int ans = 0;
	for(int i=0;i<16;i++) if(pattern_exist(i)) {
		for(int rsplit = 1; rsplit <= R; rsplit++) {
			for(int csplit = 1; csplit <= C; csplit++) {
				get_filter_pattern(i, rsplit, csplit);
				int v = find_largest_component();
				ans = max(ans, v);
			}
		}
	}

	printf(" %d\n", ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
