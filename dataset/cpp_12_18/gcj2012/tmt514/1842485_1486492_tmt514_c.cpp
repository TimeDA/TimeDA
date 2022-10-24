#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #define SZ(x) ((int)(x).size())
 #define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
 using namespace std;
 
 int h[2005], r[2005];
 int maxh[2005];
 int flag=0;
 void go(int L, int R, int see) {
 	if(L>R) return;
 	//printf("L=%d, R=%d\n", L, R);
 	for(int i=L;i<=R;i++) if(r[i] > see) { flag=1; return; }
 	int last=L-1;
 	for(int i=L;i<=R;i++) if(r[i] == see) {
 		h[i] = maxh[i];
 		for(int j=last+1;j<=i;j++) {
 			maxh[j] = min(maxh[j], (h[i]*(see-i)-(i-j)*(h[see]-h[i]))/(see-i)-1);
 		}
 		go(last+1, i-1, i);
 		last = i;
 	}
 	if(last != R) { flag=1; return; }
 	return;
 }
 void solve() {
 	static int cs=0;
 	printf("Case #%d:", ++cs);
 	int n;
 	scanf("%d", &n);
 	for(int i=1;i<=n-1;i++) scanf("%d", &r[i]);
 	for(int i=1;i<=n;i++) maxh[i] = h[i] = 0;
 	h[n] = 1;
 	flag=0;
 	go(1, n-1, n);
 	if(flag) { puts(" Impossible"); return; }
 	int val = *min_element(h+1, h+n+1);
 	for(int i=1;i<=n;i++) printf(" %d", h[i] - val);
 	puts("");
 	return;
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	while(T--) solve();
 	return 0;
 }
 
