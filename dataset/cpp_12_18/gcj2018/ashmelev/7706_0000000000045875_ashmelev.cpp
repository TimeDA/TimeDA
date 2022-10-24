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

int n;
ll ans;

int a[150][150];
int m[150][150];
int t;
int was[150];
int p[150];

int go(int x) {
	was[x] = t;
	rep(i, n) {
		if (m[x][i])
		if (p[i] == -1) {
			p[i] = x;
			re 1;
		}
	}

	rep(i, n) {
		if (m[x][i])
		if (was[p[i]] != t && go(p[i])) {
			p[i] = x;
			re 1;
		}
	}

	re 0;
}

int get1(int c) {
	rep(i, n) rep(j, n)
		m[i][j] = a[i][j] == c;

	int ans = 0;
	fill(p, -1);
	rep(i, n) {
		t++;
		ans += go(i);
	}
	re ans;
}

void solve() {

	cin >> n;
	rep(i, n) rep(j, n) {
		int x;
		cin >> x;
		if (x < 0) {
			x *= -1;
			x--;
			x += n;
		}
		else {
			x--;
		}
		a[i][j] = x;
	}

	if (0)
	rep(i, n) {
		rep(j, n)
			cout << a[i][j] << ' ';
		cout << endl;
	}

	ans = 0;
	rep(i, 2 * n)
		ans += get1(i);

	cout << n * n - ans << endl;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	int tc = 1;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";
		solve();
	}
}









