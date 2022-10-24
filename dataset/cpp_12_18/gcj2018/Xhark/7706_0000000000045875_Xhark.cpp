
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
using namespace std;
const int MAX_N = 128;
int N;
int A[MAX_N][MAX_N];

class Edge {
public:
	int who, val, rev;
};
class Matching {
public:
	Matching() {}

	void init(int N) {
		for (int i = 0; i < N; i++) Xmap[i] = -1;
		for (int i = 0; i < N; i++) Ymap[i] = -1;
		Xn = 0; Yn = 0; E = 0;
	}
	int Xmap[MAX_N], Ymap[MAX_N], Xn, Yn, E;
	vector<Edge> lx[MAX_N], ly[MAX_N];
	bool chkX[MAX_N], chkY[MAX_N];
	int matX[MAX_N], matY[MAX_N], matYe[MAX_N];;

	int get_X(int x) {
		if (Xmap[x] == -1) Xmap[x] = Xn++;
		return Xmap[x];
	}
	int get_Y(int y) {
		if (Ymap[y] == -1) Ymap[y] = Yn++;
		return Ymap[y];
	}
	void add_edge(int x, int y) {
		x = get_X(x);
		y = get_Y(y);
		Edge f, r;
		f.who = y; f.val = 1; f.rev = (int)ly[y].size();
		r.who = x; r.val = 0; r.rev = (int)lx[x].size();
		lx[x].push_back(f);
		ly[y].push_back(r);
		E++;
	}
	bool dfy(int y);
	bool dfx(int x) {
		if (chkX[x]) return false;
		chkX[x] = true;
		for (auto e : lx[x]) {
			if (e.val > 0) {
				if (dfy(e.who)) {
					ly[e.who][e.rev].val++;
					e.val --;
					matX[x] = e.who;
					matY[e.who] = x;
					matYe[e.who] = e.rev;
					return true;
				}
			}
		}
		return false;
	}
	int get_matching() {
		for (int i = 0; i < Xn; i++) matX[i] = -1;
		for (int i = 0; i < Yn; i++) matY[i] = -1;
		int mat = 0;
		while (1) {
			memset(chkX, 0, sizeof(chkX));
			memset(chkY, 0, sizeof(chkY));
			bool found = false;
			for (int i = 0; i < Xn; i++) {
				if (matX[i] == -1) {
					if (dfx(i)) {
						mat++;
						found = true;
						break;
					}
				}
			}
			if (!found) break;
		}
		return mat;
	}
};
bool Matching::dfy(int y) {
	if (chkY[y]) return false;
	chkY[y] = true;
	if (matY[y] == -1) return true;
	if (dfx(matY[y])) {
		int r = matYe[y];
		ly[y][r].val--;
		int rv = ly[y][r].rev;
		lx[matY[y]][rv].val++;
		return true;
	}
	return false;
}
Matching *M;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		M = new Matching[2 * N + 1];
		for (int i = 0; i < 2 * N + 1; i++) M[i].init(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				M[A[i][j] + N].add_edge(i, j);
			}
		}
		int sol = 0;
		for (int i = 0; i < 2 * N + 1; i++) {
			sol += M[i].E - M[i].get_matching();
		}
		static int cs = 1;
		printf("Case #%d: %d\n", cs++, sol);
		delete[] M;
	}
	return 0;
}