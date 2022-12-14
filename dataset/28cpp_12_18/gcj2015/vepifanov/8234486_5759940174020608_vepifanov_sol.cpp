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
 int mask[2500];
 map<string, int> all;
 int o;
 char h[20000];
 
 int get (string s) {
 	if (all.find (s) != all.end ()) re all[s];
 	mask[o] = 0;
 	all[s] = o++;
 	re o - 1;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		o = 0;
 		all.clear ();
 		scanf ("%d", &n);
 		gets (h);
 		for (int i = 0; i < n; i++) {
 			gets (h);
 			stringstream in (h);
 			string s;
 			while (in >> s) {
 				int x = get (s);
 				mask[x] |= 1 << i;
 			}
 		}
 		int ans = 1e9;
 		for (int i = 2; i < (1 << n); i += 4) {
 			int cur = 0;
 			for (int j = 0; j < o; j++) {
 				if ((mask[j] & i) == 0) continue;
 				if ((mask[j] & i) == mask[j]) continue;
 				cur++;
 			}	
 			ans = min (ans, cur);
 		}
 		cout << "Case #" << it << ": " << ans;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }