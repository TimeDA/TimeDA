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
 
 int a, b;
 int d;
 int m;
 int fun(int n) {
 	int res = 0;
 	map<int, bool> M;
 	int i;
 	int d = ::d;
 	int nn = n;
 	while(d--) {
 		int k = nn%10;
 		nn /= 10;
 		nn += k * m;
 		if( nn > n && nn <= b ) 
 			M[nn] = true;
 	}
 	return M.size();
 
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for( cases=1; cases<=test; cases++ ) {
 		cin >> a >> b;
 		int i;
 		long long res = 0;
 		char str[100];
 		sprintf(str, "%d", a);
 		d = strlen(str);
 		m = 1;
 		for(i=0;i<d-1;i++) m *= 10;
 		for(i=a; i<=b; i++) {
 			res += fun(i);
 		}
 		pf("Case #%d: %lld\n", cases, res);
 	}
 	return 0;
 }
 
