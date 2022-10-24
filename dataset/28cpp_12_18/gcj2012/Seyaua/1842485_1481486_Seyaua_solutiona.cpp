#include <iostream>
 #include <cstdio>
 #include <string>
 #include <cstring>
 #include <set>
 #include <map>
 #include <vector>
 #include <algorithm>
 #include <cmath>
 #include <queue>
 #include <bitset>
 
 using namespace std;
 
 int n;
 int d[11000], l[11000];
 int mx[11000];
 int dist;
 
 void solve(int testcase) {
 	printf("Case #%d: ", testcase);
 	
 	cin >> n;
 	for (int i = 0; i < n; ++i) {
 		cin >> d[i] >> l[i];
 	}
 	cin >> dist;
 
 	memset(mx, 0, sizeof(mx));
 
 	mx[0] = d[0];
 	for (int i = 0; i < n; ++i) {
 		for (int j = i + 1; j < n; ++j) {
 			if (d[i] + mx[i] >= d[j]) {
 				mx[j] = max(mx[j], min(l[j], d[j] - d[i]));
 			} else {
 				break;
 			}
 		}
 	}
 	for (int i = 0; i < n; ++i) {
 		if (d[i] + mx[i] >= dist) {
 			printf("YES\n");
 			return;
 		}
 	}
 	printf("NO\n");
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	cin >> tests;
 
 	for (int t = 1; t <= tests; ++t) {
 		solve(t);
 	}
 
 	return 0;
 }