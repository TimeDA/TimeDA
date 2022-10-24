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

string s[50];

int find1(string s1) {
	rep(i, n) rep(j, m - sz(s1) + 1)
		if (s[i].substr(j, sz(s1)) == s1)
			re 1;
	re 0;
}

int find2(string s1, string s2) {
	rep(i, n - 1) rep(j, m - sz(s1) + 1)
		if (s[i].substr(j, sz(s1)) == s1)
			if (s[i + 1].substr(j, sz(s1)) == s2)
				re 1;
	re 0;
}

pair<string, string> get(int mask) {
	string s1, s2;
	if (mask & 1)
		s1 = "W";
	else
		s1 = "B";
	if (mask & 2)
		s1 += "W";
	else
		s1 += "B";
	if (mask & 4)
		s2 = "W";
	else
		s2 = "B";
	if (mask & 8)
		s2 += "W";
	else
		s2 += "B";
	re mp(s1, s2);
}

int check(int mask) {
	string s1 = get(mask).fi;
	string s2 = get(mask).se;
	if (s1[0] == s1[1] && s2[0] == s2[1]) {
		s1 = s1.substr(1);
		s2 = s2.substr(1);
	}

	if (s1 == s2)
		re find1(s1);
	else
		re find2(s1, s2);
}

int a[50][50];
int w[30][30];

int g;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void go(int x, int y) {
	w[x][y] = 1;
	g++;
	rep(i, 4) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !w[nx][ny]) {
			if (a[nx][ny])
				go(nx, ny);
		}
	}
}

int getans(vs &v) {
	rep(i, n) rep(j, m)
		a[i][j] = v[i][j] == s[i][j];

	int ans = 0;
	fill(w, 0);
	rep(i, n) rep(j, m) {
		if (!w[i][j] && a[i][j]) {
			g = 0;
			go(i, j);
			ans = max(ans, g);
		}
	}

	if (0)
	if (ans == 5)
	{
		for (string s : v)
			cout << s << endl;
		cout << endl;
		/*
		rep(i, n) {
			rep(j, m)
				cout << w[i][j];
			cout << endl;
		}
		cout << endl;*/
	}

	re ans;
}

int getans(int mask) {
	string s[2];
	s[0] = get(mask).fi;
	s[1] = get(mask).se;

	int ans = 0;
	rep(i, n + 1) rep(j, m + 1) {
		vs v;
		rep(x, n) {
			string ss;
			rep(y, m) {
				ss += s[x >= i][y >= j];
			}
			v.pb(ss);
		}
		ans = max(ans, getans(v));
	}
	re ans;
}

void solve() {

	cin >> n >> m;
	rep(i, n)
		cin >> s[i];

	ans = 0;
	rep(i, 16)
	if (check(i))
	{
		//cout << check(i) << ' ' << get(i).fi << ' ' << get(i).se << ' ' << getans(i) << endl;
		ans = max((int)ans, getans(i));
	}

	cout << ans << endl;
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









