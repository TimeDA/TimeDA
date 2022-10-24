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
		map<int, int> M;
		REP(_i, N) {
			int D; cin>>D;
			vector<pii> V; 
			REP(i, D) {
				int x; cin>>x;
				if (M[x] != -1) {
					V.push_back(make_pair((M[x] + 1) * 1024 + (rand() % 1024), x));
					M[x]++;
				}
			}
			sort(V.begin(), V.end());
			if (V.size()) {
				int choice = V[0].second;
				cout<<choice<<endl;
				M[choice] = -1;
			} else cout<<-1<<endl;
		}
	}
    return 0;
}