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

void solve() {
	static int cs=0;
	printf("Case #%d: ", ++cs);

	double t=0;
	int n, d;
	scanf("%d", &d);
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int k, s;
		scanf("%d%d", &k, &s);
		t = max(t, (d-k)*1.0/s);
	}
	printf("%.9f\n", d/t);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
