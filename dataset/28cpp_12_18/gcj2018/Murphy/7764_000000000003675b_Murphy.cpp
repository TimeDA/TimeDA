#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
	int caseN; cin>>caseN;
	REP(_i, caseN) {
		int N; cin>>N;
		int D[128], A[128], B[128];
		REP(i, N) cin>>D[i]>>A[i]>>B[i];
		REP(i, N) {
			A[i] += D[i];
			B[i] -= D[i];
		}
		int b = 1, cnt = N;
		REP(j, N)
			REP(i, j)
				if (j - i + 1 >= b) {
					int okk = 0;
					for (int u = i; u <= j; u++) {
						int set = -10000000;
						int ok = 1;
						for (int v = i; v <= j; v++) {
							if (A[v] != A[u]) {
								if (set == -10000000) set = B[v];
								else if (B[v] != set) {
									ok = 0;
									goto next;
								}
							}
						}
						next:;
						if (ok) {
							okk = 1;
							break;
						}
					}
					if (okk) {
						if (j - i + 1 > b) {
							b = j - i + 1;
							cnt = 1;
						} else {
							cnt++;
						}
					}
				}
		printf("Case #%d: %d %d\n", _i + 1, b, cnt);
	}
    return 0;
}
