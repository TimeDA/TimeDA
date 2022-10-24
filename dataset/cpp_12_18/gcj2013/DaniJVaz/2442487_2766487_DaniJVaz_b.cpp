#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, p;
 		scanf("%d %d", &n, &p);
 
 		ll r = 1;
 		for (int i=0; i<n; i++)
 			r *= 2;
 
 		ll pot = r / 2, tmp = p;
 		ll best = 0;
 		if (p == r)
 			best = r-1;
 		else while (tmp > pot) {
 			// Add the possibilities
 			best = (best+1)*2;
 			// Pass to the losers side in that round
 			tmp -= pot;
 			pot /= 2;
 		}
 
 		pot = r;
 		ll worse = 0;
 		while (p < pot) {
 			// Add the possibilities
 			worse = worse*2+1;
 			// Pass to the losers side in that round
 			pot /= 2;
 		}
 
 		printf("Case #%d: %I64d %I64d\n", iC, best, r-1-worse);
 	}
 	return 0;
 }