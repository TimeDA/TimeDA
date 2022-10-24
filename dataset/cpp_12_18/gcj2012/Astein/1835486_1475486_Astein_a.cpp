#include <cstdio>
 #include <cstring>
 
 #include <vector>
 #include <algorithm>
 #include <string>
 #include <map>
 
 using namespace std;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn) {
 		int n;
 		scanf("%d", &n);
 		vector<int> L(n), P(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &L[i]);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &P[i]);
 		vector<int> ret;
 		for (int i = 99; i >= 0; --i) {
 			for (int j = 0; j < n; ++j) {
 				if (P[j] == i) ret.push_back(j);
 			}
 		}
 		printf("Case #%d:", cn);
 		for (int i = 0; i < n; ++i)
 			printf(" %d", ret[i]);
 		printf("\n");
 	}
 	return 0;
 }
