#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 #define N 1005
 using namespace std;
 
 int n, done;
 int A[N], B[N], b[N], l[N], v[N];
 int MX;
 
 void dfs(int x){
 	if (done) return;
 	
 	if (x < n){
 		int ok = 1;
 		for (int i=x-1; i>=0; i--){
 			b[i] = 1;
 			for (int j=i+1; j<x; j++) if (l[i] > l[j]) b[i] = max(b[i], B[j] + 1);
 			if (b[i] > B[i]) ok = 0;
 			int cnt = 0;
 			for (int j=0; j<l[i]; j++) cnt += 1 - v[j];
 			if (i == x - 1 && cnt + 1 < B[i]) ok = 0;
 			if (b[i] != B[i] && cnt + 1 < B[i]) ok = 0;
 			if (ok == 0) break;
 		}
 		if (!ok) return;
 	}
 
 	if (x == n){
 		int ok = 1;
 		for (int i=n-1; i>=0; i--){
 			b[i] = 1;
 			for (int j=i+1; j<n; j++) if (l[i] > l[j]) b[i] = max(b[i], b[j] + 1);
 			if (b[i] != B[i]) ok = 0;
 		}
 		if (ok) done = 1;
 	}
 	else{
 		int mn = n, mx = n;
 		FOR(i,0,x){
 			if (A[i] + 1 == A[x]) mn = min(mn, l[i]);
 			if (A[i] >= A[x]) mx = min(mx, l[i]);
 		}
 		FOR(i,0,x) if (B[x] >= B[i]) mn = max(mn, l[i]);
 		if (A[x] == 1) mn = 0;
 		int ismax = 1;
 		FOR(i,x+1,n) if (A[i] >= A[x]) ismax = 0;
 		if (ismax){
 			FOD(i,mx,0)	if (!v[i]){
 				v[i] = 1;
 				l[x] = i;
 				dfs(x + 1);
 				v[i] = 0;
 				if (done) return;
 			}
 		}
 		FOR(i,mn,mx) if (!v[i]){
 			v[i] = 1;
 			l[x] = i;
 			dfs(x + 1);
 			v[i] = 0;
 			if (done) return;
 		}
 	}
 }
 
 void solve(int tc){
 	printf("Case #%d: ", tc);
 	scanf("%d", &n);
 	FOR(i,0,n) scanf("%d", &A[i]);
 	FOR(i,0,n) scanf("%d", &B[i]);
 	CLR(v, 0);
 	done = 0;
 	dfs(0);
 	FOR(i,0,n) printf("%d%c", l[i] + 1, i == n - 1 ? '\n' : ' ');
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
