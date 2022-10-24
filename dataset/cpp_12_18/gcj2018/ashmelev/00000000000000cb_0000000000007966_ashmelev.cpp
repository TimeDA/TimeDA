#include <iostream>
#include <cstdio>
#include <cstdlib>
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
#include <cassert>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
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
#define ba back()
#define last(x) x[sz(x) - 1]
#define deb(x) cout << #x << " = " << (x) << endl
#define deba(x) do { cout << #x << " (size: " << sz(x) << ") = " << \
	"{"; for (auto o : x) cout << o << ","; cout << "}" << endl;} while (0)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef long double LD;
typedef double D;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

template<class T> T toString(T x) {
	ostringstream sout;
	sout << x;
	return sout.str();
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

ll d;

int check(string s) {
	ll c = 1, sum = 0;
	rrep(i, sz(s)) {
		if (s[i] == 'C') {
			c *= 2;
			if (c > d)
				c = d + 1;
		}
		else
			sum += c;
	}
	re sum <= d;
}

int update(string &s) {
	rep(i, sz(s) - 1) {
		if (s[i] == 'S' && s[i + 1] == 'C') {
			swap(s[i], s[i + 1]);
			re 1;
		}
	}
	re 0;
}

void solve() {
	string s;
	cin >> d >> s;
	reverse(all(s));
	int ans = 0;
	while (1) {
		if (check(s)) {
			cout << ans << endl;
			re;
		}
		if (!update(s)) {
			cout << "IMPOSSIBLE" << endl;
			re;
		}
		ans++;
	}
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand((int)time(0));
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif


	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		solve();
	}


}







