
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_C = 128;
int C, B[MAX_C];
char sol[MAX_C][MAX_C];
int from[MAX_C];

void move(int x, int y) {
	int r = 0;
	while (x != y) {
		if (x < y) {
			sol[r][x] = '\\';
			x++;
		}
		else {
			sol[r][x] = '/';
			x--;
		}
		r++;
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &C);
		for (int i = 0; i < C; i++) scanf("%d", &B[i]);
		static int cs = 1;
		printf("Case #%d: ", cs++);
		if (B[0] == 0 || B[C - 1] == 0) {
			printf("IMPOSSIBLE\n");
		}
		else {
			for (int i = 0; i < C; i++) for (int j = 0; j < C; j++) sol[i][j] = '.';
			for (int j = 0; j < C; j++) from[j] = 1;
			int row = 1;
			for (int i = 0; i < C; i++) {
				for (int j = 0; j < C; j++) {
					if (B[i] > 0 && from[j] > 0) {
						move(j, i);
						B[i] --; from[j] --;
						int diff = j-i;
						if (diff < 0) diff = -diff;
						if (row < diff + 1) row = diff + 1;
					}
				}
			}
			printf("%d\n", row);
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < C; j++) printf("%c", sol[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}