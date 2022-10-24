#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, x;
 		scanf("%d %d", &n, &x);
 		int files[n];
 		for (int i=0; i<n; i++)
 			scanf("%d", files+i);
 
 		sort(files, files+n);
 
 		int i = n-1, j = 0;
 		int c = 0;
 		for (; i>=j; i--) {
 			if (files[i] + files[j] <= x) {
 				c++;
 				j++;
 			}
 			else {
 				c++;
 			}
 		}
 
 		printf("Case #%d: %d\n", iC, c);
 	}
 	return 0;
 }