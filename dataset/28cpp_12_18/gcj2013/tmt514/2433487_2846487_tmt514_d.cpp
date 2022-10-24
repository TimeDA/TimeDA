#include <cstdio>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 #define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
 #define SZ(c) ((int)(c).size())
 
 typedef long long LL;
 int cs;
 char s[1000];
 int a[1000], m;
 double dp[1<<20];
 int n;
 void solve() {
 	scanf("%s", s);
 	n=strlen(s); m=0;
 	reverse(s, s+n);
 	for(int i=0;s[i];i++) m=m*2+(s[i]=='X');
 	memset(dp, 0, sizeof(dp));
 	
 	for(int i=(1<<n)-2;i>=m;i--) {
 		int b[20]={}, nxt[20]={}, prc[20]={};
 		for(int j=0;j<n;j++) b[j]=(i&(1<<j))? 1: 0;
 		int first=0;
 		for(first=0;first<n;first++) if(b[first]==0) break;
 		for(int j=n-1;j>=0;j--) if(b[j]==1) nxt[j]=first; else nxt[j]=(first=j);
 		for(int j=0;j<n;j++) if(nxt[j]>=j) prc[j]=(n-(nxt[j]-j));
 		else prc[j]=(n-(nxt[j]+n-j));
 		for(int j=0;j<n;j++) {
 			dp[i] = dp[i] + (prc[j]+    dp[i|(1<<nxt[j])]) / n;
 		}
 	}
 	printf("Case #%d: %.9f\n", cs, dp[m]);
 	fprintf(stderr, "Case #%d: %.9f\n", cs, dp[m]);
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	for(cs=1;cs<=T;cs++) solve();
 	return 0;
 }
