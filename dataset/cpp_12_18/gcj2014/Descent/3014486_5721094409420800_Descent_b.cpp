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
 
 int n, a[1005], p[1005], r[1005];
 
 bool cmp(int x, int y){return a[x] > a[y];}
 
 void solve(int tc){
 	scanf("%d", &n);
 	FOR(i,0,n) scanf("%d", &a[i]), p[i] = i;
 	sort(p, p + n, cmp);
 	FOR(i,0,n) r[p[i]] = i;
 	
 	int ret = 0, x = 0, y = n - 1;
 	FOD(i,n,0){
 		FOR(j,0,n) if (r[j] == i){
 			if (j - x <= y - j){
 				FOD(k,j,x) swap(a[k], a[k+1]), swap(r[k], r[k+1]), ++ret;
 				x++;
 			}
 			else{
 				FOR(k,j,y) swap(a[k], a[k+1]), swap(r[k], r[k+1]), ++ret;
 				y--;
 			}
 			break;
 		}
 	}
 	printf("Case #%d: %d\n", tc, ret);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
