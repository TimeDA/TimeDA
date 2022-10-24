
 #pragma warning(disable:4996)
 #pragma comment(linker, "/STACK:36777216")
 #include <stdio.h>
 #include <algorithm>
 #include <vector>
 #include <string>
 #include <memory.h>
 using namespace std;
 int N, M;
 const int MAX_N = 512;
 class FLOW {
 public:
 	int mat[MAX_N][MAX_N];
 	int N, A, B;
 	void init(int N) {
 		this->N = N;
 		memset(mat, 0, sizeof(mat));
 		A = N - 2;
 		B = N - 1;
 	}
 	void set_edge(int a, int b, int c) {
 		mat[a][b] = c;
 	}
 	bool chk[MAX_N];
 	bool dfs(int x) {
 		if (x == B) return true;
 		chk[x] = true;
 		for (int i = 0; i < N; i++) {
 			if (mat[x][i] && !chk[i]) {
 				if (dfs(i)) {
 					mat[x][i] --;
 					mat[i][x] ++;
 					return true;
 				}
 			}
 		}
 		return false;
 	}
 	void run() {
 		while (1) {
 			for (int i = 0; i < N; i++) chk[i] = false;
 			if (!dfs(A)) {
 				break;
 			}
 		}
 	}
 };
 char from[101][101], to[101][101];
 FLOW dflow, rcflow;
 int main() {
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("D-small-attempt1.out", "w", stdout);
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	int T;
 	scanf("%d", &T);
 	while (T-- > 0) {
 		int N, M;
 		scanf("%d %d", &N, &M);
 		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) from[i][j] = to[i][j] = '.';
 		int dN = N * 2 - 1;
 
 		int dA = dN * 2, rcA = N * 2;
 		int dB = dA + 1, rcB = rcA + 1;
 		dflow.init(dN*2+2);
 		rcflow.init(N*2+2);
 
 		for (int i = 0; i < N; i++) {
 			rcflow.set_edge(rcA, i, 1);
 			rcflow.set_edge(N + i, rcB, 1);
 			for (int j = 0; j < N; j++) {
 				rcflow.set_edge(i, N + j, 1);
 				dflow.set_edge(i + j, i - j + N - 1 + dN, 1);
 			}
 		}
 
 		for (int i = 0; i < dN; i++) {
 			dflow.set_edge(dA, i, 1);
 			dflow.set_edge(dN + i, dB, 1);
 		}
 
 		for (int i = 0; i < M; i++) {
 			char c[16];
 			int x, y;
 			scanf("%s %d %d", c, &x, &y);
 			x--; y--;
 			from[x][y] = to[x][y] = c[0];
 			if (c[0] == 'o' || c[0] == '+') { // diagonal
 				dflow.set_edge(dA, x + y, 0);
 				dflow.set_edge(x - y + (N - 1) + dN, dB, 0);
 				dflow.set_edge(x - y + (N - 1) + dN, x + y, 1);
 				for (int t = 0; t < dN; t++) {
 					dflow.set_edge(x+y, t + dN, 0);
 					dflow.set_edge(t, x - y + (N - 1) + dN, 0);
 				}
 			}
 			if (c[0] == 'o' || c[0] == 'x') {
 				rcflow.set_edge(rcA, x, 0);
 				rcflow.set_edge(N + y, rcB, 0);
 				rcflow.set_edge(N + y, x, 1);
 				for (int t = 0; t < N; t++) {
 					rcflow.set_edge(x, t + N, 0);
 					rcflow.set_edge(t, y + N, 0);
 				}
 			}
 		}
 		dflow.run();
 		rcflow.run();
 		int point = 0, diff = 0;
 		for (int x = 0; x < N; x++) {
 			for (int y = 0; y < N; y++) {
 				int rcX = x, rcY = y + N;
 				int rcF = rcflow.mat[rcY][rcX];
 				int dX = x + y, dY = x - y + (N - 1) + dN;
 				int dF = dflow.mat[dY][dX];
 
 				point += rcF + dF;
 
 				if (rcF && dF) {
 					to[x][y] = 'o';
 				}
 				else if (rcF) {
 					to[x][y] = 'x';
 				}
 				else if (dF) {
 					to[x][y] = '+';
 				}
 				else {
 					to[x][y] = '.';
 				}
 				if (from[x][y] != to[x][y]) diff++;
 			}
 		}
 		static int cs = 1;
 		printf("Case #%d: %d %d\n", cs++, point, diff);
 		for (int x = 0; x < N; x++) for (int y = 0; y < N; y++) {
 			if (from[x][y] != to[x][y]) {
 				printf("%c %d %d\n", to[x][y], x + 1, y + 1);
 			}
 		}
 	}
 	return 0;
 }