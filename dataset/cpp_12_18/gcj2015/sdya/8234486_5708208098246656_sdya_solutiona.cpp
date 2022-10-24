#include <iostream>
 #include <cstdio>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <bitset>
 #include <queue>
 #include <cstring>
 #include <string>
 #include <cmath>
 #include <ctime>
 #pragma comment (linker, "/STACK:256000000")
 
 using namespace std;
 
 const int maxN = 110;
 string s[maxN];
 int n, m;
 
 int dx[] = {-1, 0, 0, 1};
 int dy[] = { 0,-1, 1, 0};
 
 int getDir(char c) {
 	if (c == '^') {
 		return 0;
 	}
 	if (c == 'v') {
 		return 3;
 	}
 	return c == '<' ? 1 : 2;
 }
 
 bool isValid(int x, int y) {
 	return 0 <= x && x < n && 0 <= y && y < m;
 }
 
 bool checkDir(int dir, int x, int y) {
 	for (int i = 1; ; ++i) {
 		int nx = x + dx[dir] * i;
 		int ny = y + dy[dir] * i;
 		if (!isValid(nx, ny)) {
 			return false;
 		}
 		if (s[nx][ny] != '.') {
 			return true;
 		}
 	}
 }
 
 void solve(int test) {
 	cin >> n >> m;
 	for (int i = 0; i < n; ++i) {
 		cin >> s[i];
 	}
 
 	int res = 0;
 	for (int i = 0; i < n; ++i) {
 		for (int j = 0; j < m; ++j) {
 			if (s[i][j] == '.') {
 				continue;
 			}
 			int dir = getDir(s[i][j]);
 			if (checkDir(dir, i, j)) {
 				continue;
 			}
 
 			bool isOk = false;
 			for (int k = 0; k < 4; ++k) {
 				if (checkDir(k, i, j)) {
 					isOk = true;
 				}
 			}
 			if (!isOk) {
 				printf("Case #%d: IMPOSSIBLE\n", test);
 				return;
 			}
 			++res;
 		}
 	}
 	printf("Case #%d: %d\n", test, res);
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	int tests;
 	scanf("%d", &tests);
 	for (int i = 0; i < tests; ++i) {
 		solve(i + 1);
 		cerr << (i + 1) << endl;
 	}
 	cerr << "Time: " << clock() << endl;
 	return 0;
 }