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
 
 int check(int d, string s, int p) {
 	for (; p < sz(s); p++) {
 		if (s[p] > d + '0')
 			re 1;
 		if (s[p] < d + '0')
 			re 0;
 	}
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
 
 
 		string s;
 		cin >> s;
 		int ans = -1;
 		for (int d = 9; d >= 1; d--) {
 			if (check(d, s, 0)) {
 				ans = d;
 				break;
 			}
 		}
 		if (ans == -1) {
 			rep(i, sz(s) - 1)
 				cout << 9;
 			cout << endl;
 			continue;
 		}
 
 		int f = 0;
 		int prev = ans;
 		rep(i, sz(s)) {
 			if (f) {
 				cout << 9;
 				continue;
 			}
 			for (int d = 9; d >= prev; d--) {
 				if (check(d, s, i)) {
 					cout << d;
 					prev = d;
 					break;
 				}
 			}
 			if (prev < s[i] - '0')
 				f = 1;
 		}
 		cout << endl;
 	}
 
 	re 0;
 }
 
 
 
 
 
 
 
 
 
 
