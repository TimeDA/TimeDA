#include<cstdio>
 #include<iostream>
 #include<queue>
 #include<stack>
 #include<vector>
 #include<string>
 #include<algorithm>
 #include<map>
 #include<sstream>
 #include<cmath>
 #include<cctype>
 #include<cassert>
 #include<cstring>
 #include<cstdlib>
 
 using namespace std;
 
 const int debug = 0;
 #define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
 const int inf = 1000000000;
 
 vector<string> grid;
 int R, C;
 int finalP[105][105];
 int res;
 
 bool ok(int r, int c, int d) {
 	if (r > 0 && c > 0 && r < (R - 1) && c < (C - 1)) return true;
 
 	if (r == 0 && d == 0) return false;
 	if (c == 0 && d == 3) return false;
 	if (r == (R - 1) && d == 2) return false;
 	if (c == (C - 1) && d == 1 ) return false;
 
 	return true;
 }
 
 string move = "^>v<";
 int dir[][2] = {
 	-1, 0,
 	0, 1,
 	1, 0,
 	0, -1
 };
 
 bool inside(int r, int c) {
 	return r >= 0 && r < R && c >= 0 && c < C;
 }
 
 void check() {
 	int cnt = 0;
 	for (int i = 0; i < R; i++)
 		for (int j = 0; j < C; j++) {
 			if (finalP[i][j] != -1 && move[ finalP[i][j] ] != grid[i][j]) cnt++;
 		}
 	if (cnt >= res) return;
 
 	for (int i = 0; i < R; i++)
 		for (int j = 0; j < C; j++) {
 			if (finalP[i][j] == -1) continue;
 
 			int r = i, c = j;
 			while(true) {
 				r = r + dir[ finalP[i][j] ][ 0 ];
 				c = c + dir[ finalP[i][j] ][ 1 ];
 				if (!inside(r, c)) return;
 				if (finalP[r][c] != -1) break;
 			}
 		}
 	res = cnt;
 }
 
 void dfs(int r, int c) {
 	if (c == C) {
 		c = 0;
 		r++;
 	}
 	if (r == R) {
 		check();
 		return;
 	}
 
 	if (grid[r][c] == '.') {
 		dfs(r, c+1);
 		return;
 	}
 
 	for (int i = 0; i < 4; i++) {
 		if (ok(r, c, i)) {
 			finalP[r][c] = i;
 			dfs(r, c + 1);
 		}
 	}
 }
 
 int main() {
 	int test, cases = 1;
 	cin >> test;
 	for (cases = 1; cases <= test; cases++) {
 		cin >> R >> C;
 		grid.clear();
 		for (int i = 0; i < R; i++) {
 			string s; cin >> s; grid.push_back(s);
 		}
 		for (int i = 0; i < R; i++)
 			for (int j = 0; j < C; j++)
 				finalP[i][j] = -1;
 
 		res = inf;
 		dfs(0, 0);
 		printf("Case #%d: ", cases);
 		if (res == inf) cout << "IMPOSSIBLE" << endl;
 		else cout << res << endl;
 	}
 	return 0;
 }
