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
 
 int n;
 int m;
 int g[6][6];
 int w[6][6];
 int W[6][6];
 
 int ans;
 set<string> all;
 
 int go (int i, int j) {
 	if (j == m) {
 		j = 0;
 		i++;
 	}
 	if (i == n) {
 		string cur = "";
 		for (int s = 0; s < n; s++) {
 			string tmp = "";
 			for (int a = 0; a < n; a++)
 				for (int b = 0; b < m; b++)
 					tmp += char (g[(a + s) % n][b] + '0');
 			if (cur == "" || cur > tmp) cur = tmp;
 		}
 		if (all.find (cur) != all.end ()) re 0;
 		all.insert (cur);
 /*		for (int a = 0; a < n; a++)
 			for (int b = 0; b < m; b++) {
 				assert (W[a][b] == 0);
 				if (w[a][b] != g[a][b])
 					re 0;
 			}*/
 /*		for (int a = 0; a < n; a++) {
 			for (int b = 0; b < m; b++) {
 				printf ("%d ", g[a][b]);
 			}
 			printf ("\n");
 		}
 		printf ("\n");*/
 		re 1;
 	}
 	int ans = 0;
 	for (int t = 1; t <= 3; t++) {
 		g[i][j] = t;
 		w[i][j] = 0;
 		W[i][j] = 0;
 		int ok = 1;
 		for (int s = 0; s < 4; s++) {
 			int ni = i + int (s == 0) - int (s == 1);
 			int nj = j + int (s == 2) - int (s == 3);
 			if (ni < 0) ni += n;
 			if (ni >= n) ni -= n;
 			if (nj < 0 || nj >= m) continue;
 			if (g[ni][nj] == -1) {
 				W[i][j]++;
 				continue;
 			} else {
 				if (i != ni || j != nj) W[ni][nj]--;
 			}
 			if (g[ni][nj] == g[i][j]) {
 				w[i][j]++;
 				if (i != ni || j != nj) w[ni][nj]++;
 			}
 			if (i != ni || j != nj)
 				if (w[ni][nj] > g[ni][nj] || w[ni][nj] + W[ni][nj] < g[ni][nj]) ok = 0;
 		}
 //		printf ("%d %d %d\n", g[i][j], w[i][j], W[i][j]);
 		if (w[i][j] > g[i][j] || w[i][j] + W[i][j] < g[i][j]) ok = 0;
 		if (ok) ans += go (i, j + 1);
 		for (int s = 0; s < 4; s++) {
 			int ni = i + int (s == 0) - int (s == 1);
 			int nj = j + int (s == 2) - int (s == 3);
 			if (ni < 0) ni += n;
 			if (ni >= n) ni -= n;
 			if (nj < 0 || nj >= m) continue;
 			if (g[ni][nj] == -1) {
 				W[i][j]--;
 				continue;
 			} else {
 				if (i != ni || j != nj) W[ni][nj]++;
 			}
 			if (g[ni][nj] == g[i][j]) {
 				w[i][j]--;
 				if (i != ni || j != nj) w[ni][nj]--;
 			}
 		}
 		assert (w[i][j] == 0 && W[i][j] == 0);
 		g[i][j] = -1;
 	}
 	re ans;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> m >> n;
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				g[i][j] = -1;
 		all.clear ();
 		ans = go (0, 0);
 /*		for (int i = 1; i <= n; i++) 
 			if (n % i == 0)
 				ans += meb (n / i) * go (0, 0, i);		*/
 		cout << "Case #" << it << ": " << ans;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }