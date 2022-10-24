#include <iostream>
 #include <string>
 #include <cstring>
 #include <algorithm>
 #include <cstdio>
 #include <set>
 #include <map>
 #include <vector>
 
 using namespace std;
 
 int check(int x, int a, int b) {
 	set <int> num;
 	vector <int> d;
 	int buf = x;
 	while (buf > 0) {
 		d.push_back(buf % 10);
 		buf /= 10;
 	}
 	reverse(d.begin(), d.end());
 	int result = 0;
 	for (int i = 1; i < d.size(); ++i) {
 		rotate(d.begin(), d.begin() + 1, d.end());
 		int y = 0;
 		for (int j = 0; j < d.size(); ++j) {
 			y *= 10;
 			y += d[j];
 		}
 		if (y > x && y <= b && d[0] != 0) {
 			num.insert(y);
 		}
 	}
 	return num.size();
 }
 
 int solve(int a, int b) {
 	int res = 0;
 	for (int i = a; i <=b; ++i) {
 		res += check(i, a, b);
 	}
 	return res;
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	int t;
 	scanf("%d", &t);
 	for (int tests = 1; tests <= t; ++tests) {
 		printf("Case #%d: ", tests);
 		int a, b;
 		scanf("%d%d", &a, &b);
 		printf("%d\n", solve(a, b));
 	}
 
 	return 0;
 }