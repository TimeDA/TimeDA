#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #define SZ(x) ((int)(x).size())
 #define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
 using namespace std;
 
 int L[1005], P[1005], srt[1005];
 
 bool cmp(int x, int y) {
 	if(L[x]*P[y]!=L[y]*P[x])
 		return L[x]*P[y]<L[y]*P[x];
 	return x<y;
 }
 
 void solve() {
 	int n;
 	scanf("%d", &n);
 	for(int i=0;i<n;i++) scanf("%d", &L[i]);
 	for(int i=0;i<n;i++) scanf("%d", &P[i]);
 	for(int i=0;i<n;i++) srt[i] = i;
 	sort(srt, srt+n, cmp);
 	static int cs=0;
 	printf("Case #%d:", ++cs);
 	for(int i=0;i<n;i++) printf(" %d", srt[i]);
 	puts("");
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	while(T--) solve();
 	return 0;
 }
 
