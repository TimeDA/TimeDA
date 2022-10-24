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
 
 
 struct dat{
 	int x;
 	string s;
 };
 
 int n, a0, a1, a2, t, b[9];
 dat a[5005], c[3][5005];
 
 inline int f(int x, int y){
 	if (abs(x-y) == 1) return max(x, y);
 	return 0;
 }
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
 	RI(n), RI(a0), RI(a1), RI(a2);
 	t = 0;
 	FOR(i,0,a0) a[t++] = (dat){0, (string)"R"};
 	FOR(i,0,a1) a[t++] = (dat){1, (string)"P"};
 	FOR(i,0,a2) a[t++] = (dat){2, (string)"S"};
 	FOR(i,0,n){
 		CLR(b, 0);
 		FOR(j,0,t){
 			c[a[j].x][ b[a[j].x] ] = a[j];
 			b[ a[j].x ]++;
 		}
 
 		int mx = 0, o1, o2;
 		FOR(j,0,3) if (b[j] > b[mx]) mx = j;
 		o1 = (mx + 1) % 3;
 		o2 = (mx + 2) % 3;
 		if (b[o1] + b[o2] < b[mx]){
 			puts("IMPOSSIBLE");
 			goto END;
 		}
 		int eq = (b[o1] + b[o2] - b[mx]) / 2;
 		t = 0;
 
 		int i1 = b[o1], i2 = b[o2], im = b[mx];
 
 		FOR(j,0,eq){
 			i1--, i2--;
 			a[t].x = f(o1, o2);
 			if (c[o1][i1].s + c[o2][i2].s < c[o2][i2].s + c[o1][i1].s){
 				a[t].s = c[o1][i1].s + c[o2][i2].s ;
 			}
 			else a[t].s = c[o2][i2].s + c[o1][i1].s;
 			t++;
 		}
 
 		while (i1){
 			i1--, im--;
 			a[t].x = f(o1, mx);
 			if (c[o1][i1].s + c[mx][im].s < c[mx][im].s + c[o1][i1].s){
 				a[t].s = c[o1][i1].s + c[mx][im].s ;
 			}
 			else a[t].s = c[mx][im].s + c[o1][i1].s;
 			t++;
 		}
 		while (i2){
 			i2--, im--;
 			a[t].x = f(o2, mx);
 			if (c[o2][i1].s + c[mx][im].s < c[mx][im].s + c[o2][i2].s){
 				a[t].s = c[o2][i2].s + c[mx][im].s ;
 			}
 			else a[t].s = c[mx][im].s + c[o2][i2].s;
 			t++;
 		}
 	}
 
 	printf("%s\n", a[0].s.c_str());
 	END:;
 }return 0;}
