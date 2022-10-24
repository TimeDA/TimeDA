#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int r, c;
 		scanf("%d %d", &r, &c);
 
 		int count = 0;
 		if (r == 2) {
 			count = 1;
 			if (c%3 == 0)  // 221\221
 				count ++;			
 		}
 		else if (r==3) {
 			count = 2; // 2\3\3 3\3\2
 			if (c%4 == 0)
 				count ++; //2122\2121\2221
 		}
 		else if (r==4) {
 			count = 1;
 			if (c%3 == 0)  // 221\221
 				count +=2;
 		}
 		else if (r == 5) {
 			count = 1;
 			if (c%4 == 0)
 				count +=2; //2122\2121\2221
 		}
 		else if (r == 6) {
 			count = 2;
 			if (c%3 == 0)  // 221\221
 				count += 1;
 		}
 		printf("Case #%d: %d\n", iC, count);
 	}
 	return 0;
 }