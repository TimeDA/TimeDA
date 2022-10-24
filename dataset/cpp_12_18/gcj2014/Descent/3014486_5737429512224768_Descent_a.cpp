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
 
 int n, m,a[10005];
 
 void solve(int tc){
 	scanf("%d%d", &n, &m);
 	FOR(i,0,n) scanf("%d", &a[i]);
 	sort(a, a + n);
 	int ret = 0;
 	for (int i=0, j=n-1; i<=j;){
 		if (i == j){
 			++ret;
 			break;
 		}
 		else if (a[i] + a[j] <= m) ++ret, i++, j--;
 		else ++ret, --j;
 	}
 	
 	printf("Case #%d: %d\n", tc, ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
