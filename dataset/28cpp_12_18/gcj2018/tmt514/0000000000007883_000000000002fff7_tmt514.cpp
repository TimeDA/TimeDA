// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;
typedef long double Double;
int N;
const int Z = 25500*4;
Double maxStretch[Z];
int ok[Z];
int P;
void solve() {
	int curMaxSum = 0;
	cin	>> N >> P;
	for(int i=0;i<Z;i++) maxStretch[i] = 0;
	for(int i=0;i<Z;i++) ok[i] = 0;
	ok[0] = 1;
	Double allSum=0;
	for(int i=0;i<N;i++) {
		int W, H;
		cin >> W >> H;
		P -= (W+H)*2;
		allSum += (W+H)*2;
		int minWH = min(W, H);
		Double v = sqrtl(W*W+H*H) - minWH;
		for(int i=curMaxSum;i>=0;i--) {
			if(ok[i]) {
				ok[i+2*minWH] = 1;
				maxStretch[i+2*minWH] = max(maxStretch[i+2*minWH], maxStretch[i] + 2*v);
			}
		}
		curMaxSum += minWH*2;
	}
	Double ans = 0;
	for(int i=0;i<Z;i++) {
		if(i <= P && ok[i]) ans = max(ans, min((Double) P, i + maxStretch[i]));
	}
	static int cs = 1;
	cout << "Case #" << cs << ": ";
	++cs;
	cout << fixed << setprecision(9) << ans + allSum << endl;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
  return 0;
}
