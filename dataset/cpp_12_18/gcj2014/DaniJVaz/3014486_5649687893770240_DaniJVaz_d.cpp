#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <string>
 
 typedef long long ll;
 
 using namespace std;
 
 int calculateLen(int assign[], string * strings, int m, int n);
 
 bool nextAssign(int assign[], int m, int n) {
 	for (int i=0; i<m; i++) {
 		assign[i]++;
 		if (assign[i] < n)
 			return true;
 		else
 			assign[i] = 0;
 	}
 	return false;
 }
 
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, m;
 		scanf("%d %d", &m, &n);
 
 		string strings[m];
 		char t[101];
 		for (int i=0; i<m; i++) {
 			scanf("%s", t);
 			strings[i] = t;
 		}
 		sort(strings, strings+m);
 		int assign[m];
 		fill(assign, assign + m, 0);
 
 		int maxLen = 0;
 		int maxCount = 0;
 		do {
 			int len = calculateLen(assign, strings, m, n);
 			/*for (int i = 0; i<m; i++)
 				printf("%d ", assign[i]);
 			printf("%d\n", len);*/
 			if (len == maxLen)
 				maxCount++;
 			else if (len > maxLen) {
 				maxCount = 1;
 				maxLen = len;
 			}
 
 		} while (nextAssign(assign, m, n));
 
 		printf("Case #%d: %d %d\n", iC, maxLen, maxCount);
 	}
 	return 0;
 }
 
 int calculateLen(int assign[], string * strings, int m, int n) {
 	int totalLen = 0;
 	for (int i=0; i<n; i++) {
 		totalLen++;
 		int prev = -1;
 		int prevlen;
 		for (int j=0; j<m; j++) {
 			if (assign[j] != i)
 				continue;
 			int len = strings[j].length();
 			if (prev == -1) {
 				totalLen += len;
 			}
 			else {
 				int k=0;
 				for (; k<len && k<prevlen; k++)
 					if (strings[j][k] != strings[prev][k])
 						break;
 				totalLen += len-k;
 			}
 			prevlen = len;
 			prev = j;
 		}
 		if (prev == -1)
 			return 0;
 	}
 	return totalLen;
 }