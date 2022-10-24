#include <iostream>
 #include <cstdio>
 #include <vector>
 #include <cstdio>
 #include <algorithm>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <bitset>
 #include <cmath>
 #include <ctime>
 #pragma comment (linker, "/STACK:256000000")
 
 using namespace std;
 
 void read_data(int test) {
 }
 
 const int maxN = 110000;
 int n, a[maxN], used[maxN];
 int x;
 
 void solve(int test) {
 	cin >> n >> x;
 	for (int i = 0; i < n; ++i) {
 		cin >> a[i];
 		used[i] = false;
 	}
 	sort(a, a + n);
 	int res = 0;
 	for (int i = n - 1; i >= 0; --i) {
 		if (used[i]) {
 			continue;
 		}
 
 		++res;
 		for (int j = i - 1; j >= 0; --j) {
 			if (!used[j] && x - a[i] >= a[j]) {
 				used[j] = true;
 				break;
 			}
 		}
 	}
 	printf("Case #%d: %d\n", test, res);
 }
 
 int main(int argc, char* argv[]) {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	//freopen("input.txt", "r", stdin);
 	//freopen(argv[3], "w", stdout);
 
 	int left_bound, right_bound;
 	//sscanf(argv[1], "%d", &left_bound);
 	//sscanf(argv[2], "%d", &right_bound);
 
 	int tests;
 	scanf("%d", &tests);
 	left_bound = 1;
 	right_bound = tests;
 	for (int i = 1; i <= tests; ++i) {
 		if (i >= left_bound && i <= right_bound) {
 			solve(i);
 			cerr << i << ": " << clock() << endl;
 		} else {
 			read_data(i);
 		}
 	}
 	return 0;
 }