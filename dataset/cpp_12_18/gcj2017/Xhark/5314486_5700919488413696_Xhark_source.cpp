
 #pragma warning(disable:4996)
 #pragma comment(linker, "/STACK:36777216")
 #include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <memory.h>
 using namespace std;
 int dyn[101][101][101];
 
 int N, P;
 int cnt[16];
 
 int score(int a, int b, int c) {
 	if ((a + 2 * b + 3 * c) % P == 0) {
 		return 1;
 	}
 	return 0;
 }
 int solve(int a, int b, int c) {
 	int &dp = dyn[a][b][c];
 	if (dp != -1) return dp;
 	dp = 0;
 	if (a > 0) {
 		dp = max(dp, solve(a - 1, b, c) + score(a - 1, b, c));
 	}
 	if (b > 0) {
 		dp = max(dp, solve(a, b-1, c) + score(a, b-1, c));
 	}
 	if (c > 0) {
 		dp = max(dp, solve(a, b, c-1) + score(a, b, c-1));
 	}
 	return dp;
 }
 int main() {
 	freopen("A-small-attempt0.in", "r", stdin);
 	freopen("A-small-attempt0.out", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	while (T-- > 0) {
 		memset(dyn, -1, sizeof(dyn));
 		memset(cnt, 0, sizeof(cnt));
 		scanf("%d %d", &N, &P);
 		for (int i = 0; i < N; i++) {
 			int G;
 			scanf("%d", &G);
 			cnt[G % P] += 1;
 		}
 		int sol = cnt[0] + solve(cnt[1], cnt[2], cnt[3]);
 		static int cs = 1;
 		printf("Case #%d: %d\n", cs++, sol);
 	}
 	return 0;
 }