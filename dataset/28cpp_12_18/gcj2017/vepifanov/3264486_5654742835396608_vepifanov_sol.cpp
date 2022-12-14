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
 vector<pair<ii, int> > v;
 
 int go (int l, int r) {
 	if (l > r) re 0;
 	int s = (l + r) / 2;
 	v.pb (mp (mp (l - s, s - r), s));
 	go (l, s - 1);
 	go (s + 1, r);
 	re 0;
 }
 
 int main () {
 /*	cin >> n;
 	for (int i = 0; i < n; i++) printf ("%d ", v[i].se);
 	printf ("\n");
 	re 0;*/
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> n >> m;
 		v.clear ();
 		go (0, n - 1);
 		sort (all (v));
 		cout << "Case #" << it << ": " << -v[m - 1].fi.se << " " << -v[m - 1].fi.fi;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }