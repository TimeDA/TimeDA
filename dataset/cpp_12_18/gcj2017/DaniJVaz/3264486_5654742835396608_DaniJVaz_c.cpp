#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		ll n, k;
 		scanf("%I64d %I64d", &n, &k);
 
 		// After 1+2+...+2^i arrive, there's exactly two sizes of rows of empty stalls (va and vb)
 		//where na and nb are the number of them. Furthermore, na = nb+1
 		ll p = 1;
 		ll va = n, na = 1, vb = n-1, nb = 0;
 		while (k>p) {
 			k -= p;
 			p *= 2;
 
 			// va spots break into va/2 + (va-1)/2 (rounded down) since we remove 1
 			ll nva = va/2, nvb = (vb-1)/2;
 			ll nna = na, nnb = nb;
 
 			if (va % 2 == 1) // Odd, so divides into two equal slots
 				nna += na;
 			else			 // Even, so divides into two different slots (one for nna, one for nnb)
 				nnb += na;
 
 
 			if (vb % 2 == 1) // Odd, so divides into two equal slots
 				nnb += nb;
 			else			 // Even, so divides into two different slots (one for nna, one for nnb)
 				nna += nb;
 
 			va = nva;
 			na = nna;
 			vb = nvb;
 			nb = nnb;
 		}
 
 		ll slots = va;
 		if (k > na)
 			slots = vb;
 
 		printf("Case #%d: %I64d %I64d\n", iC, slots/2, (slots-1)/2);
 	}
 	return 0;
 }