#include <stdio.h>
 int P[1001];
 int main() {
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("B-small-attempt0.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	for (int t = 1; t <= T; t++) {
 		int sol = -1;
 		
 		int N;
 		scanf("%d", &N);
 		for (int i = 0; i < N; i++) scanf("%d", &P[i]);
 		for (int d = 1; d <= 1000; d++) {
 			int res = d;
 			for (int j = 0; j < N; j++) {
 				res += (P[j] - 1) / d;
 			}
 			if (sol == -1 || sol > res) {
 				sol = res;
 			}
 		}
 		printf("Case #%d: %d\n", t, sol);
 	}
 	return 0;
 }