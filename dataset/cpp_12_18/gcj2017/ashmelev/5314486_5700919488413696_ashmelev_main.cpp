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
 
 int table[110][110][110][4];
 
 int getans(int c1, int c2, int c3, int r) {
 	if (c1 + c2 + c3 == 0)
 		re 0 - (r == 0);
 	int &ans = table[c1][c2][c3][r];
 	if (ans != -1)
 		re ans;
 
 	ans = 0;
 	if (c1) {
 		int nr = (r + 1) % m;
 		ans = max(ans, getans(c1 - 1, c2, c3, nr) + (nr == 0));
 	}
 
 	if (c2) {
 		int nr = (r + 2) % m;
 		ans = max(ans, getans(c1, c2 - 1, c3, nr) + (nr == 0));
 	}
 
 	if (c3) {
 		int nr = (r + 3) % m;
 		ans = max(ans, getans(c1, c2, c3 - 1, nr) + (nr == 0));
 	}
 
 	re ans;
 }
 
 void solve() {
 
 	int c[4];
 	cin >> n >> m;
 	fill(c, 0);
 	rep(i, n) {
 		int x;
 		cin >> x;
 		c[x % m]++;
 	}
 
 	fill(table, -1);
 
 	cout << c[0] + 1 + getans(c[1], c[2], c[3], 0) << endl;
 
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
