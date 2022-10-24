#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n;
 		scanf("%d", &n);
 
 		int list[n];
 		for (int i=0; i<n; i++)
 			scanf("%d", list + i);
 
 		int l = 0, u = n-1;
 		int minVal, minInd;
 		int swaps = 0; 
 		while (l < u) {
 			minVal = list[l];
 			minInd = l;
 			for (int i=l; i<=u; i++)
 				if (list[i] < minVal)
 					minVal = list[minInd = i];
 
 			if (minInd-l <= u-minInd) {
 				swaps += minInd-l;
 				for (int i=minInd; i>l; i--)
 					swap(list[i], list[i-1]);
 				l++;
 			}
 			else {
 				swaps += u-minInd;
 				for (int i=minInd; i<u; i++)
 					swap(list[i], list[i+1]);
 				u--;
 			}
 		}
 
 		printf("Case #%d: %d\n", iC, swaps);
 	}
 	return 0;
 }