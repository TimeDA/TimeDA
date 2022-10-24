#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		char number[100];
 		scanf("%s", number);
 		int n = strlen(number);
 
 		int tidyPrefSize = 1;
 		for (int i=1; i<n; i++) {
 			if (number[i] >= number[i-1])
 				++tidyPrefSize;
 			else
 				break;
 		}
 
 		if (tidyPrefSize != n) {
 			for (int j=tidyPrefSize-1; j>=0; j--) {
 				number[j]--;
 				// If after decreasing this digit, the prefix is still tidy, just add 9's
 				if (j == 0 or number[j] >= number[j-1]) { 
 					for (int l=j+1; l<n; l++)
 						number[l] = '9';
 					break;
 				}
 			}
 		}
 
 		// Remove leading 0s
 		char * p = number;
 		while (*p == '0' and *(p+1) != '\0')
 			p++;
 
 
 		printf("Case #%d: %s\n", iC, p);
 	}
 	return 0;
 }