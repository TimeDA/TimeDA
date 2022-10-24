#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1010
int ma[N], px[N], py[N];
int n, m, B; // m robots; B total

ll a[N];
bool can(ll c) {
	for (int i = 0; i < n; i ++)
		if (c >= py[i]) a[i] = min((ll)ma[i], (c-py[i])/px[i]);
		else a[i] = 0;
	sort(a, a+n);
	reverse(a, a+n);
	ll S = 0;
	for (int i = 0; i < m; i ++)
		S = min((ll)B, S+a[i]);
	return S >= B;
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> m >> B >> n;
		for (int i = 0; i < n; i ++)
			cin >> ma[i] >> px[i] >> py[i];
		ll le = 1;
		ll ri = 2000000000000000000LL;
		while (le <= ri) {
			ll mi = (le+ri)/2;
			if (can(mi)) ri = mi-1;
			else le = mi+1;
		}
		printf ("Case #%d: ", __);
		cout << le << endl;
	}
	return 0;
}
