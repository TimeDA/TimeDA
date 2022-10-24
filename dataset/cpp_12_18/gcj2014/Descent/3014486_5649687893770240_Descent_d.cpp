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
 
 
 struct node{
 	int p[26];
 	void init(){memset(this, 0, sizeof(node));}
 }   T[1000];
 
 int n, m, mx, way, nd;
 int a[1005];
 char s[1005][105];
 
 void add(char s[]){
 	int x = 0, c;
 	for (int i=0; s[i]; i++){
 		c = s[i] - 'A';
 		if (!T[x].p[c]) T[x].p[c] = nd, T[nd++].init();
 		x = T[x].p[c];
 	}
 }
 
 void dfs(int x){
 	if (x == n){
 		int sum = 0;
 		FOR(i,0,m){
 			nd = 1;
 			T[0].init();
 			FOR(j,0,n) if (a[j] == i) add(s[j]);
 			if (nd > 1) sum += nd;
 		}
 		if (sum > mx) mx = sum, way = 1;
 		else if (sum == mx) way++;
 	}
 	else{
 		FOR(i,0,m) a[x] = i, dfs(x + 1);
 	}
 }
 
 void solve(int tc){
 	scanf("%d%d", &n, &m);
 	FOR(i,0,n) scanf("%s", s[i]);
 	mx = -1;
 	way = 0;
 	dfs(0);
 	printf("Case #%d: %d %d\n", tc, mx, way);
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
