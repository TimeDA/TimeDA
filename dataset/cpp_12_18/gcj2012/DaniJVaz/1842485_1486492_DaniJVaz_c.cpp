#include <cstdio>
 
 
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
 		int n;
 		scanf("%d", &n);
 
 		int peaks[n];
 		int heights[n];
 
 		for (int i=0; i<n-1; i++) {
 			scanf("%d", peaks + i);
 			heights[i] = 1;
 		}
 		heights[n-1] = 1;
 
 		bool res = true;
 		for (int i=0; i<n; i++) {
 			for (int j=i+1; j<n; j++) {
 				if (peaks[j] > peaks[i] and j+1 < peaks[i])
 					res = false;
 			}
 		}
 
 		if (!res) {
 			printf("Case #%d: Impossible\n", iC);
 		}
 		else {
 			bool stop = false;
 
 			while (!stop) {
 				stop = true;
 
 				for (int i=0; i<n-1; i++) {
 					for (int j=i+1; j<n; j++) {
 						if (peaks[i] - 1 == j)
 							continue;
 
 						if ((heights[peaks[i]-1] - heights[i])/double(peaks[i]-1-i) <= (heights[j] - heights[i])/double(j-i)) {
 							stop = false;
 							while ((heights[peaks[i]-1] - heights[i])/double(peaks[i]-1-i) <= (heights[j] - heights[i])/double(j-i)) {
 								heights[peaks[i]-1]++;
 							}
 						}
 					}
 				}
 			}
 
 			printf("Case #%d:", iC);
 			for (int i=0; i<n; i++)
 				printf(" %d", heights[i]);
 			printf("\n");
 		}
 	}
 	return 0;
 }
