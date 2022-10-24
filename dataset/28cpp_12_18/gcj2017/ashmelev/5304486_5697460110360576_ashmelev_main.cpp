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
 typedef double D;
 typedef long double LD;
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
 
 vii v[1050];
 int r[1050];
 
 int ok;
 
 ii get(int x, int y) {
 	int rx = (x * 10) / 9;
 	int lx = (x * 10 + 10) / 11;
 
 	re {(lx + y - 1) / y, rx / y};
 }
 
 int check(int k) {
 	rep(i, n) {
 		while (sz(v[i]) && v[i].back().fi > k)
 			v[i].pop_back();
 		if (!sz(v[i])) {
 			ok = 0;
 			re 0;
 		}
 		if (v[i].back().se < k)
 			re 0;
 	}
 
 	rep(i, n)
 		v[i].pop_back();
 	re 1;
 }
 
 int main() {
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 
 	int tc = 1;
 	cin >> tc;
 	rep(tt, tc) {
 
 		cout << "Case #" << tt + 1 << ": ";
 
 		cin >> n >> m;
 		rep(i, n)
 			cin >> r[i];
 
 		rep(i, n)
 			v[i].clear();
 
 		rep(i, n) rep(j, m) {
 			int x;
 			cin >> x;
 			v[i].pb(get(x, r[i]));
 		}
 
 		rep(i, n)
 			sort(all(v[i]));
 
 		int ans = 0;
 		ok = 1;
 		for (int k = 1111000; k >= 1; k--) {
 			while (check(k)) {
 				ans++;
 			}
 			if (!ok)
 				break;
 		}
 		cout << ans << endl;
 	}
 
 	re 0;
 }
 
 
 
 
 
 
 
 
 
 
