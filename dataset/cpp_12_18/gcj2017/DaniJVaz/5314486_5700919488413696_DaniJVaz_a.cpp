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
 		
 		int modpcount[p];
 		fill(modpcount, modpcount+p, 0);
 
 		for (int i=0; i<n; i++) {
 			int t;
 			scanf("%d", &t);
 			++ modpcount[t%p];
 		}
 
 		int res = 0;
 		if (p == 2) {
 			res = modpcount[0] + (modpcount[1]+1)/2;
 		}
 		else if (p == 3) {
 			res += modpcount[0];
 			int m = min(modpcount[1], modpcount[2]);
 			res += m;
 			modpcount[1] -= m;
 			modpcount[2] -= m;
 			res += (modpcount[1]+2)/3 + (modpcount[2]+2)/3; // at this point only one will be nonzero
 		}
 		else if (p == 4) {
 
 		}
 
 
 
 		printf("Case #%d: %d\n", iC, res);
 	}
 	return 0;
 }