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

#define N 10010
int n, px[N], py[N];

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> px[i] >> py[i];
		sort(px, px+n);
		sort(py, py+n);
		int S = max((px[n-1]-px[0]+1)/2, (py[n-1]-py[0]+1)/2);
		printf ("Case #%d: %d\n", __, S);
	}
	return 0;
}
