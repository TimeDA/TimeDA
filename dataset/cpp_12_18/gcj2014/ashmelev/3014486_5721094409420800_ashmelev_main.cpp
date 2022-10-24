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
 typedef vector<string> vs;
 typedef double D;
 typedef long double LD;
 typedef long long ll;
 typedef pair<ll, ll> pll;
 typedef vector<ll> vll;
 
 template<class T> T abs(T x) { return x > 0 ? x : -x;}
 
 int m;
 int n;
 
 int a[1000];
 
 int getans(vi v, int rev) {
 	int ans = 0;
 	rep(i, sz(v))
 	rep(j, i)
 	if ((v[i] < v[j]) ^ rev)
 		ans++;
 	re ans;
 }
 
 int getans(int p) {
 	vi v1, v2;
 
 	if (p <= m) {
 		rep(i, p)
 			v1.pb(a[i]);
 		for (int i = p; i < n; i++)
 			if (i != m)
 				v2.pb(a[i]);
 	}
 	else {
 		rep(i, p + 1)
 			if (i != m)
 				v1.pb(a[i]);
 		for (int i = p + 1; i < n; i++)
 			v2.pb(a[i]);
 	}
 /*
 	rep(i, p + 1)
 		if (i != m)
 			v1.pb(a[i]);*/
 
 	if (sz(v1) + sz(v2) != n - 1)
 		while (true);
 
 	re abs(p - m) + getans(v1, 0) + getans(v2, 1);
 }
 
 int main() {
 
 #ifdef LOCAL_BOBER
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 #endif
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 
 		cin >> n;
 		rep(i, n) {
 			cin >> a[i];
 		}
 		m = max_element(a, a + n) - a;
 
 		/*vi v;
 		rep(i, n)
 			v.pb(a[i]);
 		rep(i, n)
 			cout << a[i] << ' ';
 		cout << endl;
 		cout << getans(v, 0) << endl;*/
 
 		int best = 1000000000;
 		rep(i, (1 << n)) {
 			vi v1;
 			vi v2;
 			vi v;
 			rep(j, n) {
 				v.pb((i >> j) & 1);
 
 				if (i & (1 << j))
 					v2.pb(a[j]);
 				else
 					v1.pb(a[j]);
 			}
 			int o = getans(v, 0) + getans(v1, 0) + getans(v2, 1);
 			//cout << i << ' ' << getans(v1, 0) << ' ' << getans(v2, 1) << ' ' << sz(v1) << ' ' << sz(v2) << endl;
 			//cout << i << ' ' << o << ' ' << sz(v1) << ' ' << sz(v2) << endl;
 			if (o < best) {
 				best = o;
 			}
 		}
 
 		/*
 		for (int p = 0; p < n; p++) {
 			int tmp = getans(p);
 			if (tmp < best)
 				best = tmp;
 		}
 		rep(i, n)
 			cout << a[i] << ' ';
 		cout << endl;*/
 		cout << best << endl;
 	}
 
 
 	re 0;
 }
 
