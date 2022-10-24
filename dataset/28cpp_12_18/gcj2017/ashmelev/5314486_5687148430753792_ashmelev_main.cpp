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
 typedef double D;
 typedef long double LD;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 typedef vector<ll> vll;
 
 template<class T> T abs(T x) { return x > 0 ? x : -x;}
 
 int m;
 int n;
 ll ans;
 
 int nint() {
 	int x;
 	scanf("%d", &x);
 	re x;
 }
 
 int k;
 
 int c1[1050], c2[1050];
 
 int check(int c) {
 	int cur = 0;
 	rep(i, n) {
 		cur += c;
 		cur -= c1[i];
 		if (cur < 0)
 			re 0;
 	}
 	re 1;
 }
 
 void solve() {
 
 	cin >> n >> k >> m;
 
 	fill(c1, 0);
 	fill(c2, 0);
 
 	rep(i, m) {
 		int x, y;
 		cin >> x >> y;
 		x--;
 		y--;
 		c2[y]++;
 		c1[x]++;
 	}
 
 	int ans = 0;
 	rep(i, k)
 		ans = max(ans, c2[i]);
 
 	int l = ans, r = 1000;
 	ans = r;
 
 	while (l <= r) {
 		int c = (l + r) / 2;
 		if (check(c)) {
 			ans = c;
 			r = c - 1;
 		}
 		else
 			l = c + 1;
 	}
 
 	cout << ans << ' ';
 
 	int d = 0;
 	rep(i, n)
 		d += max(0, c1[i] - ans);
 
 	cout << d << endl;
 }
 
 int main() {
 
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #else
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 #endif
 
 	int tc = 1;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 		solve();
 	}
 
 
 	re 0;
 }
