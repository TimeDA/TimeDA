#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define N 10005
 using namespace std;
 
 int n, ok, tc, D;
 int d[N], l[N], v[N];
 
 int main(){
 	scanf("%*d");
 	while (scanf("%d", &n) != EOF){
 		FOR(i,0,n) scanf("%d%d", &d[i], &l[i]), v[i] = 0;
 		scanf("%d", &D);
 		
 		v[0] = d[0];
 		ok = 0;
 		
 		FOR(i,0,n){
 			v[i] = min(v[i], l[i]);
 			FOR(j,0,n)
 			if (abs(d[i] - d[j]) <= v[i]) v[j] = max(v[j], abs(d[i] - d[j]));
 
 			if (d[i] + v[i] >= D) ok = 1;
 		}
 		printf("Case #%d: %s\n", ++tc, ok ? "YES" : "NO");
 	}
 	return 0;
 }
