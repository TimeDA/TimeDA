#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	int __i; cin>>__i;
	REP(_i, __i) {
		int D, N; cin>>D>>N;
		double TT = 0;
		REP(i, N) {
			double K, S;
			cin>>K>>S;
			double T = (D - K) / S;
			if (T >= 0) TT = max(TT, T);
		}
		double rst = D / TT;
		printf("Case #%d: %.10lf\n", _i + 1, rst);
	}
    return 0;
}