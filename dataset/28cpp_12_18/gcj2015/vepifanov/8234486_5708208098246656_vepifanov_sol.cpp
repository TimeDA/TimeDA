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
 
 const int di[4] = {0, -1, 0, 1};
 const int dj[4] = {-1, 0, 1, 0};
 
 int n;
 int m;
 
 string s[100];
 int row[100];
 int col[100];
 
 int get (char c) {
 	if (c == '<') re 0;
 	if (c == '^') re 1;
 	if (c == '>') re 2;
 	re 3;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 
 		cin >> n >> m;
 		for (int i = 0; i < n; i++) cin >> s[i];
 
 		memset (row, 0, sizeof (row));
 		memset (col, 0, sizeof (col));
 
 		int ans = 0;
 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < m; j++)
 				if (s[i][j] != '.') {
 					row[i]++;
 					col[j]++;
 				}
 		for (int i = 0; i < n && ans != -1; i++)
 			for (int j = 0; j < m; j++)
 				if (s[i][j] != '.') {
 					int ii = i, jj = j;
 					int d = get (s[i][j]);
 					int bad = 0;
 					while (true) {
 						ii += di[d];
 						jj += dj[d];
 						if (ii < 0 || jj < 0 || ii >= n || jj >= m) {
 							bad = 1;
 							break;
 						}
 						if (s[ii][jj] != '.') break;
 					}
 					if (bad) {
 						if (row[i] == 1 && col[j] == 1) {
 							ans = -1;
 							break;
 						}
 						ans++;
 					}
 				}
 		cout << "Case #" << it << ": ";
 		if (ans == -1) cout << "IMPOSSIBLE"; else cout << ans;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }