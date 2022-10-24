#include <bits/stdc++.h>
 
 using namespace std;
 
 char arr[1100];
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int k;
 		scanf("%s%d", arr, &k);
 		int n = strlen(arr);
 		int ans = 0;
 		for (int i = 0; i <= n - k; ++i) {
 			if (arr[i] == '-') {
 				for (int j = 0; j < k; ++j) {
 					arr[i + j] = arr[i + j] == '+' ? '-' : '+';
 				}
 				++ans;
 			}
 		}
 		bool ok = true;
 		for (int i = 0; i < n; ++i) {
 			if (arr[i] == '-') ok = false;
 		}
 		printf("Case #%d: ", t);
 		if (ok) {
 			printf("%d\n", ans);
 		} else {
 			puts("IMPOSSIBLE");
 		}
 	}
 	return 0;
 }
 
