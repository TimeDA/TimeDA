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

struct P3 {
	ll x, y, z;
	P3 () {}
	P3 (ll _x, ll _y, ll _z):x(_x), y(_y), z(_z) {}
	P3 operator + (const P3&a) {
		return P3(x+a.x, y+a.y, z+a.z);
	}
	P3 operator - (const P3&a) {
		return P3(x-a.x, y-a.y, z-a.z);
	}
	ll dot (const P3&a) const {
		return x*a.x+y*a.y+z*a.z;
	}
	P3 crs (const P3&a) const {
		return P3(y*a.z - z*a.y, z*a.x - x*a.z, x*a.y - y*a.x);
	}
	void get() {cin >> x >> y >> z;}
	void out() {cout << x << " " << y << " " << z << endl;}
};


ll vol(P3 x, P3 y, P3 z) {
  return x.dot(y.crs(z));
}

ll vol(P3 x, P3 y, P3 z, P3 w) {
  return vol(w-x, w-y, w-z);
}

ll crs2(P3 x, P3 y, P3 z) {
	return (x.x*y.y+y.x*z.y+z.x*x.y)-(x.y*y.x+y.y*z.x+z.y*x.x);
}

bool inside(P3 x, P3 y, P3 z, P3 w) {
	return abs(crs2(x, y, z)) == abs(crs2(w, y, z)) + abs(crs2(x, w, z)) + abs(crs2(x, y, w));
}

bool above(P3 x, P3 y, P3 z, P3 w) {
	//if (!inside(x, y, z, w)) return true;
	if (crs2(x, y, z) < 0) swap(x, y);
	return vol(x, y, z, w) < 0;
}

#define N 100010
int n;
P3 a[N];
int p[N];

bool chk() {
	for (int i = 3; i < n; i++)
		for (int j = 0; j < i-2; j ++)
			if (!above(a[p[i]], a[p[i-1]], a[p[i-2]], a[p[j]])) return false;
	return true;
}

int main() {
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> n;
		for (int i = 0; i < n; i ++) a[i].get();
		for (int i = 0; i < n; i ++) p[i] = i;
		do {
			if (chk()) break;
		} while (next_permutation(p, p+n));
		printf ("Case #%d: ", __);
		for (int i = 0; i < n; i ++)
			printf ("%d%c", p[i]+1, i == n-1?'\n':' ');
	}
	return 0;
}
