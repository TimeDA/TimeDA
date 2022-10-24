#include <stdio.h>
 #define MX 100000000
 int d[2001], h[2001];
 bool pos;
 void solve(int s,int e,int l) {
 	if (!pos) return;
 	if (s == e) return;
 	if (s > e || !(s<d[s] && d[s]<=e)) {
 		pos = false; return ;
 	}
 	solve(d[s], e, l);
 	h[s] = h[e] - (e - s) * l;
 	solve(s+1, d[s], l+1);
 }
 int main(){
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C-small-attempt0.out","w",stdout);
 	int T;
 	scanf("%d",&T);
 	while(T-->0){
 		int n;
 		scanf("%d",&n);
 		int i;
 		for(i=1;i<n;i++){
 			scanf("%d", &d[i]);
 		}
 		h[n] = MX;
 		pos = true;
 		solve(1, n, 0);
 
 		static int cs = 1;
 		printf("Case #%d: ", cs++);
 		if (!pos) printf("Impossible\n");
 		else {
 			for(i=1;i<=n;i++){
 				if (i != 1) printf(" ");
 				printf("%d",h[i]);
 			}
 			printf("\n");
 		}
 	}
 	return 0;
 }