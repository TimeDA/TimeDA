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
 
 int c1, c2, c3;
 int c[3];
 int gc1, gc2, gc3;
 int gc[3];
 
 string get(int x) {
 	if (x == 0)
 		re "R";
 	if (x == 1)
 		re "P";
 	re "S";
 }
 
 string go(int x, int n) {
 	if (n == 0) {
 		gc[x]++;
 		re get(x);
 	}
 
 	int nx = (x + 2) % 3;
 	string s1 = go(nx, n - 1);
 	string s2 = go(x, n - 1);
 	if (s1 > s2)
 		swap(s1, s2);
 	re s1 + s2;
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
 		cin >> n >> c1 >> c2 >> c3;
 		c[0] = c1;
 		c[1] = c2;
 		c[2] = c3;
 
 		string ans = "";
 		rep(i, 3) {
 			fill(gc, 0);
 			string s= go(i, n);
 			int ok = 1;
 			rep(i, 3)
 			if (gc[i] != c[i])
 				ok = 0;
 			if (ok)
 				if (!sz(ans) || ans > s)
 					ans = s;
 		}
 		if (!sz(ans))
 			cout << "IMPOSSIBLE" << endl;
 		else
 			cout << ans << endl;
 	}
 
 
 	re 0;
 }
 
 
 
 
 
 
 
 
 
 
