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
 #include <cassert>
 
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
 
 const int mod = 1000*1000*1000+7;
 
 int n;
 int m;
 int q, d;
 int x[200];
 int y[200];
 int z[200];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n >> m >> q >> d;		
 		for (int i = 0; i < q; i++) {
 			cin >> x[i] >> y[i] >> z[i];
 			x[i]--;
 			y[i]--;
 		}	
 		int ok = 1;
 		ll ans = 0;
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++) {
 				ll l = -4e18, r = 4e18;
 				for (int k = 0; k < q; k++) {
 					ll dist = abs (x[k] - i) + abs (y[k] - j);
 					l = max (l, z[k] - dist * d);
 					r = min (r, z[k] + dist * d);
 				}
 //				printf ("%d %d = %lld %lld\n", i, j, l, r);
 				if (l > r) ok = 0; else ans = (ans + r) % mod;
 			}
 		cout.precision (20);
 		cout << "Case #" << it << ": ";
 		if (ok) cout << ans; else cout << "IMPOSSIBLE";
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }