// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

char z[105][105]={};

void solve() {
	static int cs = 0;
	printf("Case #%d: ", ++cs);
	
	int n, a[105]={};
	int cur[105][105]={};
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	
	if (a[0] == 0 || a[n-1] == 0) {
		puts("IMPOSSIBLE");
		return ;
	}

	memset(cur, 0, sizeof(cur));
	int m = 0;
	for(int i=0;i<n;i++) cur[0][i] = 1;
	bool change = true;
	while(change) {
		int tl = 0;
		int tr = 0;

		/*
		for(int i=0;i<n;i++) printf("%d ", cur[i]); puts("");
		for(int i=0;i<n;i++) printf("%d ", a[i]); puts("");
		puts("==");*/
		change = false;
		
		tl = a[0];
		tr = cur[m][0];
		cur[m+1][0] = cur[m][0];
		cur[m+1][n-1] = cur[m][n-1];


		for(int i=1;i<n-1;i++) {
			if (cur[m][i] && tr + cur[m][i] <= tl) {
				tr += cur[m][i];
				z[m][i] = '/';
				cur[m+1][i-1] += cur[m][i];
				change = true;
			} else if (cur[m][i] && tr >= tl + a[i]) {
				tr += cur[m][i];
				z[m][i] = '\\';
				cur[m+1][i+1] += cur[m][i];
				change = true;
			} else if (tr + cur[m][i] <= tl + a[i]) {
				tr += cur[m][i];
				cur[m+1][i] += cur[m][i];
				z[m][i] = '.';
			} else {
				assert(false);
			}

			tl += a[i];
		}
		z[m][0] = z[m][n-1] = '.';

		z[m][n] = 0;
		m++;
	}
	printf("%d\n", m);
	for(int i=0;i<m;i++) {
		puts(z[i]);
	}
	

}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
