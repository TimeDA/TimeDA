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
 
 const int N = 150;
 int i, j, k, m, n, l;
 double e[N], s[N], d[N][N], ans[N][N], a[N][N];
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt0.in", "r", stdin);
 	freopen("C-small-attempt0.out", "w", stdout);
 
 	//freopen("C-large.in", "r", stdin);
 	//freopen("C-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
 		int Q;
 		cin >> n >> Q;
 		F1(i, n) {
 			cin >> e[i] >> s[i];
 		}
 		F1(i, n) {
 			F1(j, n) {
 				cin >> d[i][j];
 				if (i == j) d[i][j] = 0;
 				if (d[i][j] < -0.5) d[i][j] = 1e50;
 			}
 		}
 		F1(k, n) F1(i, n) F1(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
 
 		F1(start, n) {
 			F1(j, n) ans[start][j] = 1e50;
 			set< pair<double, pii> > S;
 			F1(i, n) F1(j, n) a[i][j] = 1e50;
 			S.insert(make_pair(0, pii(start, start)));
 			a[start][start] = 0;
 			while (!S.empty()) {
 				auto z = *S.begin(); S.erase(S.begin());
 
 				double t = z.first;
 				int i = z.second.first;
 				int horse = z.second.second;
 
 				ans[start][i] = min(ans[start][i], a[i][horse]);
 
 				F1(j, n) {
 					if (d[horse][i] + d[i][j] <= e[horse] + 0.5 && a[j][horse] > t + d[i][j] / s[horse]) {
 						a[j][horse] = t + d[i][j] / s[horse];
 						S.insert(make_pair(a[j][horse], pii(j, horse)));
 					}
 					// new horse
 					if (d[i][j] <= e[i] + 0.5 && a[j][i] > t + d[i][j] / s[i]) {
 						a[j][i] = t + d[i][j] / s[i];
 						S.insert(make_pair(a[j][i], pii(j, i)));
 					}
 				}
 			}
 		}
   		printf("Case #%d:", tt);
 		while (Q--) {
 			cin >> i >> j;
 			printf(" %.6lf", ans[i][j]);
 
 		}
 		puts("");
 	}
 	return 0;
 }
