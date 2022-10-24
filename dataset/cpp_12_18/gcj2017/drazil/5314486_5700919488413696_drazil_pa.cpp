#include <bits/stdc++.h>
 
 using namespace std;
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int n, p;
 		scanf("%d%d", &n, &p);
 		int arr[20] = {0};
 		for (int i = 0; i < n; ++i) {
 			int val;
 			scanf("%d", &val);
 			++arr[val % p];
 		}
 		int ans = arr[0] + 1;
 		if (arr[3] > 0) {
 			// p == 4
 			int m = min(arr[1], arr[3]);
 			arr[3] -= m;
 			arr[1] -= m;
 			ans += m;
 			m = arr[3] / p;
 			arr[3] -= m * p;
 			ans += m;
 		}
 		if (arr[2] > 0) {
 			if (p == 3) {
 				int m = min(arr[1], arr[2]);
 				arr[1] -= m;
 				arr[2] -= m;
 				ans += m;
 			} else {
 				// p == 4
 				int m = arr[2] / 2;
 				arr[2] -= m * 2;
 				ans += m;
 				m = min(arr[2], arr[1] / 2);
 				arr[2] -= m;
 				arr[1] -= m * 2;
 				ans += m;
 			}
 			int m = arr[2] / p;
 			arr[2] -= m * p;
 			ans += m;
 		}
 		if (arr[1] > 0) {
 			int m = arr[1] / p;
 			arr[1] -= m * p;
 			ans += m;
 		}
 		if (arr[1] + arr[2] + arr[3] == 0) --ans;
 		printf("Case #%d: %d\n", t, ans);
 	}
 	return 0;
 }
 
