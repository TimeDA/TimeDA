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
 
 vii v;
 int rr[1000];
 int use[1000];
 
 ii ans[1000];
 
 void go(int x1, int y1, int x2, int y2, int f1, int f2, int f3, int f4) {
 	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << endl;
 
 	rep(i, sz(v)) {
 		if (!use[i])
 			continue;
 		int r = v[i].fi;
 		int lx = x1;
 		if (f1)
 			lx -= r;
 		int rx = lx + 2 * r;
 		int ly = y1;
 		if (f3)
 			ly -= r;
 		int ry = ly + 2 * r;
 
 
 		if (ry > y2 && !f4)
 			continue;
 		if (rx > x2 && !f2)
 			continue;
 		int cx = (lx + rx) / 2;
 		if (cx > x2)
 			continue;
 		int cy = (ly + ry) / 2;
 		if (cy > y2)
 			continue;
 
 		//cout << ": " << lx << ' ' << rx << ' ' << ly << ' ' << ry << endl;
 
 		use[i] = 0;
 		ans[v[i].se] = mp((lx + rx) / 2, (ly + ry) / 2);
 
 		if (x2 > rx) {
 			int ny2 = min(y2, ry);
 			int nf4 = f4;
 			if (y2 != ny2)
 				nf4 = 0;
 			go(rx, y1, x2, ny2, 0, f2, f3, nf4);
 		}
 
 		if (y2 > ry) {
 			go(x1, ry, x2, y2, f1, f2, 0, f4);
 		}
 		break;
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tc;
 	cin >> tc;
 	rep(tt, tc) {
 		cout << "Case #" << tt + 1 << ": ";
 
 		v.clear();
 		ll w, h;
 		cin >> n >> w >> h;
 		rep(i, n) {
 			int x;
 			cin >> x;
 			rr[i] = x;
 			v.pb(mp(x, i));
 		}
 		sort(all(v));
 		reverse(all(v));
 		rep(i, sz(v)) {
 			int c = v[i].fi;
 			int o = 1;
 			while (o < c)
 				o *= 2;
 			v[i].fi = o;
 		}
 
 		rep(i, n)
 		use[i] = 1;
 
 		go(0, 0, w, h, 1, 1, 1, 1);
 
 		/*
 		rep(i, n)
 		cout << use[i] << ' ';
 		cout << endl;*/
 
 		rep(i, n)
 		if (use[i])
 			while (1);
 
 		rep(i, n) rep(j, i) {
 			int d = max(abs(ans[i].fi - ans[j].fi), abs(ans[i].se - ans[j].se));
 			if (d < rr[i] + rr[j]) {
 				//cout << i << ' ' << j << endl;
 				//exit(0);
 				while (1);
 			}
 			if (ans[i].fi > w || ans[i].fi < 0)
 				while (1);
 		}
 
 		rep(i, n)
 		cout << ans[i].fi << ' ' << ans[i].se << ' ';
 		cout << endl;
 	}
 
 	re 0;
 }
