#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define RI(x) scanf("%d", &x)
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int n, a[5], b[5];
 int c[10000];
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
 	RI(n);
 	RI(a[0]); RI(b[0]);
 	RI(a[1]); RI(b[1]);
 	RI(a[2]); RI(b[2]);
 
 	if (a[0]*2 <= n && a[1]*2 <= n && a[2]*2 <= n){
 		int p = -1;
 		FOR(i,0,n){
 			int mx = -1, idx;
 			FOR(j,0,3) if (j != p){
 				if (a[j] > mx || (a[j] == mx && j == c[0])){
 					mx = a[j];
 					idx = j;
 				}
 			}
 	
 				c[i] = idx;
 				printf("%c", "RYB"[idx]);    --a[idx]; p=idx;
 
 		}
 		puts("");
 		
 	}
 	else puts("IMPOSSIBLE");
 
 
 }return 0;}
