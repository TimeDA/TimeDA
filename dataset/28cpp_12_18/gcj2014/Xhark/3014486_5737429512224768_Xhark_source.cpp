#include <stdio.h>
 #include <algorithm>
 using namespace std;
 
 int dat[10001];
 int main() {
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 	int T, N, X;
 	scanf("%d", &T);
 	for (int t = 1; t <= T; t++) {
 		int sol = 0;
 		scanf("%d %d", &N, &X);
 		for (int i = 0; i < N; i++) scanf("%d", &dat[i]);
 		sort(dat, dat + N);
 		int s = 0, e = N - 1;
 
 		while (s <= e) {
 			if (dat[s] + dat[e] <= X) {
 				s++; e--;
 			}
 			else {
 				e--;
 			}
 			sol++;
 		}
 		printf("Case #%d: %d\n", t, sol);
 	}
 	return 0;
 }