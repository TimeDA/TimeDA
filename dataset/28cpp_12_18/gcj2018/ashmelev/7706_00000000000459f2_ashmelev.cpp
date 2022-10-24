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

int c[150];
int p[150];

void solve() {

	cin >> n;
	rep(i, n)
		cin >> c[i];

	if (c[0] == 0 || c[n - 1] == 0 || accumulate(c, c + n, 0) != n) {
		cout << "IMPOSSIBLE" << endl;
		re;
	}

	fill(p, -1);
	rep(i, n) {
		rep(j, n) {
			if (c[i] > 0 && p[j] == -1) {
				p[j] =i;
				c[i]--;
			}
		}
	}

	ans = 0;
	rep(i, n)
		ans = max(ans, (ll)abs(i - p[i]));
	cout << ans + 1 << endl;
	m = ans;

	char table[150][150];
	rep(i, m) rep(j, n)
		table[i][j] = '.';

	rep(i, n) {
		int c = i;
		rep(j, m) {
			if (c < p[i]) {
				table[j][c] = '\\';
				c++;
			}
			else
			if (c > p[i]) {
				table[j][c] = '/';
				c--;
			}
			else
			if (c == p[i]) {
				table[j][c] = '.';
			}
		}
	}
	rep(i, m) {
		rep(j, n)
			cout << table[i][j];
		cout << endl;
	}

	rep(i, n)
		cout << '.';
	cout << endl;
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









