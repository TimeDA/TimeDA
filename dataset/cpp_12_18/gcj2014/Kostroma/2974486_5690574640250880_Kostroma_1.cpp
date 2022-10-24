#pragma comment (linker, "/STACK:128000000")
 #include <cstdio>
 #include <cassert>
 #include <algorithm>
 #include <iostream>
 #include <memory.h>
 #include <string>
 #include <vector>
 #include <set>
 #include <map>
 #include <cmath>
 //#include <unordered_map>
 //#include <unordered_set>
 #include <ctime>
 #include <stack>
 #include <queue>
 using namespace std;
 //#define FILENAME ""
 #define mp make_pair
 #define all(a) a.begin(), a.end()
 typedef long long li;
 typedef long double ld;
 void solve();
 //void precalc();
 clock_t start;
 //int timer = 1;
 int main() {
 #ifdef room111
     freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #else
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
     //freopen(FILENAME".in", "r", stdin);
     //freopen(FILENAME ".out", "w", stdout);
 #endif
     int t = 1;
 	//cout.sync_with_stdio(0);
 	//precalc();
 	cout.precision(10);
 	cout << fixed;
 	cin >> t;
 	start = clock();
     while (t--) {
         solve();
 		//++timer;
 	}
 
 #ifdef room111
 	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
 #endif
 
     return 0;
 }
 
 //BE CAREFUL: IS INT REALLY INT?
 
 int testNum = 1;
 
 //#define int li
 
 vector<vector<int>> matrix;
 
 int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
 int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};
 
 bool correct (int i, int j) {
 	return i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size();
 }
 
 int adjacent (int i, int j) {
 	int res = 0;
 	for (int dir = 0; dir < 8; ++dir) {
 		int x = i + dx[dir];
 		int y = j + dy[dir];
 		if (correct(x, y) && matrix[x][y])
 			++res;
 	}
 	return res;
 }
 
 bool used[10][10];
 
 int dfs(int i, int j) {
 	if (used[i][j])
 		return 0;
 	used[i][j] = true;
 	if (adjacent(i, j))
 		return 1;
 	int res = 1;
 	for (int dir = 0; dir < 8; ++dir) {
 		int x = i + dx[dir];
 		int y = j + dy[dir];
 		if (correct(x, y) && !matrix[x][y])
 			res += dfs(x, y);
 	}
 	return res;
 }
 
 void solve() {
 	cout << "Case #" << testNum++ << ": ";
 
 	int r, c, m;
 	cin >> r >> c >> m;
 
 	if (r >= 2 && c >= 2 && m + 3 >= r * c && m + 1 != r * c) {
 		cout << "\nImpossible\n";
 		return;
 	}
 
 	if (m + 1 == r * c) {
 		cout << "\n";
 		for (int i = 0; i < r; ++i) {
 			for (int j = 0; j < c; ++j) {
 				if (i == 0 && j == 0)
 					cout << "c";
 				else
 					cout << "*";
 			}
 			cout << "\n";
 		}
 		return;
 	}
 
 	for (int mask = 0; mask < (1 << (r * c)); ++mask) {
 		matrix = vector<vector<int>>(r, vector<int>(c, 0));
 		int z = 0;
 		for (int i = 0; i < r * c; ++i)
 			if (mask & (1 << i)) {
 				++z;
 				matrix[i / c][i % c] = 1;
 				if (z > m || r * c - i + z < m)
 					break;
 			}
 		if (z != m)
 			continue;
 
 		bool f = true;
 		for (int i = 0; i < r && f; ++i)
 			for (int j = 0; j < c; ++j)
 				if (!matrix[i][j] && !adjacent(i, j)) {
 					memset(used, false, sizeof used);
 					int cur = dfs(i, j);
 					if (cur + m == r * c) {
 						matrix[i][j] = 2;
 						cout << "\n";
 						for (int i = 0; i < r; ++i) {
 							for (int j = 0; j < c; ++j) {
 								switch(matrix[i][j]) {
 								case 0:
 									cout << '.';
 									break;
 								case 1:
 									cout << "*";
 									break;
 								case 2:
 									cout <<"c";
 									break;
 								}
 							}
 							cout << "\n";
 						}
 						return;
 					}
 					f = false;
 					break;
 				}
 		
 	}
 
 	cout << "\nImpossible\n";
 }
