
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <stdlib.h>
using namespace std;
int N, M;
int arr[100][100];
int sum[100][100];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		static int cs = 1;
		int A;
		scanf("%d", &A);
		memset(arr, 0, sizeof(arr));
		for (N = 1; N*N < A; N++);
		for (; A%N != 0; N++);
		M = A / N;
		while (1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					sum[i][j] = arr[i][j];
					if (i > 0)sum[i][j] += sum[i - 1][j];
					if (j > 0) sum[i][j] += sum[i][j - 1];
					if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
				}
			}
			if (sum[N - 1][M - 1] == N * M) break;
			int ci, cj, mn;
			ci = 1; cj = 1;
			mn = 9;
			for (int i = 1; i < N - 1; i++) {
				for (int j = 1; j < M - 1; j++) {
					int value = sum[i + 1][j + 1];
					if (i - 2 >= 0) value -= sum[i - 2][j + 1];
					if (j - 2 >= 0) value -= sum[i + 1][j - 2];
					if (i - 2 >= 0 && j - 2 >= 0) value += sum[i - 2][j - 2];
					if (mn > value) {
						mn = value;
						ci = i; cj = j;
					}
				}
			}
			printf("%d %d\n", ci + 100, cj + 100);
			fflush(stdout);
			int x, y;
			scanf("%d %d", &x, &y);
			if (x == 0 && y == 0) break;
			x -= 100; y -= 100;
			arr[x][y] = 1;
		}
	}
	return 0;
}