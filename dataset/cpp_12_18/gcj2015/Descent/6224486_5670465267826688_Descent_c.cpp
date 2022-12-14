#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <set>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 int MUL[5][5] = {
 	{0, 0, 0, 0, 0},
 	{0, 1, 2, 3, 4},
 	{0, 2, -1, 4, -3},
 	{0, 3, -4, -1, 2},
 	{0, 4, 3, -2, -1}
 };
 
 int mul(int x, int y){
 	int s = x / abs(x) * y / abs(y);
 	x = abs(x), y = abs(y);
 	return MUL[x][y] * s;
 }
 
 int n, m;
 int a[10005];
 char s[10005];
 set<int> S;
 
 void solve(int tc){
 	scanf("%d%d%s", &n, &m, s);
 	FOR(i,0,n) a[i] = s[i] - 'g';
 	int res = 0;
 	int t = 1;
 	FOR(i,0,n) t = mul(t, a[i]);
 	int w = 1, nxt = 2;
 	S.clear();
 	FOR(i,0,m){
 		FOR(j,0,n){
 			w = mul(w, a[j]);
 			if (w == nxt){
 				++nxt;
 				S.clear();
 				w = 1;
 				if (nxt == 5){
 					FOR(k,j+1,n) w = mul(w, a[k]);
 					FOR(k,i+1,m) w = mul(w, t);
 					if (w == 1) res = 1;
 					goto END;
 				}
 			}
 		}
 		if (S.find(w) != S.end()) break;
 		S.insert(w);
 	}
 
 	END:
 	printf("Case #%d: %s\n", tc, res ? "YES" : "NO");
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
