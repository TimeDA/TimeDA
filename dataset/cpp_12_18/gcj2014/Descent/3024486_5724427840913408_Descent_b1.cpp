#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <map>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 struct dat{
 	int v[4];
 	bool operator < (dat const &T) const{
 		return lexicographical_compare(v, v+4, T.v, T.v+4);
 	};
 };
 
 map<dat, int> S;
 int p, q, n, a[10], cost[10];
 
 int dfs(int a[]){
 	dat t;
 	FOR(i,0,4) t.v[i] = a[i];
 	if (S.find(t) != S.end()) return S[t];
 	
 	int b[4], mx = 0;
 	
 	FOR(i,0,5) if (a[i] > 0){
 		FOR(j,0,4) b[j] = a[j];
 		b[i] -= p;
 		int yo = 0;
 		if (b[i] < 1) yo += cost[i], b[i] = 0;
 		FOR(j,0,4) if (b[j] > 0){
 			b[j] = max(0, b[j] - q);
 			break;
 		}
 		mx = max(mx, yo + dfs(b));
 	}
 	FOR(i,0,4) b[i] = a[i];
 	FOR(i,0,4) if (b[i] > 0){
 		b[i] = max(0, b[i] - q);
 		mx = max(mx, dfs(b));
 		break;
 	}
 	
 	S[t] = mx;
 	return mx;
 }
 
 
 void solve(int tc){
 	scanf("%d%d%d", &p, &q, &n);
 	CLR(cost, 0);
 	CLR(a, 0);
 	S.clear();
 	FOR(i,0,n) scanf("%d%d", &a[i], &cost[i]);
 	printf("Case #%d: %d\n", tc, dfs(a));
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
