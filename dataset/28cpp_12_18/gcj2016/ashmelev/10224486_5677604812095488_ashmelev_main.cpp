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
 
 int m;
 int n;
 int ans;
 
 double table[250][250][250];
 int was[250][250][250];
 double pp[250];
 
 double getans(int p, int k, int s) {
 	if (s < 0)
 		re 0;
 	if (p == n)
 		re s == 0;
 
 	double &ans = table[p][k][s];
 	if (was[p][k][s])
 		re ans;
 	was[p][k][s] = 1;
 
 	double t1 = getans(p + 1, k, s - 1) * pp[p];
 	double t2 = getans(p + 1, k, s) * (1 - pp[p]);
 	ans = t1 + t2;
 	//cout << p << ' ' << k << ' ' << s << ' ' << ans << endl;
 	re ans;
 }
 
 double getans(int mask) {
 	int sn = n;
 	double spp[250];
 	rep(i, n)
 		spp[i] = pp[i];
 
 	n = 0;
 	rep(i, sn)
 	if (mask & (1 << i)) {
 		pp[n] = spp[i];
 		n++;
 	}
 
 	rep(i, n) rep(j, 2) rep(k, n)
 		was[i][j][k] = 0;
 
 	double ans = getans(0, 0, n / 2);
 	n = sn;
 	rep(i, n)
 		pp[i] = spp[i];
 	re ans;
 }
 
 int main() {
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #else
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 		cin >> n >> m;
 		rep(i, n)
 			cin >> pp[i];
 		double ans = 0;
 		rep(i, (1 << n))
 		if (__builtin_popcount(i) == m) {
 			ans = max(ans, getans(i));
 		}
 		printf("%.10lf", ans);
 		cout << endl;
 	}
 
 
 	re 0;
 }
 
 
 
 
 
 
 
 
 
 
