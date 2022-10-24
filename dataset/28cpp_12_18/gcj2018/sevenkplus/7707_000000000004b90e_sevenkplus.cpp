#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 1010
int n;
PII a[N], b[N];
int p[N];

ll dx, dy;
bool cmpxx(PII x, PII y) {
	ll xx = x.fi*(x.se+dy)-x.se*(x.fi+dx);
	ll yy = y.fi*(y.se+dy)-y.se*(y.fi+dx);
	if (xx != yy) return xx < yy;
	// in the same direction
	return (y.fi-x.fi)*dx+(y.se-x.se)*dy > 0;
}

bool cmp(int x, int y) {
	if (!cmpxx(a[x], b[x])) swap(a[x], b[x]);
	if (!cmpxx(a[y], b[y])) swap(a[y], b[y]);
	if (b[x] != b[y]) return cmpxx(b[x], b[y]);
	return cmpxx(a[x], a[y]);
}

bool chk() {
	int p0 = 0, p1 = 0;
	for (int i = 0; i < n; i ++) {
		if (p[i] == 0) p0 = i;
		if (p[i] == 1) p1 = i;
	}
	return p0 < p1;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		int k;
		cin >> n >> k;
		for (int i = 0; i < n; i ++) {
			cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
		}
		dx = b[0].fi-a[0].fi;
		dy = b[0].se-a[0].se;
		for (int i = 0; i < n; i ++) p[i] = i;
		sort(p, p+n, cmp);
		bool F = chk();
		if (!F) {
			dx = -dx;
			dy = -dy;
			sort(p, p+n, cmp);
			F = chk();
		}
		if (!F) {
			dx = b[1].fi-a[1].fi;
			dy = b[1].se-a[1].se;
			sort(p, p+n, cmp);
			F = chk();
		}
		if (!F) {
			dx = -dx;
			dy = -dy;
			sort(p, p+n, cmp);
			F = chk();
		}
		//assert(F);
		printf ("Case #%d: ", __);
		for (int i = 0; i < n; i ++)
			printf ("%d%c", p[i]+1, i == n-1?'\n':' ');
	}
	return 0;
}
