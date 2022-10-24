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
 
 int n, ret; char s[1000];
 
 int main(){	int tc;	scanf("%d", &tc); FOE(TC,1,tc){ printf("Case #%d: ", TC);
 	scanf("%s", s), n = strlen(s);
 	ret = 0;
 	FOD(i,n,0) if (s[i] == '-'){
 		FOE(j,0,i) s[j] = (s[j] == '-' ? '+' : '-');
 		++ret;
 	}
 	printf("%d\n", ret);
 }	return 0;	}
