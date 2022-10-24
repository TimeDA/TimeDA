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
 string s[26];
 int g[26][26], p[26], v1[26], v2[26];
 
 int rec(int cnt) {
 	F0(i, n) if (!v1[i]) {
 		bool any = false, anybad = false;
 		F0(j, n) if (!v2[j] && g[i][j]) {
 			v1[i] = v2[j] = 1;
 			if (!rec(cnt + 1)) anybad = true; else any = true;
 			v1[i] = v2[j] = 0;
 		}
 		if (!any || anybad) return 0;
 	}
 	return 1;
 }
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("D-small-attempt0.in", "r", stdin);
 	freopen("D-small-attempt0.out", "w", stdout);
 
 	//freopen("D-large.in", "r", stdin);
 	//freopen("D-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		//cerr << tt << endl;
 		cin >> n;
 		F0(i, n) cin >> s[i];
 		int q = n * n;
 		F0(mask, (1 << (n*n))) {
 			int good = 1, cnt = 0;
 			F0(i, n) F0(j, n) {
 				g[i][j] = (s[i][j] == '1');
 				if (mask&(1 << (i*n + j))) {
 					if (g[i][j]) good = 0;
 					else {
 						cnt++;
 						g[i][j] = 1;
 					}
 				}
 			}
 			if (good && cnt < q) {
 				F0(i, n) v1[i] = v2[i] = 0;
 				if (rec(0)) {
 					q = cnt;
 				}
 			}
 		}
 		printf("Case #%d: ", tt);
 		cout << q << endl;
 	}
 	return 0;
 }
