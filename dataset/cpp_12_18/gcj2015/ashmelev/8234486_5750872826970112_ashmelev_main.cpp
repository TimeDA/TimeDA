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
 #define prev prev239
 #define next next239
 #define hash hash239
 #define rank rank239
 #define sqrt(x) sqrt(abs(x))
 #define unq(x) (x.resize(unique(all(x)) - x.begin()))
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef long long ll;
 typedef double D;
 typedef long double LD;
 typedef pair<ll, ll> pll;
 
 template<class T> T abs(T x) {
 	return x > 0 ? x : -x;
 }
 
 int m;
 int n;
 
 ll x[100];
 ll r[100];
 
 ll get() {
 	double o;
 	cin >> o;
 	re (ll) (o * 10000 + .5);
 }
 
 ll cv;
 ll cx;
 
 double getans() {
 	rep(i, n)
 	for (int j = i + 1; j < n; j++)
 		if (x[j] < x[i]) {
 			swap(x[j], x[i]);
 			swap(r[j], r[i]);
 		}
 
 	if (n == 1)
 		re cv / (double) r[0];
 
 	if (n == 2) {
 		if (x[0] == x[1])
 			re cv / (double) (r[0] + r[1]);
 		if (x[0] == cx)
 			re cv / (double) r[0];
 		if (x[1] == cx)
 			re cv / (double) r[1];
 
 		double d = (cx - x[0]) / (double) (x[1] - cx);
 		double v0 = cv / (d + 1);
 		double v1 = cv / (d + 1) * d;
 
 		re max(v0 / r[0], v1 / r[1]);
 	}
 	re 0;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 
 		cin >> n;
 		cv = get();
 		cx = get();
 
 		rep(i, n) {
 			r[i] = get();
 			x[i] = get();
 		}
 
 		int f1 = 0, f2 = 0;
 		rep(i, n) {
 			if (x[i] >= cx)
 				f1 = 1;
 			if (x[i] <= cx)
 				f2 = 1;
 		}
 
 		if (!f1 || !f2) {
 			cout << "IMPOSSIBLE" << endl;
 			continue;
 		}
 
 		double ans = getans();
 		printf("%.8lf", ans);
 		cout << endl;
 	}
 
 	re 0;
 }
