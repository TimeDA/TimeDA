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
 
 int n;
 int m;
 
 int d[1000];
 int x[1000];
 int y[1000];
 int z[1000];
 int vx[1000];
 int vy[1000];
 int vz[1000];
 int mark[1000];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		scanf ("%d%d", &n, &m);
 		for (int i = 0; i < n; i++) {
 			scanf ("%d%d%d%d%d%d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
 			d[i] = 1e9;
 		}	
 		d[0] = 0;
 		mark[0] = 1;
 		for (int i = 0; i < n; i++) {
 			int k = -1;
 			for (int j = 0; j < n; j++)
 				if (mark[j] == 1 && (k == -1 || d[k] > d[j]))
 					k = j;
 			if (k == -1) break;
 			mark[k] = 2;
 			for (int j = 0; j < n; j++) {
 				int nd = max (d[k], sqr (x[j] - x[k]) + sqr (y[j] - y[k]) + sqr (z[j] - z[k]));
 				if (nd < d[j]) {
 					d[j] = nd;
 					mark[j] = 1;
 				}
 			}
 		}
 		cout.precision (10);
 		cout << "Case #" << it << ": " << sqrt (d[1] + 0.0);
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }