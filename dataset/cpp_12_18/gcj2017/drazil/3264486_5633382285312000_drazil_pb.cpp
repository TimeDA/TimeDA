#include <bits/stdc++.h>
 
 using namespace std;
 
 char arr[21];
 
 int main() {
 	int tc;
 	scanf("%d", &tc);
 	for (int t = 1; t <= tc; ++t) {
 		scanf("%s", arr);
 		int len = strlen(arr);
 		for (int k = 0; k < 20; ++k)
 			for (int i = 0; i < len - 1; ++i) {
 				if (arr[i] > arr[i + 1]) {
 					--arr[i];
 					for (int j = i + 1; j < len; ++j) arr[j] = '9';
 					break;
 				}
 			}
 		int ptr = 0;
 		while (ptr < len && arr[ptr] == '0') ++ptr;
 		printf("Case #%d: %s\n", t, arr + ptr);
 	}
 	return 0;
 }
 
