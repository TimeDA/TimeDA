#ifndef LOCAL_BOBER
 #pragma comment(linker, "/STACK:134217728")
 #endif
 
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
 
 int parse(int x, int *mas) {
 	int n = 0;
 	while (x) {
 		mas[n++] = x % 10;
 		x /= 10;
 	}
 	reverse(mas, mas + n);
 	re n;
 }
 
 int lol[3000000];
 int ct;
 
 int main() {
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #else
 #endif
 
 	ll st10[10];
 	st10[0] = 1;
 	for (int i = 1; i < 10; i++)
 		st10[i] = st10[i - 1] * 10;
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 		int l, r;
 		cin >> l >> r;
 		int ans = 0;
 		int mas[10];
 
 		for (int a = l; a <= r; a++) {
 			ct++;
 			n = parse(a, mas);
 
 			for (int o = 1; o < n; o++) {
 				if (mas[o] == 0)
 					continue;
 				int d1 = 0, d2 = 0;
 				rep(i, n)
 				if (i < o)
 					d1 = d1 * 10 + mas[i];
 				else
 					d2 = d2 * 10 + mas[i];
 
 				ll f = d2 * st10[o] + d1;
 				if (f > a && f <= r) {
 					if (lol[f] != ct)
 						ans++;
 					lol[f] = ct;
 				}
 			}
 		}
 
 		cout << ans << endl;
 	}
 
 
 	re 0;
 }
