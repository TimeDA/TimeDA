#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int least[1024];
map<int, int> conv;
#define maxn 1020
int N, L;

vector<int> gao(vector<int>& r, int x) {
	vector<int> res = r;
	int offset = 0;
	offset = conv[x];
	for (int i = maxn - 1; i >= 0; i--) {
		if (r[i] <= N)
			for (int j = offset; j <= 100; j++) {
				if (i + j - offset >= maxn) break;
				res[i + j - offset] = min(res[i + j - offset], res[i] + least[j] - x);
			}
	}
	return res;
}

void output(vector<int>& r) {
	cout<<"output====="<<endl;
	REP(i, maxn)
		if (r[i] <= N)
			cout<<i<<' '<<r[i]<<endl;
}

int main() {
	int caseN; cin>>caseN;
	REP(_i, caseN) {
		cin>>N>>L;
		memset(least, 0x3f, sizeof least);
		conv.clear();
		REP(x, N + 1) {
			int d = x * 100.0 / N;
			int r;
			for (r = d + 10; r >= d - 10; r--) {
				if (200 * x >= (2 * r - 1) * N)
					break;
			}
			least[r] = min(least[r], x);
			conv[x] = r;
		}
		vector<int> m(maxn, N + 1);
		m[0] = 0;
		int sum = 0, tot = 0;;
		REP(i, L) {
			int x; cin>>x;
			sum += x;
			tot += conv[x];
			m = gao(m, x);
		}
		REP (_i, N - sum) {
			auto m2 = gao(m, 0);
			if (m == m2) break;
			else m = m2;
		}
		int b = 0;
		REP(i, maxn)
			if (m[i] <= N - sum) {
				b = i;
			}
		printf("Case #%d: %d\n", _i + 1, b + tot);
	}
    return 0;
}
