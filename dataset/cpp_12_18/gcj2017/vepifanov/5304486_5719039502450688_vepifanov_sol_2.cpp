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
 
 const int inf = 1e9;
 
 int n;
 int m;
 int hd, ad, hk, ak, b, d;
 
 int go (int hd, int ad, int hk, int ak, int f, int lh) {
 //	printf ("%d %d %d %d %d %d\n", hd, ad, hk, ak, f, lh);
 	int cur = 1e9;
 	if (lh == 2) re cur;
 	if (f == 0) {
 		if (hd - (ak - d) <= 0) cur = min (cur, go (::hd - ak, ad, hk, ak, 0, lh + 1) + 1); else {
 			if (ak > 0 && d > 0) {
 				int nak = max (0, ak - d);
 				cur = min (cur, go (hd - nak, ad, hk, nak, 0, 0) + 1);
 			}	
 		}
 		cur = min (cur, go (hd, ad, hk, ak, 1, lh));
 	}
 	if (f == 1) {
 		if (hd - ak <= 0) cur = min (cur, go (::hd - ak, ad, hk, ak, 1, lh + 1) + 1); else {
 			if (ad < hk && b > 0) {
 				cur = min (cur, go (hd - ak, ad + b, hk, ak, 1, 0) + 1);
 			}	
 		}
 		cur = min (cur, go (hd, ad, hk, ak, 2, lh));
 	}
 	if (f == 2) {
 		if (hk <= ad) re 1;
 		if (hd - ak <= 0) cur = min (cur, go (::hd - ak, ad, hk, ak, 2, lh + 1) + 1); else cur = min (cur, go (hd - ak, ad, hk - ad, ak, 2, 0) + 1);
 	}
 	re cur;
 }
 
 int main () {
 	int tt;
 	cin >> tt;
 	for (int it = 1; it <= tt; it++) {
 		cin >> hd >> ad >> hk >> ak >> b >> d;		
 		int ans = go (hd, ad, hk, ak, 0, 0);
 		cout << "Case #" << it << ": ";
 		if (ans >= inf) cout << "IMPOSSIBLE"; else cout << ans;
 		cout << endl;
 		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
 	}
 	return 0;
 }