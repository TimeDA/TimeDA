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
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef long double LD;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 typedef vector<ll> vll;
 
 template<class T> T abs(T x) { return x > 0 ? x : -x;}
 
 map<ii, int> m;
 int n;
 
 int g;
 
 queue<ii> q;
 int d[15000], l[15000];
 int D;
 
 void parse(ii o) {
 	int p = o.fi;
 	int x = o.se;
 
 
 	if (g)
 		re;
 
 	int len = d[p] - x;
 	//cout << p << ' ' << x << ' ' << len << endl;
 	if (x + 2 * len >= D) {
 		g = 1;
 		re;
 	}
 
 	int y = x + 2 * len;
 	ll c = x + len;
 	int f = lower_bound(d, d + n, c) - d;
 	while (f < n && d[f] <= y) {
 		ll cc = d[f];
 		//if ((ll) len * len <= sqr(c - cc) + sqr(l[f]))
 		{
 			int cx = max((ll)c, cc - l[f]);
 			//cout << f << ' ' << cx << endl;
 			if (m.count(mp(f, cx)) == 0) {
 				m[mp(f, cx)] = 1;
 				q.push(mp(f, cx));
 			}
 		}
 		f++;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 
 		cin >> n;
 		rep(i, n) cin >> d[i] >> l[i];
 		cin >> D;
 
 		m.clear();
 
 		m[mp(0, 0)] = 1;
 		q.push(mp(0, 0));
 		g = 0;
 
 		while (!q.empty()) {
 			parse(q.front());
 			q.pop();
 		}
 
 		cout << (g ? "YES" : "NO");
 		cout << endl;
 	}
 
 	re 0;
 }
