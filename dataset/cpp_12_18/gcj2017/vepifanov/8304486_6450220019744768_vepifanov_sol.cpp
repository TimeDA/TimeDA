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
 
 const int N = 10000;
 
 int n;
 int m;
 int was[N];
 int prev[N];
 int preve[N];
 int val[N];
 vii v[N];
 
 int go (int x, int pe) {
 	was[x] = 1;
 	for (int i = 0; i < sz (v[x]); i++) {
 		int y = v[x][i].fi;
 		int z = v[x][i].se;
 		if ((z ^ 1) == pe || was[y] == 2) continue;
 		if (was[y] == 1) {
 			int k = x;
 			while (k != y) {
 				val[preve[k]]++;
 				k = prev[k];
 			}
 			val[z]++;
 		} else {
 			prev[y] = x;
 			preve[y] = z;
 			go (y, z);
 		}	
 	}
 	was[x] = 2;
 	re 0;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		scanf ("%d%d", &n, &m);
 		for (int i = 0; i < n; i++) v[i].clear ();
 		for (int i = 0; i < m; i++) {
 			int a, b;
 			scanf ("%d%d", &a, &b); a--; b--;
 			v[a].pb (mp (b, 2 * i));
 			v[b].pb (mp (a, 2 * i + 1));
 		}
 		memset (val, 0, sizeof (val));
 		memset (was, 0, sizeof (was));
 		for (int i = 0; i < n; i++)
 			if (!was[i])
 				go (i, -1);
 		int ok = 1;
 		for (int i = 0; i < m; i++) {
 			assert (val[2 * i] == 0 || val[2 * i + 1] == 0);
 			if (val[2 * i] + val[2 * i + 1] == 0)
 				ok = 0;
 		}
 		cout.precision (20);
 		cout << "Case #" << it << ": ";
 		if (!ok) cout << "IMPOSSIBLE"; else {
 			for (int i = 0; i < m; i++)
 				cout << val[2 * i] - val[2 * i + 1] << " ";
 		}
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }