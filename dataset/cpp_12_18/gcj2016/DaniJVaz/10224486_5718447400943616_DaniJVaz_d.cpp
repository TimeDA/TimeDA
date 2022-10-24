#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 bool recValidate(ll mat, int n, ll taken=0, ll arrived=0) {
 	//printf("<");
 	for (int i=0; i<n; i++) {
 		if ((arrived & (1LL << i)) > 0)
 			continue;
 
 		ll possible = (mat >> (i*n)) & (((1LL << n) - 1) ^ taken);
 		//printf("%d %I64d %I64d\n", i, possible, arrived);
 		if (possible == 0)
 			return false;
 		for (int j=0; j<n; j++) {
 			if ((possible & (1LL <<j)) > 0) {
 				if (!recValidate(mat, n, taken | (1LL << j), arrived | (1LL << i))) {
 					return false;
 				}
 			}
 		}
 	}
 	return true;
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n;
 		scanf("%d", &n);
 
 		char sMatrix[n][n+2];
 		for (int i=0; i<n; i++)
 			scanf("%s", &sMatrix[i][0]);
 
 		ll matrix = 0;
 		for (int i=n-1; i>=0; i--)
 			for (int j=n-1; j>=0; j--)
 				matrix = (matrix << 1) | (sMatrix[i][j] == '1');
 
 
 		int minCost = n*n;
 		for (ll m = 0; m < (1LL << (n*n)); m++) {
 			if ((m | matrix) != m)
 				continue;
 			//printf("%I64d ", m);
 
 			if (!recValidate(m, n))
 				continue;
 
 			int cost = 0;
 			for (int i=0; i<n*n; i++)
 				if ((m & (1LL << i)) > 0 and (matrix & (1LL << i)) == 0)
 					cost ++;
 			minCost = min(minCost, cost);
 		}
 
 		printf("Case #%d: %d\n", iC, minCost);
 	}
 	return 0;
 }