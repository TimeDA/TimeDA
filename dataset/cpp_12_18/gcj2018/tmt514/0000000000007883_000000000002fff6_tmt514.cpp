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

const int N = 1005;
LL M[N], S[N], P[N];
LL a[N];

void solve() {
	int R, B, C;
	scanf("%d%d%d", &R, &B, &C);
	for(int i=0;i<C;i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		M[i] = x;
		S[i] = y;
		P[i] = z;
	}
	long long l=0, r=(1ll<<62), ans=r;
	while (l <= r) {
		long long m = (l+r)/2;
		for(int i=0;i<C;i++) {
			if(m < P[i]) {
				a[i] = 0;
			} else {
				a[i] = min(M[i], (m-P[i])/S[i]);
			}
		}
		sort(a, a+C);
		LL sum=0;
		for(int i=0;i<R;i++) {
			sum += a[C-1-i];
		}
		if(sum >= B) {
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	static int cs = 0;
	printf("Case #%d: ", ++cs);
	printf("%lld\n", ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
