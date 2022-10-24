#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define N 2005
 using namespace std;
 
 struct dat{
 	int x, y;
 	bool operator < (dat const &T) const{return x < T.x;}
 };
 
 struct dat2{
 	int x, y, id;
 	bool operator < (dat2 const &T) const{return x < T.x;}
 };
 
 
 bool cmp(dat a, dat b){
 	return a.y > b.y;
 }
 
 struct IC{
 	int n, m;
 	dat a[N];
 	int p[N];
 	void init(){
 		n = m = 0;
 		CLR(a, 0);
 		CLR(p, 0);
 	}
 	void add(int x, int y){
 		a[m++] = (dat){x, y};
 	}
 	void add(int x){
 		p[n++] = x;
 	}
 	// preserve later
 	int solve0(){
 		if (m > n) return 0;
 		sort(p, p + n);
 		sort(a, a + m);
 		FOR(i,0,m){
 			int ok = 0;
 			FOR(j,0,n) if (p[j] >= a[i].x && p[j] <= a[i].y){
 				p[j] = -1;
 				ok = 1;
 				break;
 			}
 			if (!ok){
 				return 0;
 			}
 		}
 		
 		return 1;
 	}
 	int solve1(){
 		if (m > n) return 0;
 		sort(p, p + n);
 		reverse(p, p + n);
 		sort(a, a + m, cmp);
 
 		FOR(i,0,m){
 			int ok = 0;
 			FOR(j,0,n) if (p[j] >= a[i].x && p[j] <= a[i].y){
 				p[j] = -1;
 				ok = 1;
 				break;
 			}
 			if (!ok){
 				return 0;
 			}
 		}
 		
 		return 1;
 	}
 };
 
 struct PS{
 	int n;
 	dat2 a[N];
 	void init(){
 		n = 0;
 	}
 	void add(int x, int y, int id){
 		a[n++] = (dat2){x, y, id};
 	}
 	int solve(){
 		sort(a, a + n);
 		int ret0 = 0, ret1 = 0;
 		FOR(i,0,n){
 			if (a[i].y == 0){
 				if (a[i].id == 0){
 					if (ret1) --ret1;
 					else if (ret0) --ret0;
 				}
 				else{
 					if (ret0) --ret0;
 				}
 			}
 			else{
 				if (a[i].id == 0) ++ret0;
 				else ++ret1;
 			}
 		}
 		return ret0 + ret1;
 	}
 };
 
 int n, a[N], b[N];
 IC S[2];
 PS Q;
 
 void solve(int tc){
 	CLR(S, 0);
 	CLR(a, 0);
 	CLR(b, 0);
 
 
 	scanf("%d", &n);
 	FOR(i,0,n){
 		char s[5];
 		scanf("%s%d", s, &b[i]);
 		if (s[0] == 'E') a[i] = 1;
 		else a[i] = 0;
 	}
 	
 	FOR(i,0,n) if (!b[i]) S[a[i]].add(i);
 	FOR(i,1,2001){
 		int p = -1, pp;
 		FOR(j,0,n) if (b[j] == i){
 			if (p == -1 && !a[j]) Q.add(j, 0, i);
 			if (p == a[j]) S[p^1].add(pp + 1, j - 1);
 			else p = a[j];
 			pp = j;
 		}
 		if (p == 1) Q.add(pp, 1, i);
 	}
 	
 	printf("Case #%d: ", tc);
 	int f1 = S[0].solve0();
 	int f2 = S[1].solve1();
 	int flag = f1 + f2;
 	if (flag != 2) puts("CRIME TIME");
 	else{
 		FOR(j,0,2) FOR(i,0,S[j].n) if (S[j].p[i] != -1) Q.add(S[j].p[i], j, 0);
 		printf("%d\n", Q.solve());
 	}
 }
 
 int main(){
 	int tc;
 	scanf("%d", &tc);
 	FOE(i,1,tc) solve(i);
 	return 0;
 }
