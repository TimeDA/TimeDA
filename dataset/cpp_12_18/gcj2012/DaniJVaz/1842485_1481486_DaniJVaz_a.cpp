#include <cstdio>
 
 /*
  * Simple dynamic programming
  */
 
 inline int max(int a, int b) {
 	if (a >= b)
 		return a;
 	else
 		return b;
 }
 
 inline int min(int a, int b) {
 	if (a <= b)
 		return a;
 	else
 		return b;
 }
 
 int main() {
 	int iC, nC;
 	scanf("%d", &nC);
 	for (iC = 1; iC <= nC; iC++) {
 		int n, dist;
 		scanf("%d", &n);
 
 		int vineDist[n];
 		int vineLen[n];
 		int maxSwing[n];
 
 		for (int i=0; i<n; i++) {
 			scanf("%d %d", vineDist + i, vineLen + i);
 			maxSwing[i] = -1;
 		}
 
 		scanf("%d", &dist);
 
 		bool res = false;
 		if (vineLen[0] >= vineDist[0]) { // Able to grab first vine
 			maxSwing[0] = vineDist[0];
 			for (int i=0; i<n; i++) {
 				if (vineDist[i] + maxSwing[i] >= dist) {
 					res = true;
 					break;
 				}
 
 				for (int j=i+1; j<n; j++) {
 					if (vineDist[j] > vineDist[i] + maxSwing[i])
 						break;
 
 					maxSwing[j] = max(maxSwing[j], min(vineDist[j]-vineDist[i], vineLen[j]));
 				}
 			}
 		}
 
 		if (res)
 			printf("Case #%d: YES\n", iC);
 		else
 			printf("Case #%d: NO\n", iC);
 	}
 	return 0;
 }
