#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;


int main() {
	std::ios::sync_with_stdio(false);
	int caseI; 
	cin>>caseI;
	srand(1897);
	REP(caseN, caseI) {
		int N; 
		cin>>N;
		vector<int> X(N);
		REP(i, N) cin>>X[i];


		auto Y = X;
		sort(Y.begin(), Y.end());

		vector<int> A, B;
		REP(i, N) {
			if (i & 1) B.push_back(X[i]); else A.push_back(X[i]);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		vector<int> Z;
		REP(i, N) {
			if (i & 1) Z.push_back(B[i / 2]); else Z.push_back(A[i / 2]);
		}

		int diff = -1;
		REP(i, N) {
			if (Z[i] != Y[i])
				if (diff == -1)
					diff = i;
		}
		if (diff == -1) {
			printf("Case #%d: OK\n", caseN + 1);
		} else {
			printf("Case #%d: %d\n", caseN + 1, diff);
		}
	}
    return 0;
}