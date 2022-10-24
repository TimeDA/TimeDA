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
 
 int n, cnt, v[99];
 
 void upd(int n){
 	while (n > 0){		v[n%10] = 1, n /= 10;	}
 	cnt = 0;
 	FOE(i,0,10) cnt += v[i];
 }
 
 int main(){	int tc;	scanf("%d", &tc); FOE(TC,1,tc){ printf("Case #%d: ", TC);
 	scanf("%d", &n);
 	if (n == 0) {puts("INSOMNIA"); continue;}
 	CLR(v, 0);
 	upd(n);
 	int m = n;
 	while (cnt < 10){
 		m += n;
 		upd(m);
 	}
 	printf("%d\n", m);
 }	return 0;	}
