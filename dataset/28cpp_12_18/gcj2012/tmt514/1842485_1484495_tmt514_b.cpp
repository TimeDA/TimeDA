#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #define SZ(x) ((int)(x).size())
 #define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
 using namespace std;
 
 int n, W, L;
 int r[10005], rr[10005];
 int srt[10005];
 int x[10005], y[10005];
 struct Rect{
 	int l, r, u, d;
 	Rect(){}
 	Rect(int _l, int _r, int _d, int _u) {
 		l=_l; r=_r; u=_u; d=_d;
 	}
 } a[10005];
 int na;
 
 bool cmp(int p, int q) {
 	return r[p] > r[q];
 }
 void solve() {
 	static int cs=0;
 	printf("Case #%d:", ++cs);
 	scanf("%d%d%d", &n, &W, &L);
 	for(int i=0;i<n;i++) scanf("%d", &r[i]);
 	for(int i=0;i<n;i++) srt[i] = i;
 	sort(srt, srt+n, cmp);
 	for(int i=0;i<n;i++) rr[i] = r[srt[i]];
 	na = 1;
 	a[0] = Rect(-100000, W+100000, -100000, L+100000);
 	for(int i=0;i<n;i++) {
 		int found = 0;
 		for(int j=0;j<na && !found;j++) {
 			if (a[j].l+rr[i]<=W && a[j].d+rr[i]<=L && a[j].r-a[j].l >= 2*rr[i] && a[j].u-a[j].d >= 2*rr[i]) {
 				x[srt[i]] = max(0, a[j].l + rr[i]);
 				y[srt[i]] = max(0, a[j].d + rr[i]);
 				int mlr = max(0, a[j].l + rr[i])+rr[i];
 				int mdu = max(0, a[j].d + rr[i])+rr[i];
 				if(a[j].r-a[j].l < a[j].u-a[j].d) {
 					a[na] = Rect(mlr, a[j].r, a[j].d, mdu);
 					na++;
 					a[j] = Rect(a[j].l, a[j].r, mdu, a[j].u);
 				} else {
 					a[na] = Rect(mlr, a[j].r, a[j].d, a[j].u);
 					na++;
 					a[j] = Rect(a[j].l, mlr, mdu, a[j].u);
 				}
 				found = 1;
 				break;
 			}
 		}
 		if(!found) fprintf(stderr,"QQ\n");
 	}
 
 	for(int i=0;i<n;i++) {
 		if(x[i]<0 || y[i]<0 || x[i]>=W || y[i]>=L) fprintf(stderr, "QQ!\n");
 		printf(" %d %d", x[i], y[i]);
 	}
 	puts("");
 	return;
 }
 
 int main(void) {
 	int T;
 	scanf("%d", &T);
 	while(T--) solve();
 	return 0;
 }
 
