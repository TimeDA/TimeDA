// PURE BRUTEFORCE SOLN //
 // feeling sleepy
 
 
 #include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 #define pf printf
 #define sf scanf
 #define VI vector<int>
 #define pb push_back
 #define fo(a,b) for((a)=0;(a)<(b);a++)
 
 #define debug 0
 const int inf = 1000000000;
 
 long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
 double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }
 
 int n, s, p;
 VI v;
 int res;
 
 void dfs(int u, int s, int cnt) {
 
 	if( s < 0 ) return;
 	if( u == v.size() ) {
 		if( s == 0 ) 
 			res >?= cnt;
 		return;
 	}
 	
 	int i, j, k;
 	for(i=0;i<=10;i++) 
 		for(j=i;j<=10;j++) {
 			if( i + j > v[u] ) break;
 			if( j - i > 2 ) break;
 			k = v[u] - i - j;
 			if( k < j ) break;
 			if( k - i > 2 ) continue;
 			if( k - i == 2 ) {
 				dfs(u+1, s-1, cnt + (k>=p ? 1 : 0));
 			}
 			else {
 				dfs(u+1, s, cnt + (k>=p ? 1 : 0));
 			}
 		}
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for( cases=1; cases<=test; cases++ ) {
 		v.clear();
 		cin >> n >> s >> p;
 		int i;
 		for(i=0; i<n; i++) {
 			int a; cin >> a; v.pb(a);
 		}
 		res = 0;
 		dfs(0, s, 0);
 		pf("Case #%d: %d\n", cases, res);
 	}
 	return 0;
 }
 
