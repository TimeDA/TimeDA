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
 int x[100];
 int remains[9], rn, tmp[9], tmpn, divs[20];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt0.out", "w", stdout);
 
 	//freopen("C-large.out", "w", stdout);
 
 	int tn = 1;
 
 	F1(tt,tn) {
 		printf("Case #%d:\n", tt);
 
 		set<string> S;
 		n = 16; m = 50;
 		x[0] = 1; x[n - 1] = 1;
 		while (SZ(S) < m) {
 			F1(i, n - 2) x[i] = rand() % 2;
 			rn = 9; F0(i, rn) {
 				remains[i] = i + 2; divs[i + 2] = 0;
 			}
 
 			for (int div = 2; div <= 7 && rn > 0; div++) {
 				int tmpn = rn;
 				F0(k, rn) {
 					int y = 0, big = 0, base = remains[k];
 					F0(i, n) {
 						y = (y * base + x[i]);
 						if (y > div) big = 1;
 						y %= div;
 					}
 					if (y == 0 && big) {
 						divs[remains[k]] = div;
 						remains[k] = -1;
 						tmpn = 0; F0(l, rn) if (remains[l] != -1) tmp[tmpn++] = remains[l];
 					}
 				}
 				if (tmpn != rn) {
 					rn = tmpn;
 					F0(k, rn) remains[k] = tmp[k];
 				}
 			}
 			if (rn == 0) {
 				string s;
 				F0(i, n) s += string(1, '0' + x[i]);
 				if (S.count(s)) continue;
 				S.insert(s);
 				cout << s;
 				for (int i = 2; i <= 10; i++) cout << " " << divs[i]; cout << endl;
 			}
 			//cerr << s << " " << SZ(S) << endl;
 		}
 	}
 	return 0;
 }
