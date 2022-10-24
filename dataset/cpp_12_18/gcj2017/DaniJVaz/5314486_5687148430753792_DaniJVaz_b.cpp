#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, c, m;
 		scanf("%d %d %d", &n, &c, &m);
 
 		int countClients[c];
 		fill(countClients, countClients+c, 0);
 
 		int tickets[n];
 		fill(tickets, tickets+n, 0);
 		for (int i=0;i<m; i++) {
 			int p, b;
 			scanf("%d %d", &p, &b);
 			++ tickets[p-1];
 			++ countClients[b-1];
 		}
 
 		int minRides = 0;
 		for (int i=0; i<c; i++)
 			minRides = max(minRides, countClients[i]);
 
 		int maxRides = m;
 		int minPromotions = 0;
 
 		for (int r=minRides; r<=maxRides; r++) {
 			bool pass = true;
 			int empty = 0;
 			int promotions = 0;
 
 			for (int i=0; i<n; i++) {
 				if (tickets[i] > r + empty) {
 					pass = false;
 					break;
 				}
 				else if (tickets[i] <= r) {
 					empty += r-tickets[i];
 				}
 				else {
 					promotions += tickets[i]-r;
 				}
 			}
 
 			if (pass) {
 				maxRides = r;
 				minPromotions = promotions;
 				break;
 			}
 		}
 
 
 		printf("Case #%d: %d %d\n", iC, maxRides, minPromotions);
 	}
 	return 0;
 }