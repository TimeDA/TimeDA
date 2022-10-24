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
 
 map<string, int> M;
 int z, a1[1000000], a2[1000000];
 
 char ss[1000000];
 vector<int> read() {
 	gets(ss);
 	stringstream o;
 	o << ss;
 	vector<int> ret;
 	string s;
 	while (o >> s) {
 		if (!M.count(s)) M[s] = ++k;
 		ret.push_back(M[s]);
 	}
 	return ret;
 }
 
 vector<int> v[205];
 
 int main() {
  //  freopen("x.in", "r", stdin);
 
 	freopen("C-small-attempt1.in", "r", stdin);
 	freopen("C-small-attempt1.out", "w", stdout);
 
 	//freopen("C-large.in", "r", stdin);
 	//freopen("C-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		M.clear(); k = 0;
 		cerr << tt << endl;
 		printf("Case #%d: ", tt);
 
 		scanf("%d\n", &n);
 		F0(i, n) v[i] = read();
 		int ans = 1000000000;
 
 		F0(mask, (1 << (n - 2))) {
 			++z;
 			for (int x : v[0]) a1[x] = z;
 			for (int x : v[1]) a2[x] = z;
 			for (int i = 2; i < n; i++) if ((1 << (i - 2))&mask) {
 				for (int x : v[i]) a1[x] = z;
 			}
 			else {
 				for (int x : v[i]) a2[x] = z;
 			}
 			int cnt = 0;
 			F1(i, k) if (a1[i] == z && a2[i] == z) cnt++;
 			ans = min(ans, cnt);
 		}
 		cout << ans;
 
 		cout << endl;
 	}
 	return 0;
 }
