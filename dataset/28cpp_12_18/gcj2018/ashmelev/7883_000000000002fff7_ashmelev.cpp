#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]
#define next next239
#define prev prev239

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

template<class T> string toString(T x) {
	stringstream sout;
	sout << x;
	re sout.str();
}

int nint() {
	int x;
	scanf("%d", &x);
	re x;
}

const ll mod = 1000000000 + 7;

int m;
int n;
ll ans;
ll p;
ll p0;
double p1;

void check(vector<pair<int, double>> &v) {
	int mi = 0;
	double ma = 0;
	rep(i, sz(v)) {
		mi += v[i].fi;
		ma += v[i].se;
	}
	if (mi + p0 <= p) {
		p1 = max(p1, min((double)p, p0 + ma));
	}
}

void solve() {
	vector<pair<int, double>> v;
	cin >> n >> p;
	p0 = 0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		p0 += 2 * (a + b);
		if (a > b)
			swap(a, b);
		v.pb(mp(2 * a, 2 * sqrt(a * a + b * b)));
	}
	p1 = p0;
	sort(all(v));
	rep(i, sz(v)) {
		vector<pair<int, double>> v1;
		v1.pb(v[i]);
		check(v1);
		rep(j, i) {
			v1.pb(v[j]);
			check(v1);
		}
	}

	rep(i, sz(v)) rep(j, i) {
		vector<pair<int, double>> v1;
		v1.pb(v[i]);
		v1.pb(v[j]);
		check(v1);
		rep(k, j) {
			v1.pb(v[k]);
			check(v1);
		}
	}

	printf("%.7lf\n", p1);
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		solve();
	}
}









