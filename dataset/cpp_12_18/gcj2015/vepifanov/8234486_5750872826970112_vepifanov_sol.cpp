#include <cstdio>
 #include <numeric>
 #include <iostream>
 #include <vector>
 #include <set>
 #include <cstring>
 #include <string>
 #include <map>
 #include <cmath>
 #include <ctime>
 #include <algorithm>
 #include <bitset>
 #include <queue>
 #include <sstream>
 #include <deque>
 
 using namespace std;
 
 #define mp make_pair
 #define pb push_back
 #define rep(i,n) for(int i = 0; i < (n); i++)
 #define re return
 #define fi first
 #define se second
 #define sz(x) ((int) (x).size())
 #define all(x) (x).begin(), (x).end()
 #define sqr(x) ((x) * (x))
 #define sqrt(x) sqrt(abs(x))
 #define y0 y3487465
 #define y1 y8687969
 #define fill(x,y) memset(x,y,sizeof(x))
 #define prev PREV
                          
 typedef vector<int> vi;
 typedef long long ll;
 typedef long double ld;
 typedef double D;
 typedef pair<int, int> ii;
 typedef vector<ii> vii;
 typedef vector<string> vs;
 typedef vector<vi> vvi;
 
 template<class T> T abs(T x) { re x > 0 ? x : -x; }
 
 const ld eps = 1e-12;
 
 int n;
 int m;
 
 ld V, T;
 pair<ld, ld> v[100];
 
 bool can (ld h) {
 	ld mv = 0;
 	for (int i = 0; i < n; i++) mv += v[i].se * h;
 	if (mv < V - eps) re false;
 	ld mint = 0, rem = V;
 	for (int i = 0; i < n; i++) {
 		ld tmp = min (rem, v[i].se * h);
 		mint += v[i].fi * tmp;
 		rem -= tmp;
 	}
 	mint /= V;
 	ld maxt = 0;
 	rem = V;
 	for (int i = n - 1; i >= 0; i--) {
 		ld tmp = min (rem, v[i].se * h);
 		maxt += v[i].fi * tmp;
 		rem -= tmp;
 	}
 	maxt /= V;
 	re (mint - eps <= T && T <= maxt + eps);
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 
 		cin >> n >> V >> T;
 		for (int i = 0; i < n; i++) cin >> v[i].se >> v[i].fi;
 
 		sort (v, v + n);
 
 		cout << "Case #" << it << ": ";
 
 		if (v[0].fi > T + 1e-8 || v[n - 1].fi < T - 1e-8) cout << "IMPOSSIBLE"; else {
 			ld l = 0, r = 1e15;
 			for (int i = 0; i < 200; i++) {
 				ld s = (l + r) / 2;
 				if (can (s)) r = s; else l = s;
 			}
 			printf("%.10f", (double)l);
 		}
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }