#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int findKit(int* reqs, int** packages, int n, int p, int i, int minServ, int maxServ) {
 	if (i == n) {
 		// printf("%d %d\n", minServ, maxServ);
 		return 1;
 	}
 
 	for (int j=0; j<p; j++) {
 		if (packages[i][j] < 0)
 			continue;
 
 		int minS = packages[i][j] / (1.1*reqs[i]) - 1;
 		while (110*minS*reqs[i] < 100*packages[i][j]) ++minS;
 		int maxS = packages[i][j] / (0.9*reqs[i]) + 1;
 		while (90*maxS*reqs[i] > 100*packages[i][j]) --maxS;
 		// printf("%d %d %d %d\n", minS, maxS, reqs[i], packages[i][j]);
 
 		if (minS > maxS)
 			continue;
 
 		if (minS > maxServ)
 			break;
 		if (maxS < minServ)
 			continue;
 
 		minS = max(minS, minServ);
 		maxS = min(maxS, maxServ);
 		if (findKit(reqs, packages, n, p, i+1, minS, maxS)) {
 			packages[i][j] = -1;
 			// printf(" %d %d\n", i, j);
 			return 1;
 		}
 	}
 	return 0;
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, p;
 		scanf("%d %d", &n, &p);
 
 		int reqs[n];
 		for (int i=0; i<n; i++)
 			scanf("%d", &reqs[i]);
 
 		int _packages[n*p];
 		int *packages[n];
 		for (int i=0; i<n; i++) {
 			packages[i] = &_packages[i*p];
 			for (int j=0; j<p; j++)
 				scanf("%d", &packages[i][j]);
 			sort(packages[i], packages[i]+p);
 		}
 
 		int c = 0;
 		while (findKit(reqs, packages, n, p, 0, 0, 10000000))
 			++c;
 
 		printf("Case #%d: %d\n", iC, c);
 	}
 	return 0;
 }