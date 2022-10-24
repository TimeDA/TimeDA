#include <iostream>
 #include <string>
 #include <cstring>
 #include <cstdio>
 #include <set>
 #include <map>
 #include <vector>
 #include <algorithm>
 #include <queue>
 #include <bitset>
 #include <cmath>
 
 using namespace std;
 
 const int maxN = 210;
 
 char a[maxN][maxN];
 int b[maxN][maxN];
 
 string dirs = "v^><";
 
 int dx[] = {1, -1, 0, 0};
 int dy[] = {0, 0, 1, -1};
 
 bool is_in(int x, int y, int r, int c) {
 	return x >= 0 && x < r && y >= 0 && y < c;
 }
 
 int fd(char c) {
 	for (int i = 0; i < 4; ++i) {
 		if (dirs[i] == c) {
 			return i;
 		}
 	}
 }
 
 void solve(int tcase) {
 	printf("Case #%d: ", tcase);
 
 	int r, c;
 	cin >> r >> c;
 
 	for (int i = 0; i < r; ++i) {
 		string cur;
 		cin >> cur;
 		for (int j = 0; j < c; ++j) {
 			a[i][j] = cur[j];
 		}
 	}
 
 	memset(b, 0, sizeof(b));
 
 	// lbound
 	for (int i = 0; i < r; ++i) {
 
 		for (int j = 0; j < c; ++j) {
 			if (a[i][j] != '.') {
 				char cc = '<';
 				int t = fd(cc);
 				b[i][j] |= (1 << t);
 				break;
 			}
 		}
 	}
 
 	// rbound
 	for (int i = 0; i < r; ++i) {
 
 		for (int j = c - 1; j >= 0; --j) {
 			if (a[i][j] != '.') {
 				char cc = '>';
 				int t = fd(cc);
 				b[i][j] |= (1 << t);
 				break;
 			}
 		}
 	}
 
 	// upbound
 	for (int i = 0; i < c; ++i) {
 		for (int j = 0; j < r; ++j) {
 			if (a[j][i] != '.') {
 				char cc = '^';
 				int t = fd(cc);
 				b[j][i] |= (1 << t);
 				break;
 			}
 		}
 	}
 
 	// downbound
 	for (int i = 0; i < c; ++i) {
 		for (int j = r - 1; j >= 0; --j) {
 			if (a[j][i] != '.') {
 				char cc = 'v';
 				int t = fd(cc);
 				b[j][i] |= (1 << t);
 				break;
 			}
 		}
 	}
 
 	int result = 0;
 	for (int i = 0; i < r; ++i) {
 		for (int j = 0; j < c; ++j) {
 			if (b[i][j] == 0) continue;
 			if (b[i][j] == 15) {
 				cout << "IMPOSSIBLE" << endl;
 				return;
 			} else {
 				char cur = a[i][j];
 				int num = fd(cur);
 				if (b[i][j] & (1 << num)) {
 					++result;
 				}
 			}
 
 		}
 	}
 	cout << result << endl;
 
 }
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("GCJ2015R2.txt", "w", stdout);
 
 	int t;
 	scanf("%d", &t);
 
 	for (int i = 1; i <= t; ++i) {
 		solve(i);
 	}
 
 
 	return 0;
 }
 
