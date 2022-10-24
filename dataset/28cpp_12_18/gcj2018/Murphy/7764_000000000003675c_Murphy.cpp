#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
	int caseN; cin>>caseN;
	REP(_i, caseN) {
		int N;
		int F[2][10];
		cin>>N;
		REP(i, N) {
			cin>>F[0][i]>>F[1][i];
			F[0][i]--; F[1][i]--;
		}
		string G(N, '0');
		unordered_set<string> V;
		queue<string> Q;
		int best = 0;
		REP(i, N) {
			int x;
			cin>>x;
			G[i] = x + '0';
		}

		V.insert(G);
		Q.push(G);
		while (!Q.empty()) {
			auto c = Q.front(); Q.pop();
			best = max(best, (int)c[0] - '0');
			// cout<<c<<endl;
			REP(i, N) {
				if (c[F[0][i]] > '0' && c[F[1][i]] > '0') {
					auto nxt = c;
					nxt[F[0][i]]--;
					nxt[F[1][i]]--;
					// assert(F[0][i] != i);
					// assert(F[1][i] != i);
					nxt[i]++;
					if (V.count(nxt) == 0) {
						V.insert(nxt);
						Q.push(nxt);
					}
				}
			}
		}
		printf("Case #%d: %d\n", _i + 1, best);
	}
    return 0;
}
