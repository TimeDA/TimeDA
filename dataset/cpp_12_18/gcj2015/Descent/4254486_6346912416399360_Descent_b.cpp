#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, m, a[1005], b[1005], s[1005];
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%d%d", &n, &m);
 	FOR(i,0,n-m+1) scanf("%d", &s[i]);
 	
 	FOR(i,0,m){
 		int mx = 0, mn = 0, delta = 0;
 		for (int k=i; k+1<n-m+1;k+=m){
 			delta += s[k+1] - s[k];
 			mx = max(mx, delta);
 			mn = min(mn, delta);
 		}
 		a[i] = -mn;
 		b[i] = mx;
 	}
 	
 	int S = 0;
 	FOR(i,0,m) S += a[i];
 	while (S > s[0]) S -= m;
 	while (S + m <= s[0]) S += m;
 	while (S < s[0]){
 		int p = 0;
 		FOR(i,0,m) if (a[i] + b[i] < a[p] + b[p]) p = i;
 		++a[p];
 		++S;
 	}
 	int ret = 0;
 	FOR(i,0,m) ret = max(ret, a[i] + b[i]);
 	printf("%d\n", ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
