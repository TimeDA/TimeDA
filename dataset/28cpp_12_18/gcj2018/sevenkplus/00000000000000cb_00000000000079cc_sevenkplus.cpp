#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

void rot(db &x, db &y, db t) {
	db x1 = x*cos(t)-y*sin(t);
	db y1 = y*cos(t)+x*sin(t);
	x = x1;
	y = y1;
}

void ff(db x, db y, db z, db t, db r) {
	rot(x, z, t);
	rot(y, z, r);
	printf ("%.9lf %.9lf %.9lf\n", x, z, y);
}

int main() {
	int _;
	cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		db A;
		cin >> A;
		db t, r;
		if (A <= sqrt(2)) {
			db le = 0, ri = M_PI/4;
			for (int i = 200; i--;) {
				db mi = (le+ri)/2;
				if (cos(mi) + sin(mi) < A) le = mi;
				else ri = mi;
			}
			t = (le+ri)/2;
			r = 0;
		} else {
			db le = 0, ri = acos(1/sqrt(3));
			for (int i = 200; i--;) {
				db mi = (le+ri)/2;
				if (sqrt(2)*cos(mi)+sin(mi) < A) le = mi;
				else ri = mi;
			}
			t = M_PI/4;
			r = (le+ri)/2;
		}
		printf ("Case #%d:\n", __);
		ff(0.5, 0, 0, t, r);
		ff(0, 0.5, 0, t, r);
		ff(0, 0, 0.5, t, r);
	}
	return 0;
}