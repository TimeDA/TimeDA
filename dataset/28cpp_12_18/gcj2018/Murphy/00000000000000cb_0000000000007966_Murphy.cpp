#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	int caseI; cin>>caseI;
	REP(caseN, caseI) {
		LL D; string S;
		int R = 0;
		cin>>D>>S;
		LL C = 0, P = 1;
		map<LL, int> cnt;
		for (char c : S) {
			if (c == 'C') {
				P *= 2;
			} else {
				C += P;
				cnt[P]++;
			}
		}
		while (C > D) {
			LL B = 0;
			for (auto it : cnt) {
				if (it.second) B = it.first;
			}
			if (B == 1) {
				printf("Case #%d: IMPOSSIBLE\n", caseN + 1);
				break;
			}
			// cerr<<B<<' '<<C<<' '<<R<<' '<<endl;
			R++;
			C -= B; cnt[B]--; 
			B /= 2;
			C += B; cnt[B]++;
		}
		if (C <= D) 
			printf("Case #%d: %d\n", caseN + 1, R);
	}
    return 0;
}