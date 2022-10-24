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
 
 const int W = 1010;
 const int H = 2010;
 
 int n;
 int m;
 int bad[W][H];
 vii v[2 * W * H];
 int cf[W * H * 6];
 int e, o;
 int prev[2 * W * H];
 int preve[2 * W * H];
 int w, h;
 int x1[1000], y1[1000];
 int x2[1000], y2[1000];
 vi vy;
 map<int, int> num;
 int r;
 
 int addedge (int a, int b, int c) {
 	v[a].pb (mp (b, e));
 	cf[e] = c;
 	e++;
 	v[b].pb (mp (a, e));
 	cf[e] = 0;
 	e++;
 	re 0;
 }
 
 int ct;
 int q[W * H];
 int was[W * H];
 
 int go (int S, int T) {	
 	ct++;
 	int l = 0, r = 1;
 	q[0] = S;
 	while (l < r) {
 		int x = q[l++];
 		for (int i = 0; i < sz (v[x]); i++) {
 			int y = v[x][i].fi;
 			int z = v[x][i].se;
 			if (cf[z] > 0 && was[y] != ct) {
 				was[y] = ct;
 				prev[y] = x;
 				preve[y] = z;
 				q[r++] = y;
 			}
 		}
 		if (was[T] == ct) re 1;
 	}
 	re 0;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		scanf ("%d%d%d", &w, &h, &n);
 		for (int i = 0; i < n; i++) {
 			scanf ("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
 			x2[i]++;
 			y2[i]++;
 		}
 		vy.clear ();
 		for (int i = 0; i <= h; i++) vy.pb (i);
 		num.clear ();
 		for (int i = 0; i < sz (vy); i++) num[vy[i]] = i;
 		r = h;
 		for (int i = 0; i < w; i++)
 			for (int j = 0; j < r; j++)
 				bad[i][j] = 0;
 		for (int i = 0; i < n; i++) {
 //			printf ("%d %d %d %d -\n", x1[i], x2[i] + 1, y1[i], y2[i]);
 			for (int a = x1[i]; a < x2[i]; a++)
 				for (int b = y1[i]; b < y2[i]; b++)
 					bad[a][b] = 1;
 //			cerr << i << endl;
 		}
 		e = 0;
 		o = 2 * w * r + 2;
 		for (int i = 0; i < o; i++) v[i].clear ();
 		for (int i = 0; i < w; i++)
 			for (int j = 0; j < r; j++)
 				if (!bad[i][j]) {
 					int k = i * r + j;
 					if (j == 0) addedge (o - 2, 2 * k, 1);
 					if (j + 1 == r) addedge (2 * k + 1, o - 1, 1);
 					addedge (2 * k, 2 * k + 1, vy[j + 1] - vy[j]);
 					for (int t = 0; t < 2; t++) {
 						int ni = i + int (t == 0);
 						int nj = j + int (t == 1);
 						if (ni < w && nj < r && !bad[ni][nj]) {
 							int nk = ni * r + nj;
 							int nc = (t == 0) ? (vy[j + 1] - vy[j]) : 1;
 							addedge (2 * k + 1, 2 * nk, nc);
 							addedge (2 * nk + 1, 2 * k, nc);
 						}
 					}
 				}
 //		printf ("%d %d %d\n", o, e, 2 * W * H);
 		int ans = 0;
 		while (go (o - 2, o - 1)) {
 			ans++;
 			int j = o - 1;
 			while (j != o - 2) {
 //				printf ("%d ", j / 2);
 				int k = prev[j];
 				int z = preve[j];
 				cf[z]--;
 				cf[z ^ 1]++;
 				j = k;
 			}
 //			printf ("\n");
 		}
 		cout << "Case #" << it << ": " << ans;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }