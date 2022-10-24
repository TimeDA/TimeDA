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
 
 const int TT = 40000;
 const ll MAXRAND = 1e18;
 
 int n;
 int m;
 vi v[100];
 int par[100];
 string s[5];
 string ch;
 int cnt[5];
 int was[5];
 int p[5][21];
 int pos[5];
 int q[100];
 
 void go (char c) {
 	for (int i = 0; i < m; i++) {
 		if (was[i]) continue;
 		while (pos[i] >= 0 && s[i][pos[i] + 1] != c) pos[i] = p[i][pos[i]];
 		if (s[i][pos[i] + 1] == c) pos[i]++;
 		if (pos[i] + 1 == sz (s[i])) was[i] = 1;
 	}
 }
 
 double f[101];
 int hook[101];
 double cur[101];
 
 int calc (int x) {
 	hook[x] = 1;
 	for (int i = 0; i < sz (v[x]); i++)
 		hook[x] += calc (v[x][i]);
 	re hook[x];
 }
 
 ll myrand () {
 	re abs ((((((rand () << 16) | rand ()) << 16) | rand ()) << 16) | rand ());
 }
 
 int main () {
 	f[0] = 1;
 	for (int i = 1; i <= 100; i++) f[i] = f[i - 1] * i;
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n;
 		for (int i = 0; i < n; i++) v[i].clear ();
 		for (int i = 0; i < n; i++) {
 			cin >> par[i];
 			par[i]--;
 			if (par[i] != -1) v[par[i]].pb (i);
 		}
 		for (int i = 0; i < n; i++)
 			if (par[i] == -1)
 				calc (i);
 		cin >> ch;
 		cin >> m;
 		for (int i = 0; i < m; i++) {
 			cin >> s[i];
 			p[i][0] = -1;
 			for (int j = 1; j < sz (s[i]); j++) {
 				int k = p[i][j - 1];
 				while (k >= 0 && s[i][k + 1] != s[i][j]) k = p[i][k];
 				if (s[i][k + 1] == s[i][j]) k++;
 				p[i][j] = k;
 			}
 		}
 		memset (cnt, 0, sizeof (cnt));
 		for (int it = 0; it < TT; it++) {
 			int r = 0;
 			for (int i = 0; i < n; i++)
 				if (par[i] == -1)
 					q[r++] = i;
 			for (int i = 0; i < m; i++) {
 				pos[i] = -1;
 				was[i] = 0;
 			}
 			for (int i = 0; i < n; i++) {
 				int sum = 0;
 				for (int j = 0; j < r; j++) {
 					cur[j] = hook[q[j]];
 					sum += cur[j];
 				}
 				int now = myrand () % sum;
 				int k = 0;
 				while (k + 1 < r && now >= cur[k]) {
 					now -= cur[k];
 					k++;
 				}
 				int x = q[k];
 				swap (q[k], q[r - 1]); r--;
 				go (ch[x]);
 				for (int j = 0; j < sz (v[x]); j++) q[r++] = v[x][j];
 			}
 			for (int i = 0; i < m; i++) cnt[i] += was[i];
 		}
 		cout.precision (10);
 		cout << "Case #" << it << ": ";
 		for (int i = 0; i < m; i++) cout << (cnt[i] + 0.0) / TT << " ";
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }