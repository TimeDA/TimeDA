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

int R, C, H, V;
char a[105][105]={};

void solve() {

	static int cs=0;
	printf("Case #%d: ", ++cs);

	int rows[105]={};
	int cols[105]={};
	scanf("%d%d%d%d", &R, &C, &H, &V);
	for(int i=0;i<R;i++) scanf("%s", a[i]);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			if(a[i][j]=='@') {
				++rows[i];
				++cols[j];
			}

	for(int i=1;i<R;i++) rows[i] +=rows[i-1];
	for(int i=1;i<C;i++) cols[i] += cols[i-1];

	if (rows[R-1] == 0) {
		puts("POSSIBLE");
		return;
	}

	if(rows[R-1]%(H+1) || cols[C-1]%(V+1)) {
		puts("IMPOSSIBLE");
		return ;
	}
	vector<int> splitH(R), splitV(C);
	int SH = rows[R-1] / (H+1);
	int SV = cols[C-1] / (V+1);
	int nowH = SH, gi = 0;
	int nowV = SV, gj = 0;
	
	for(int i=0;i<R;i++) {
		splitH[i] = gi;
		if(rows[i]%(H+1)==0 && rows[i] == nowH) {
			nowH += SH;
			++gi;
		}
	}
	for(int i=0;i<C;i++) {
		splitV[i] = gj;
		if(cols[i]%(V+1)==0 && cols[i] == nowV) {
			nowV += SV;
			++gj;
		}
	}
	if (nowH <= rows[R-1] || nowV <= cols[C-1]) {
		puts("IMPOSSIBLE");
		return ;
	}
	int gp[105][105]={};
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++) {
			gp[splitH[i]][splitV[j]] += (a[i][j]=='@');
		}
	for(int i=0;i<=H;i++)
		for(int j=0;j<=V;j++)
			if(gp[i][j] != gp[0][0]) {
				puts("IMPOSSIBLE");
				return ;
			}
	puts("POSSIBLE");
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
