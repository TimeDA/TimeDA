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
 int ans, cnt, at[1005];
 string s[1005];
 
 int solve(vector<string> s) {
 	set<string> S;
 	for (string x : s) {
 		while (1) {
 			S.insert(x);
 			if (x.empty()) break;
 			else x.pop_back();
 		}
 	}
 	return SZ(S);
 }
 
 void go(int i) {
 	if (i == m) {
 		vector< vector<string> >vs(n);
 		F0(j,m) vs[at[j]].push_back(s[j]);
 		int ss = 0;
 		F0(j,n) ss += solve(vs[j]);
 		if (ss > ans) { ans = ss; cnt = 1; } else if (ss == ans) cnt++;
 		return;
 	}
 	for (at[i] = 0; at[i] < n; at[i]++) {
 		go(i+1);
 	}
 }
 
 int main() {
     //freopen("x.in", "r", stdin);
 
 	freopen("D-small-attempt0.in", "r", stdin);
 	freopen("D-small-attempt0.out", "w", stdout);
 
 	//freopen("D-large.in", "r", stdin);
 	//freopen("D-large.out", "w", stdout);
 
 	int tt, tn; cin >> tn;
 
 	F1(tt,tn) {
 		cerr << tt << endl;
 		cin >> m >> n;
 		F0(i,m) cin >> s[i];
 		ans = -1; cnt = 0;
 		go(0);
   		printf("Case #%d: ", tt);
 		cout << ans << " " << cnt << endl;
 	}
 	while (1);
 	return 0;
 }
