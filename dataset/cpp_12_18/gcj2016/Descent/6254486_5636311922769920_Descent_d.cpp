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
 
 int n, m, ava; 
 
 int main(){	int tc;	scanf("%d", &tc); FOE(TC,1,tc){ printf("Case #%d: ", TC);
 	scanf("%d%d%d", &n, &m, &ava);
 	if (ava * m < n){ puts("IMPOSSIBLE");	continue; }
 	LLD off = 0, p = 1;
 	FOR(i,0,m-1) p = p * (LLD)n;
 	FOR(i,0,m) off += (LLD)i * p, p = p / (LLD)n;
 	p = 1;
 	FOR(i,0,m-1) p *= (LLD)n;
 	//for (int i=0; i<n; i+=m) printf("%lld ", off+1), off += p * (LLD)m;
 	//puts("");
 	FOR(i,0,n) printf(" %d", i+1); puts("");
 }	return 0;	}
