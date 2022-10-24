#include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <string>
 #include <vector>
 #include <iostream>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <queue>
 #include <sstream>
 using namespace std;
 typedef long long ll;
 typedef pair<int,int> pii;
 #define SZ(x) (int)(x.size())
 #define F0(i,n) for(int i=0;i<n;i++)
 #define F1(i,n) for(int i=1;i<=n;i++)
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 int i, j, k, m, n, l;
 int d[100];
 
 int main() {
    // freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 
 	//freopen("A-large.in", "r", stdin);
 	//freopen("A-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		//cerr << tt << endl;
 		ll n;
 		cin >> n;
 		k = 0;
 		while (n > 0) {
 			d[k++] = n % 10;
 			n /= 10;
 		}
 
 		int smaller = 0;
 		for (int i = k - 1; i >= 0; i--) {
 			for (int digit = 9; digit >= 0; digit--) {
 				if (digit > d[i] && !smaller) continue;
 				if (i != k - 1 && digit < d[i + 1]) continue;
 
 				int bad = 0;
 				if (!smaller && digit == d[i]) {
 					for (int j = i - 1; j >= 0; j--) {
 						if (d[j] < digit) {
 							bad = 1;
 							break;
 						}
 						else if (d[j] > digit) break;
 					}
 				}
 
 				if (!bad) {
 					if (digit < d[i]) smaller = 1;
 					d[i] = digit;
 					break;
 				}
  			}
 		}
 		n = 0;
 		for (int i = k - 1; i >= 0; i--) n = n * 10 + d[i];
 
   		printf("Case #%d: %lld\n", tt, n);
 	}
 	return 0;
 }
