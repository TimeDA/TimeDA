#include <cstdio>
 #include <string>
 #include <cstring>
 #include <vector>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 int dt12[102][102];
 int dt3top[102][102];
 const int mod = 1000000007;
 
 
 int board[8][8];
 
 int check_board(int height, int width)
 {
 	for (int i = 0; i < height; i++) {
 		for (int j = 0; j < width; j++) {
 			if (board[i][j]) { // 2
 				int cnt = 0;
 				cnt += (board[i][(j + 1) % width]);
 				cnt += (board[i][(j + width - 1) % width]);
 				if (i + 1 < height)cnt += (board[i + 1][j]);
 				if (i > 0)cnt += (board[i - 1][j]);
 				if (cnt != 2) return 0;
 			}
 			else { // 1
 				int cnt = 0;
 				cnt += !(board[i][(j + 1) % width]);
 				cnt += !(board[i][(j + width - 1) % width]);
 				if (i + 1 < height)cnt += !(board[i + 1][j]);
 				if (i > 0)cnt += !(board[i - 1][j]);
 				if (cnt != 1) return 0;
 			}
 		}
 	}
 	return 1;
 }
 
 int mid_check_board(int height, int width)
 {
 	for (int i = 0; i < height; i++) {
 		for (int j = 0; j < width; j++) {
 			if (!board[i][j]) { // 1
 				int cnt = 0;
 				cnt += !(board[i][(j + 1) % width]);
 				cnt += !(board[i][(j + width - 1) % width]);
 				if (i + 1 < height)cnt += !(board[i + 1][j]);
 				if (i > 0)cnt += !(board[i - 1][j]);
 				if (cnt > 1) return 0;
 			}
 		}
 	}
 	return 1;
 }
 
 int dfs(int r, int c, int height, int width)
 {
 	if (!mid_check_board(height, width)) return 0;
 	if (c == width) return dfs(r + 1, 0, height, width);
 	if (r == height) return check_board(height, width);
 	int res = dfs(r, c+1, height, width);
 	if (r + 1 < height && board[r][c] == 1 && board[r+1][c] == 1){
 		board[r][c] = 0;
 		board[r + 1][c] = 0;
 		res += dfs(r, c + 1, height, width);
 		board[r][c] = 1;
 		board[r + 1][c] = 1;
 	}
 	if (board[r][c] == 1 && board[r][(c+1)%width] == 1){
 		board[r][c] = 0;
 		board[r][(c + 1) % width] = 0;
 		res += dfs(r, c + 1, height, width);
 		board[r][c] = 1;
 		board[r][(c + 1) % width] = 1;
 	}
 	return res;
 }
 
 long long getans(int R, int C)
 {
 	long long val = 0;
 	for (int i = 0; i <= R; i++) {
 		val += dt12[i][C] * dt3top[R - i][C] % mod;
 	}
 	val %= mod;
 	return val;
 }
 
 int gcd(int a, int b){
 	while (b) {
 		int t = a % b;
 		a = b;
 		b = t;
 	}
 	return a;
 }
 
 int main(){
 	for (int C = 0; C <= 100; C++) {
 		dt3top[0][C] = 1;
 		dt12[0][C] = 1;
 	}
 	for (int R = 1; R <= 6; R++) {
 		for (int C = 1; C <= 6; C++) {
 			for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) board[i][j] = 1;
 			dt12[R][C] = dfs(0, 0, R, C);
 		}
 	}
 	for (int R = 1; R <= 100; R++) {
 		for (int C = 1; C <= 100; C++) {
 			/* fill dt3top: 3   */
 			long long val = 0;
 			if (R >= 2) val = dt12[R-2][C];
 			for (int i = 1; i < R - 2; i++) {
 				val += dt12[i][C] * dt3top[R-2-i][C] % mod;
 			}
 			val %= mod;
 			dt3top[R][C] = val;
 		}
 	}
 	int T;
 	scanf("%d", &T);
 	for (int testcase = 1; testcase <= T; testcase++)
 	{
 		int R, C;
 		scanf("%d%d", &R, &C);
 		long long ans = 0;
 		long long divval = 0;
 		for (int i = 1; i <= C; i++) {
 			ans += getans(R, gcd(i, C));
 			ans %= mod;
 			divval++;
 		}
 		ans /= divval;
 		printf("Case #%d: %lld\n", testcase, ans);
 	}
 	return 0;
 }