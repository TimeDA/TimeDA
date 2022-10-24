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

ll n;
ll k;
ll m[1050], s[1050], p[1050];
ll a;

int check(ll c) {
	vll v;
	rep(i, n) {
		if (c >= p[i]) {
			ll k = (c - p[i]) / s[i];
			k = min(k, m[i]);
			v.pb(k);
		}
	}
	sort(all(v));
	reverse(all(v));
	ll sum = 0;
	rep(i, sz(v))
	if (i < a)
		sum += v[i];
	re sum >= k;
}

void solve() {
	cin >> a >> k >> n;
	rep(i, n)
		cin >> m[i] >> s[i] >> p[i];

	ll l = 0, r = 3e18, ans = r;
	while (l <= r) {
		ll c = (l + r) / 2;
		if (check(c)) {
			ans = c;
			r = c - 1;
		}
		else
			l = c + 1;
	}
	cout << ans << endl;
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









