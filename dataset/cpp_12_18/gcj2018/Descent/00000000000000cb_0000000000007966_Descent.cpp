#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define RI(x) scanf("%d", &x)
#define PB push_back
using namespace std;

LLD func(char s[]){
	LLD S = 0, t = 1;
	for (int i=0; s[i]; i++){
		if (s[i] == 'S') S += t;
		else t <<= 1;
	}
	return S;
}

int n, m, cnt;
char s[333];

int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
	RI(m); scanf("%s", s);
	n = strlen(s);
	cnt = 0;
	while (func(s) > (LLD)m){
		FOD(i,n-1,0) if (s[i] == 'C' && s[i+1] == 'S'){
			swap(s[i], s[i+1]);
			++cnt;
			goto NEXT;
		}
		puts("IMPOSSIBLE");
		goto DONE;
		NEXT:;
	}
	printf("%d\n", cnt);
	DONE:;
}return 0;}