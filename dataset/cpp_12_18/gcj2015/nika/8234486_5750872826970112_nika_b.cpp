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
 typedef pair<int, int> pii;
 #define SZ(x) (int)(x.size())
 #define F0(i,n) for(int i=0;i<n;i++)
 #define F1(i,n) for(int i=1;i<=n;i++)
 const int MOD = 1000002013;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-10;
 ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n - 1)&n) + 1 : 0; }
 
 int i, j, k, m, n, l;
 double v[105], t[105], V, T, x[105];
 
 bool ok(double R) {
 	double s = 0.0, s1 = 0.0, s2 = 0.0, L;
 	F0(i, n) {
 		x[i] = v[i] * R;
 		s += x[i];
 	}
 	if (s < V) return false;
 
 	L = V;
 	F0(i, n) {
 		double y = min(x[i], L);
 		L -= y;
 		s1 += y * t[i];
 	}
 
 	L = V;
 	for (int i = n - 1; i >= 0; i--) {
 		double y = min(x[i], L);
 		L -= y;
 		s2 += y * t[i];
 	}
 	return (s1  <= V * T && V * T <= s2);
 }
 
 int main() {
 	//freopen("x.in", "r", stdin);
 
 	freopen("B-small-attempt2.in", "r", stdin);
 	freopen("B-small-attempt2.out", "w", stdout);
 
 	//freopen("B-large.in", "r", stdin);
 	//freopen("B-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt, tn) {
 		//cerr << tt << endl;
 		printf("Case #%d: ", tt);
 
 		cin >> n >> V >> T;
 		F0(i, n) cin >> v[i] >> t[i];
 		F0(i, n) for (int j = i + 1; j < n; j++) if (t[i] > t[j]) { swap(t[i], t[j]); swap(v[i], v[j]); }
 
 		int n2 = 1;
 		F1(i, n - 1) {
 			if (t[i] == t[n2 - 1]) {
 				v[n2 - 1] += v[i];
 			}
 			else {
 				t[n2] = t[i];
 				v[n2] = v[i];
 				n2++;
 			}
 		}
 		n = n2;
 
 		double P = 0.0, Q = 1e9;
 
 		if (!ok(Q)) cout << "IMPOSSIBLE"; else {
 			F0(k, 200) {
 				double R = (P + Q) / 2;
 				if (ok(R)) Q = R; else P = R;
 			}
 			printf("%.9lf", P);
 		}
 
 		cout << endl;
 	}
 	return 0;
 }
