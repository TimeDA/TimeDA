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
		map<int, int> m[2];
		m[0][0] = 0;
		REP(i, N) {
			int W; cin>>W;
			m[1] = m[0];
			for (auto it : m[0]) {
				int cW = it.first, length = it.second;
				if (cW <= W * 6) {
					int nW = cW + W;
					if (m[1].count(nW)) {
						m[1][nW] = max(m[1][nW], length + 1);
					} else {
						m[1][nW] = length + 1;
					}
				}
			}
			swap(m[0], m[1]);
		}
		int best = 0;
		for (auto it : m[0]) {
			// cout<<it.first<<' '<<it.second<<endl;
			best = max(best, it.second);
		}
		printf("Case #%d: %d\n", _i + 1, best);
	}
    return 0;
}