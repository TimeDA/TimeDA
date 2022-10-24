#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int r, b, c;
ll cm[1010];
ll cs[1010];
ll cp[1010];

ll can (ll h) {
	vector<ll> now;
	for (int i = 0; i < c; i++)
		if (cp[i] < h)
			now.pb (min ((h - cp[i]) / cs[i], cm[i]));
	sort (all (now));
	reverse (all (now));
	ll cur = 0;
	for (int i = 0; i < r && i < sz (now); i++) cur += now[i];
//	cout << h << " " << cur << endl;
	re cur;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> r >> b >> c;
		for (int i = 0; i < c; i++) cin >> cm[i] >> cs[i] >> cp[i];
		ll l = 0, r = 4e18;
		while (r - l > 1) {
			ll s = (l + r) / 2;
			if (can (s) >= b) r = s; else l = s;
		}
		cout.precision (20);
		cout << "Case #" << it << ": " << r;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}