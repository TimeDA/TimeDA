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

string s[150];

int ss[150][150];

void solve() {

	int h, v;
	cin >> n >> m >> h >> v;

	rep(i, n)
		cin >> s[i];

	int a = 0;
	rep(i, n) rep(j, m)
		a += s[i][j] == '@';

	if (a % ((h + 1) * (v + 1))) {
		cout << "IMPOSSIBLE" << endl;
		re;
	}

	int sum = 0;
	vi v1, v2;

	rep(i, n) {
		sum += count(all(s[i]), '@');
		if (sum == a / (h + 1)) {
			v1.pb(i);
			sum = 0;
		}

		if (sum > a / (h + 1)) {
			cout << "IMPOSSIBLE" << endl;
			re;
		}
	}

	rep(i, m) {
		rep(j, n)
			sum += s[j][i] == '@';
		if (sum == a / (v + 1)) {
			v2.pb(i);
			sum = 0;
		}
		if (sum > a / (v + 1)) {
			cout << "IMPOSSIBLE" << endl;
			re;
		}
	}

	fill(ss, 0);

	rep(i, n) rep(j, m) {
		int a = lower_bound(all(v1), i) - v1.begin();
		int b = lower_bound(all(v2), j) - v2.begin();
		ss[a][b] += s[i][j] == '@';
	}

	rep(i, h + 1) rep(j, v + 1)
		if (ss[i][j] != a / (h + 1) / (v + 1)) {
			cout << "IMPOSSIBLE" << endl;
			re;
		}

	cout << "POSSIBLE" << endl;
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









