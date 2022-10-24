#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n - 1)&n) + 1 : 0; }

int i, j, k, m, n, l;

void reachable(ll n) {
	set<ll> S;
	queue<ll> Q;
	Q.push(n);
	while (!Q.empty()) {
		ll i = Q.front(); Q.pop();
		if (S.count(i)) continue;
		S.insert(i);
		if (i > 1) {
			Q.push((i - 1) / 2);
			Q.push(i / 2);
		}
	}
}

int main() {
	int tn; cin >> tn;

	F1(tt, tn) {
		int A, B, N;
		cin >> A >> B;
		cin >> N;

		while (true) {
			int Q = (A + B + 1) / 2;
			cout << Q << endl;
			string s;
			cin >> s;
			if (s == "CORRECT") break;
			else if (s == "TOO_BIG") B = Q - 1;
			else if (s == "TOO_SMALL") A = Q;
			else break;
		}

		/*
		//cerr << tt << endl;
		printf("Case #%d: ", tt);

		ll n, k;
		cin >> n >> k;

		map<ll, ll> M;
		M[-n] = 1;

		while (1) {
			auto it = M.begin();
			ll n = -it->first;
			ll cnt = it->second;
			if (k <= cnt) {
				cout << n / 2 << " " << (n - 1) / 2 << endl;
				break;
			}
			else {
				k -= cnt;
				M.erase(it);
				M[-(n / 2)] += cnt;
				M[-((n - 1) / 2)] += cnt;
			}
		}
		*/
	}
	return 0;
}
