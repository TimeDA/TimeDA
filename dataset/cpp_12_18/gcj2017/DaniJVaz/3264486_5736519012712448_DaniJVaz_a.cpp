#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 void flipK(char * pancakes, int k) {
 	for (int j=0; j<k; j++)
 		pancakes[j] = (pancakes[j]=='-')?'+':'-';
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		char pancakes[2000];
 		int k;
 
 		scanf("%s %d", pancakes, &k);
 		int n = strlen(pancakes);
 
 		int c = 0; 
 		for (int i=0; i<=n-k; i++) {
 			if (pancakes[i] == '-') {
 				flipK(pancakes+i, k);
 				++c;
 			}
 		}
 
 		for (int i=0; i<n; i++)
 			if (pancakes[i] == '-')
 				c = -1;
 
 		printf("Case #%d: ", iC);
 		if (c == -1)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%d\n", c);
 	}
 	return 0;
 }