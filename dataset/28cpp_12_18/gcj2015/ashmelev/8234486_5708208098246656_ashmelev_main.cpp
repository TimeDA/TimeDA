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
 
 string s[1000];
 
 int dx[4] = {1, 0, -1, 0};
 int dy[4] = {0, 1, 0, -1};
 
 int good(int x, int y) {
 	re x >= 0 && x < n && y >= 0 && y < m;
 }
 
 int getval(char c) {
 	if (c == 'v')
 		re 0;
 	if (c == '>')
 		re 1;
 	if (c == '^')
 		re 2;
 	re 3;
 }
 
 int getmask(int x, int y) {
 	int ans = 0;
 	rep(o, 4) {
 		int cx = x + dx[o];
 		int cy = y + dy[o];
 		int f = 0;
 		while (good(cx, cy)) {
 			if (s[cx][cy] != '.')
 				f = 1;
 			cx += dx[o];
 			cy += dy[o];
 		}
 		if (f)
 			ans += (1 << o);
 	}
 	re ans;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 
 		cin >> n >> m;
 		rep(i, n) {
 			cin >> s[i];
 		}
 
 		int ans = 0;
 		int f = 0;
 		rep(i, n) rep(j, m)
 		if (s[i][j] != '.') {
 			int o = getmask(i, j);
 			if (o == 0) {
 				f = 1;
 			}
 			int u = getval(s[i][j]);
 			if ((o & (1 << u)) == 0)
 				ans++;
 		}
 
 		if (f)
 			cout << "IMPOSSIBLE" << endl;
 		else
 			cout << ans << endl;
 	}
 
 	re 0;
 }
