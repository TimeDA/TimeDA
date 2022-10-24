
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_N = 500;
int dyn[MAX_N+1][MAX_N+1];
int mx[MAX_N+1][MAX_N + 1];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int r = 0; r <= 33; r++) {
		for (int b = 0; b <= 33; b++) {
			if (r + b == 0) continue;
			//if (r+b > 33) continue;
			for (int x = MAX_N; x >= r; x--) {
				for (int y = MAX_N; y >= b; y--) {
					dyn[x][y] = max(dyn[x][y], mx[x - r][y - b] + 1);
				}
			}
			for (int x = 0; x <= MAX_N; x++) {
				for (int y = 0; y <= MAX_N; y++) {
					mx[x][y] = max(mx[x][y], dyn[x][y]);
					if (x>0) mx[x][y] = max(mx[x][y], mx[x - 1][y]);
					if (y>0) mx[x][y] = max(mx[x][y], mx[x][y - 1]);
				}
			}
		}
	}
	while (T-- > 0) {
		static int cs = 1;
		int R, B;
		scanf("%d %d", &R, &B);
		
		printf("Case #%d: %d\n", cs++, dyn[R][B]);
	}
	return 0;
}