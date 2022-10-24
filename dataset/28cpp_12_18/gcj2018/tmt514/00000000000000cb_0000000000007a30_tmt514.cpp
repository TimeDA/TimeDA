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

int r[1005][1005];
int f[1005][1005];
#include <cassert>

void solve() {
	int a;
	scanf("%d", &a);
	int p=3;
	while(p*p<a) p++;
	memset(r, 0, sizeof(r));
	memset(f, 0, sizeof(f));
	int t = 0;
	while(true) {
		assert(t<=1000);
		++t;
		int minValue = 10;
		int mi = 2;
		int mj = 2;
		for(int i=2;i<p;i++)
			for(int j=2;j<p;j++) {
				if(r[i][j] < minValue) {
					minValue = r[i][j];
					mi = i;
					mj = j;
				}
			}
		printf("%d %d\n", mi, mj);
		fflush(stdout);
		scanf("%d%d", &mi, &mj);
		if(mi==0 && mj==0) break;
		if(f[mi][mj] == 0) {
			f[mi][mj] = 1;
			for(int i=-1;i<=1;i++)
				for(int j=-1;j<=1;j++)
					r[mi+i][mj+j]++;
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
