#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 double recExplore(int n, int k, double * probs, double * probYes, int taken = 0, int i=0) {
 	if (taken == k)
 		return probYes[k/2];
 
 	if (i == n)
 		return 0;
 
 	double prob = recExplore(n, k, probs, probYes, taken, i+1);
 
 	double probYes2[k];
 	probYes2[0] = probYes[0] * (1-probs[i]);
 	for (int j=0; j<k; j++)
 		probYes2[j] = probYes[j-1]*probs[i] + probYes[j]*(1-probs[i]);
 	double prob2 = recExplore(n, k, probs, probYes2, taken+1, i+1);
 	return max(prob, prob2);
 	/*
 	if (takenN == k) {
 		double chosen[k];
 		int l=0;
 		for (int i=0; i<n; i++) {
 			if ((takenMask & (1LL << i)) > 0)
 				chosen[l++] = probs[i];
 		}
 
 		if (takenMask == 0)
 			return 0;
 
 		/ *printf("%x\n", takenMask);
 		for (int j=0; j<k; j++)
 			printf("%f ", chosen[j]);
 		printf("%x\n", takenMask);* /
 
 		double prob = 0;
 		for (int m = 0; m < (1LL << k); m++ ) {
 			double tmp = 1;
 			int res = 0;
 			for (int j=0; j<k; j++) {
 				if ((m & (1LL << j)) > 0) {
 					tmp *= chosen[j];
 					res += 1;
 				}
 				else {
 					tmp *= (1-chosen[j]);
 					res -= 1;
 				}
 			}
 
 			if (res == 0)
 				prob += tmp;
 		}
 		return prob;
 	}
 
 	double bestProb = 0;
 	for (int i=0; i<n; i++) {
 		if ((takenMask & (1LL << i)) == 0) {
 			bestProb = max(bestProb, recExplore(n, k, probs, takenMask | (1LL << i), takenN+1));
 		}
 	}
 	return bestProb;*/
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, k;
 		scanf("%d %d", &n, &k);
 
 		double probs[n];
 		for (int i=0; i<n; i++) {
 			float tmp;
 			scanf("%f", &tmp);
 			probs[i] = tmp;
 		}
 
 		double probYes[k];
 		fill(probYes, probYes+k, 0);
 		probYes[0] = 1;
 
 		double bestProb = recExplore(n, k, probs, probYes);
 		printf("Case #%d: %.9f\n", iC, bestProb);
 	}
 	return 0;
 }
