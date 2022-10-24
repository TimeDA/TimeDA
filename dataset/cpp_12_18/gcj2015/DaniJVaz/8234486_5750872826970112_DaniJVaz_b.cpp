#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 typedef long double ld;
 
 using namespace std;
 
 double abs(double l) {
 	if (l<0)
 		return -l;
 	return l;
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n;
 		double vol, temp;
 		scanf("%d %lf %lf", &n, &vol, &temp);
 		//printf("%d %lf %lf\n", n, vol, temp);
 
 		double rates[n];
 		double temps[n];
 		for (int i=0; i<n; i++) {
 			scanf("%lf %lf", &rates[i], &temps[i]);
 		}
 
 		ld minTime = 0;
 		if (n == 1) {
 			if (abs(temps[0]-temp) >= 1E-14)
 				minTime = -1;
 			else 
 				minTime = vol / rates[0];
 		}
 		else if (n == 2) {
 			if ((temps[0] < temp and temps[1] < temp) or (temps[0] > temp and temps[1] > temp)) {
 				minTime = -1;
 			}
 			else if (temps[0] == temps[1]) {
 				minTime = vol / (rates[0]+rates[1]);
 			}
 			else {
 				ld t1 = ld(vol)*(temp-temps[1]) / (rates[0]*(temps[0]-temps[1]));
 				ld t2 = ld(vol)*(temp-temps[0]) / (rates[1]*(temps[1]-temps[0]));
 				minTime = max(t1, t2);
 			}
 		}
 
 		printf("Case #%d: ", iC);
 		if (minTime < 0)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%.8lf\n", (double)minTime);
 	}
 	return 0;
 }