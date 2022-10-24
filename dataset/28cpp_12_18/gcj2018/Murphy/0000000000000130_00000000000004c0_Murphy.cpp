#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;


int main(){
	int caseI; cin>>caseI;
	REP(_i, caseI) {
		cout<<"Case #"<<(_i+1)<<":";
		int N;
		priority_queue<pii> Q;
		cin>>N;
		REP(i, N) {
			int x; cin>>x; Q.push(make_pair(x, i));
		}
		while (1) {
			auto r = Q.top(); Q.pop();
			int c = r.first, idx = r.second;
			if (Q.size() == 1) {
				auto r2 = Q.top(); Q.pop();
				int idx2 = r2.second;
				REP(i, c) {
					cout<<' '<<(char)('A' + idx)<<(char)('A' + idx2);
				}
				break;
			} else {
				c--; cout<<' '<<(char)('A' + idx);
				if (c) Q.push(make_pair(c, idx));
			}
		}
		cout<<endl;
	}
    return 0;
}