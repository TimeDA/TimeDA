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
 
 const int N = 2000;
 
 int n;
 int m;
 int x[N + 1];
 int y[N + 1];
 int res[1 << 15];
 int sum[1 << 15];
 int can[1 << 15];
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n;
 		for (int i = 0; i < n; i++) {
 			string s;
 			cin >> s >> x[i];
 			y[i] = int (s == "E") - int (s == "L");
 		}
 		res[0] = 0;
 		for (int i = 1; i < (1 << n); i++) {
 			res[i] = 1e9;
 			vi v;
 			int last = 0;
 			int ok = 1;
 			for (int j = 0; j < n; j++)
 				if ((i >> j) & 1) {
 					v.pb (j);
 					if (x[j] > 0) {
 						if (last != 0 && last != x[j])
 							ok = 0;
 						last = x[j];	
 					}
 				}
 			for (int j = 0; j + 1 < sz (v); j++)
 				if (y[v[j]] == y[v[j + 1]])
 					ok = 0;
 			if (last)
 				for (int j = 0; j < n; j++)
 					if (((i >> j) & 1) == 0 && x[j] == last)
 						ok = 0;
 			can[i] = ok;
 			sum[i] = int (y[v[sz (v) - 1]] == 1);
 //			printf ("%d = %d\n", i, ok);
 		}
 		for (int i = 0; i < (1 << n); i++)
 			for (int j = (i + 1) | i; j < (1 << n); j = (j + 1) | i) {
 				int k = j - i;
 			//	printf ("%d %d %d\n", i, j, k);
 				if (can[k])
 					res[j] = min (res[j], res[i] + sum[k]);
 			}
 		cout << "Case #" << it << ": ";
 		if (res[(1 << n) - 1] > n) cout << "CRIME TIME"; else cout << res[(1 << n) - 1];
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }