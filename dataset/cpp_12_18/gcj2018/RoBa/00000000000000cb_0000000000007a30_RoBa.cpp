#include <cstdio>
#include <cstring>
#include <cstdlib>

int tk[30][30];

void process(int R, int C) {
	memset(tk, 0, sizeof(tk));
	int cnt = 0;
	for (int i = 1 ; i <= R ; ++i)
		for (int j = 1 ; j <= C ; ++j) {
			while (!tk[i][j]) {
				int cx, cy;
				if (i + 2 <= R) cx = i + 1;
				else cx = R - 1;
				if (j + 2 <= C) cy = j + 1;
				else cy = C - 1;

				printf("%d %d\n", cx, cy);
				fflush(stdout);
				int realx, realy;
				scanf("%d%d",&realx, &realy);
				if (realx == 0 && realy == 0) {
					return;
				}
				tk[realx][realy] = 1;
			}
		}
}

int main() {
	int T, A, R, C;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&A);
		if (A == 20) {
			R = 4; C = 5;
			process(R, C);
		} else if (A == 200) {
			R = 14; C = 15;
			process(R, C);
		} else {
			printf("Error A value!\n");
			fflush(stdout);
		}
	}
	return 0;
}