#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, tc, t;
 int p[2005], h[20];
 
 
 int main(){
 
 	h[0] = 1000000000;
 	h[1] = h[0] - 1;
 	FOR(i,2,12){
 		h[i] = h[i-2] - (h[i-2] - h[i-1]) * 10 - 1;
 	}
 
 	scanf("%*d");
 	while (scanf("%d", &n) != EOF){
 		FOR(i,0,n-1) scanf("%d", &p[i]), p[i]--;
 		p[n-1] = n-1;
 		printf("Case #%d:", ++tc);
 		
 		// check invalid
 		int ok = 1;
 		FOR(i,0,n-1)
 		FOR(j,0,i)
 		if (p[j] > i && p[j] < p[i]) ok = 0;
 		if (!ok){
 			printf(" Impossible\n");
 			continue;
 		}
 		
 		// go
 		FOR(i,0,n){
 			t = 0;
 			int x = i;
 			while (x != n - 1) x = p[x], ++t;
 			printf(" %d", h[t]);
 		}
 		puts("");
 	}
 	return 0;
 }
