#include <iostream>
 #include <cstdio>
 #include <vector>
 #include <algorithm>
 #include <bitset>
 #include <cstring>
 #include <string>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <ctime>
 #pragma comment (linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 50000;
 int d[maxN], l[maxN];
 int n;
 int finish;
 int answer;
 
 int p[maxN];
 
 void solve(int test) {
 	scanf("%d", &n);
 	for (int i = 1; i <= n; ++i) {
 		cin >> d[i] >> l[i];
 	}
 	
 	cin >> finish;
 	for (int i = 1; i <= n; ++i) {
 		p[i] = d[i];
 	}
 
 	p[1] = d[1] + d[1];
 	for (int i = 1; i <= n; ++i) {
 		for (int j = i + 1; j <= n; ++j) {
 			if (p[i] >= d[j]) {
 				int add = min(d[j] - d[i], l[j]);
 				p[j] = max(p[j], d[j] + add);
 			}
 		}
 	}
 	bool good = false;
 	for (int i = 1; i <= n; ++i) {
 		if (p[i] >= finish) {
 			good = true;
 		}
 	}
 
 	if (good) {
 		printf("Case #%d: YES\n", test);
 	} else {
 		printf("Case #%d: NO\n", test);
 	}
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	scanf("%d", &tests);
 	for (int i = 0; i < tests; ++i) {
 		solve(i + 1);
 		cerr << i << endl;
 	}
 	return 0;
 }