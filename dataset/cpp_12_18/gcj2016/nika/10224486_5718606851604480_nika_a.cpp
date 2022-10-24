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
 const string h = "PRS";
 
 string build(int i, int n) {
 	if (n == 0) return string(1, h[i]);
 	string a = build(i, n - 1);
 	string b = build((i + 1) % 3, n - 1);
 	if (a > b) swap(a, b);
 	return a + b;
 }
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 
 	//freopen("A-large.in", "r", stdin);
 	//freopen("A-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		int R, P, S;
 		cin >> n >> R >> P >> S;
 
 		string q = "Z";
 		F0(i, 3) {
 			string s = build(i, n);
 			//cout << s << endl;
 			if (count(s.begin(), s.end(), 'P') == P && count(s.begin(), s.end(), 'S') == S && count(s.begin(), s.end(), 'R') == R) q = min(q, s);
 		}
 		if (q == "Z") q = "IMPOSSIBLE";
 
 		//cerr << tt << endl;
   		printf("Case #%d: ", tt);
 		cout << q << endl;
 	}
 	return 0;
 }
