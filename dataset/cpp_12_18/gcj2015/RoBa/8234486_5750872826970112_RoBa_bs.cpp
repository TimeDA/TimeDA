#include <cstdio>
 #include <algorithm>
 using namespace std;
 
 const int MAXN = 110;
 const double eps = 1e-10;
 double V, X;
 double R[MAXN], C[MAXN];
 int N;
 
 int main() {
 	int T;
 	scanf("%d",&T);
 	for (int ca = 1 ; ca <= T ; ++ca) {
 		scanf("%d%lf%lf",&N,&V,&X);
 		for (int i = 0 ; i < N ; ++i) {
 			scanf("%lf%lf",&R[i],&C[i]);
 		}
 		printf("Case #%d: ", ca);
 		if (N == 1) {
 			if (C[0] != X) {
 				printf("IMPOSSIBLE\n");
 				continue;
 			}
 			printf("%.10lf\n", V / R[0]);
 		} else if (N == 2) {
 			if (C[0] == C[1]) {
 				if (C[0] != X) {
 					printf("IMPOSSIBLE\n");
 					continue;
 				} else {
 					printf("%.10lf\n", V / (R[0] + R[1]));
 				}
 			} else {
 				if (max(C[0], C[1]) < X || min(C[0], C[1]) > X) {
 					printf("IMPOSSIBLE\n");
 					continue;
 				} 
 				if (C[0] == X) {
 					printf("%.10lf\n", V / R[0]);
 					continue;
 				} else if (C[1] == X) {
 					printf("%.10lf\n", V / R[1]);
 					continue;
 				} else {
 
 				double v0 = (V * X - V * C[1]) / (C[0] - C[1]);
 				double v1 = (V * C[0] - V * X) / (C[0] - C[1]); 
 					printf("%.10lf\n", max(v0 / R[0], v1 / R[1]));
 				}
 			}
 		} else {
 			printf("oops\n");
 		}
 	}
 	return 0;
 }