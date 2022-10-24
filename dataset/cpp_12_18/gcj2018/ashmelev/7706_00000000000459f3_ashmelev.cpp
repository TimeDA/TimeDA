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

int table[35][505][505];
int s2[505];

int getans(int k, int a, int b) {
	if (k > a)
		re 0;

	int &ans = table[k][a][b];
	if (ans != -1)
		re ans;

	ans = 0;
	for (int t = 1; t * k <= a; t++) {
		if (s2[t] > b)
			break;
		ans = max(ans, t + getans(k + 1, a - t * k, b - s2[t]));
	}

	re ans;
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << getans(0, a, b) - 1 << endl;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	fill(table, -1);

	for (int i = 1; i <= 500; i++)
		s2[i] = i * (i - 1) / 2;

	int tc = 1;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";
		solve();
	}
}









