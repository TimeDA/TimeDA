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
 int was[4];
 int use[4];
 int g[4][4];
 int w[4][4];
 
 int cool (int i) {
 	if (i == n) re 1;
 	for (int j = 0; j < n; j++)
 		if (!was[j]) {
 			was[j] = 1;
 			int ok = 0;
 			for (int k = 0; k < n; k++)
 				if (w[j][k] && !use[k]) {
 					ok = 1;
 					use[k] = 1;
 					if (!cool (i + 1)) re 0;
 					use[k] = 0;
 				}
 			was[j] = 0;	
 			if (!ok) re 0;
 		}
 	re 1;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n;
 		for (int i = 0; i < n; i++) {
 			string s;
 			cin >> s;
 			for (int j = 0; j < n; j++)
 				g[i][j] = s[j] - '0';
 		}
 		int answer = n * n;
 		for (int mask = 0; mask < (1 << (n * n)); mask++) {
 			int cur = 0;
 			for (int i = 0; i < n; i++)
 				for (int j = 0; j < n; j++)
 					if ((mask >> (i * n + j)) & 1) {
 						w[i][j] = g[i][j] | 1;
 						cur++;
 					} else w[i][j] = g[i][j];	
 			memset (was, 0, sizeof (was));
 			memset (use, 0, sizeof (use));
 			if (cur < answer && cool (0)) answer = cur;
 		}
 		cout << "Case #" << it << ": " << answer;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }