
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
using namespace std;
typedef pair<double, double> pii;
#define mp(a, b) make_pair(a, b)

int pN = 0;
int get_pnum(map<pii, int> &pmap, map<int, pii > &nmap, double x, double y) {
	pii point = mp(x, y);
	if (pmap.find(point) == pmap.end()) {
		nmap[pN] = point;
		pmap[point] = pN++;
	}
	return pmap[point];
}

const int MAX_N = 1200;
vector<pair<int ,int> > lst[MAX_N];
bool used[MAX_N];
typedef double LL;
bool cmp(pair<pii, int> &a, pair<pii, int> &b) {
	LL ax = a.first.first;
	LL ay = a.first.second;

	LL bx = b.first.first;
	LL by = b.first.second;

	return ax * by < bx * ay;
}

double A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];
int F, K;
vector<int> solve() {
	map<pii, int> pmap;
	map<int, pii > nmap;
	pN = 0;
	for (int i = 0; i < F; i++) {
		double a = A[i], b = B[i], c = C[i], d = D[i];
		int p1 = get_pnum(pmap, nmap, a, b);
		int p2 = get_pnum(pmap, nmap, c, d);
		lst[p1].push_back(mp(p2, i));
		lst[p2].push_back(mp(p1, i));
		used[i] = false;
	}
	vector<int> sol;
	for (auto x : pmap) {
		pii p = x.first;
		double px = p.first;
		double py = p.second;

		int pn = x.second;
		vector<pair<pii, int> > cand;
		for (auto t : lst[pn]) {
			int tn = t.first;
			int ti = t.second;
			pii tp = nmap[tn];
			double tx = tp.first;
			double ty = tp.second;
			if (tx > px) continue;
			if (tx == px && ty > py) continue;
			if (used[ti]) continue;

			if (tx == px) {
				sol.push_back(ti);
				used[ti] = true;
				continue;
			}
			//double po = -(double)(py - ty) / (double)(px - tx);
			pii po = mp(ty - py, px - tx);
			cand.push_back(mp(po, ti));
			used[ti] = true;
		}
		sort(cand.begin(), cand.end(), cmp);
		for (auto c : cand) {
			sol.push_back(c.second);
		}
	}
	for (int i = 0; i < pN; i++) lst[i].clear();
	return sol;
}
void flipX() {
	for (int i = 0; i < F; i++) {
		A[i] = -A[i]; C[i] = -C[i];
	}
}

void flipY() {
	for (int i = 0; i < F; i++) {
		B[i] = -B[i]; D[i] = -D[i];
	}
}

void changeXY() {
	double tmp;
	for (int i = 0; i < F; i++) {
		tmp = A[i]; A[i] = B[i]; B[i] = tmp;
		tmp = C[i]; C[i] = D[i]; D[i] = tmp;
	}
}
#include <math.h>
pii change(double x, double y, double thet, double ux, double uy) {
	double a11 = cos(thet), a12 = -sin(thet), a21 = sin(thet), a22 = cos(thet);
	double tx = (x - ux), ty = (y - uy);
	double px = tx * a11 + ty * a12;
	double py = tx * a21 + ty * a22;
	return mp(px, py);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d", &F, &K);
		for (int i = 0; i < F; i++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			A[i] = a; B[i] = b; C[i] = c; D[i] = d;
		}
		double thet = atan2(C[0] - A[0], D[0] - B[0]);
		double ux = B[0], uy = A[0];
		thet = -thet;
		for (int i = 0; i < F; i++) {
			pii pa = change(B[i], A[i], thet, ux, uy);
			pii pb = change(D[i], C[i], thet, ux, uy);
			B[i] = pa.first; A[i] = pa.second;
			D[i] = pb.first; C[i] = pb.second;
			
		}
		int fc = 0;
		while (1) {
			vector<int> sol = solve();
			bool flip = false;
			for (int i = 0; i < F; i++) {
				if (sol[i] == 0) {
					static int cs = 1;
					printf("Case #%d:", cs++);
					for (int i = 0; i < F; i++) printf(" %d", sol[i] + 1);
					printf("\n");
					break;
				}
				if (sol[i] == 1) {
					flip = true;
					break;
				}
			}
			if (!flip) break;
			if (fc == 0) flipX();
			else if (fc == 1) flipY();
			else if (fc == 2) flipX();
			else if (fc == 3) flipY();
			else if (fc == 4) changeXY();
			else if (fc == 5) flipX();
			else if (fc == 6) flipY();
			else if (fc == 7) flipX();
			else if (fc == 8) flipY();
			fc++;
		}
	}
	return 0;
}