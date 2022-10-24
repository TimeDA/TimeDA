
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <math.h>
using namespace std;
const int MAX_N = 128;
int N, P;
int	W[MAX_N], H[MAX_N];
double S[MAX_N], E[MAX_N];
const double eps = 1.0e-12;
typedef pair<double, double> pii;
int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d %d", &N, &P);
		double sol = 0.0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &W[i], &H[i]);
			sol += 2.0 * double(W[i] + H[i]);
			P -= 2*W[i];
			P -= 2*H[i];
			S[i] = 2.0 * double(min(W[i], H[i]));
			E[i] = 2.0 * sqrt(double(W[i] * W[i] + H[i] * H[i]));
		}
		vector<pii> range, trange, nrange;
		range.push_back(make_pair(0.0, 0.0));
		for (int i = 0; i < N; i++) {
			trange.clear();
			for (int j = 0; j < (int)range.size(); j++) {
				trange.push_back(make_pair(S[i] + range[j].first, E[i] + range[j].second));
			}
			nrange.clear();
			int a = 0, b = 0;
			while (a < (int)range.size() || b < (int)trange.size()) {
				bool update_b = true;
				if (a < (int)range.size()) {
					if (b == (int)trange.size()) update_b = false;
					else if (range[a].first < trange[b].first) update_b = false;
				}
				if (!update_b) {
					nrange.push_back(range[a]);
					a++;
				}
				else {
					nrange.push_back(trange[b]);
					b++;
				}
			}
			double cs, ce;
			cs = nrange[0].first; ce = nrange[0].second;
			range.clear();
			for (int j = 1; j < (int)nrange.size(); j++) {
				double s = nrange[j].first;
				double e = nrange[j].second;
				if (s <= ce + eps) {
					ce = max(ce, e);
					continue;
				}
				else {
					range.push_back(make_pair(cs, ce));
					cs = s; ce = e;
				}
			}
			range.push_back(make_pair(cs, ce));
		}
		double dP = (double)P, dX = 0.0;
		for (int i = 0; i < (int)range.size(); i++) {
			double s = range[i].first;
			double e = range[i].second;
			if (e <= dP) {
				dX = e;
			}
			else if (s <= dP) {
				dX = dP;
				break;
			}
			else {
				break;
			}
		}
		sol += dX;
		static int cs = 1;
		printf("Case #%d: %.9lf\n", cs++, sol);
	}
	return 0;
}