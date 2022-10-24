#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int X = 114, Y = 113;


int main() {
	std::ios::sync_with_stdio(false);
	int caseI; 
	cin>>caseI;
	srand(1897);
	REP(caseN, caseI) {
		int A; 
		cin>>A;
		// cerr<<A<<endl;
		set<pii> P;
		priority_queue<pair<int, pii>> locations;
		for (int i = 100 + 1; i <= X - 1; i++)
			for (int j = 100 + 1; j <= Y - 1; j++) {
				locations.push(make_pair(9, make_pair(i, j)));
			}
		while (1) {
			int i, j, ii, jj;
			auto p = locations.top();
			int _cnt = p.first;
			i = p.second.first; j = p.second.second;

			int cnt = 0;
			for (int dx = -1; dx <= 1; dx++)
				for (int dy = -1; dy <= 1; dy++) {
					if (P.count(make_pair(i + dx, j + dy)) == 0) cnt++;
				}
			// if (caseN == 1)
			// 	cerr<<_cnt<<' '<<cnt<<' '<<i<<' '<<j<<'@'<<caseN<<endl;	
			if (_cnt != cnt) {
				locations.pop();
				locations.push(make_pair(cnt, make_pair(i, j)));
			} else {
				cout<<i<<' '<<j<<endl;
				cin>>ii>>jj;
				// if (caseN == 1)
					// cerr<<'g'<<i<<' '<<j<<' '<<ii<<' '<<jj<<'@'<<caseN<<endl;
				if (ii == 0 && jj == 0) break;
				P.insert(make_pair(ii, jj));
			}
		}
	}
    return 0;
}
