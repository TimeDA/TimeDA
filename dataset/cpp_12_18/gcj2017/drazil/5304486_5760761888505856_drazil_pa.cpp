#include <bits/stdc++.h>
 
 using namespace std;
 
 char arr[110][110];
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		int r, c;
 		scanf("%d%d", &r, &c);
 		for (int i = 0; i < r; ++i) {
 			scanf("%s", arr[i]);
 		}
 		for (int i = 0; i < r; ++i) {
 			for (int j = 0; j < c - 1; ++j) {
 				if (arr[i][j + 1] == '?') arr[i][j + 1] = arr[i][j];
 			}
 		}
 		for (int i = 0; i < r; ++i) {
 			for (int j = c - 1; j > 0; --j) {
 				if (arr[i][j - 1] == '?') arr[i][j - 1] = arr[i][j];
 			}
 		}
 		for (int i = r - 1; i > 0; --i) {
 			for (int j = 0; j < c; ++j) {
 				if (arr[i - 1][j] == '?') arr[i - 1][j] = arr[i][j];
 			}
 		}
 		for (int i = 0; i < r - 1; ++i) {
 			for (int j = 0; j < c; ++j) {
 				if (arr[i + 1][j] == '?') arr[i + 1][j] = arr[i][j];
 			}
 		}
 		printf("Case #%d:\n", t);
 		for (int i = 0; i < r; ++i) puts(arr[i]);
 	}
 	return 0;
 }
 
