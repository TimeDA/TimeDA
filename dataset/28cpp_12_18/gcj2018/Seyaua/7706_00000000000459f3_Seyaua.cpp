#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>

using namespace std;

const int maxN = 510;
int R, B;

vector<pair<int, int> > vals;

int cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first + a.second < b.first + b.second;
}

int dp[2][maxN][maxN];


int ndp[2][maxN][maxN];
int rs[maxN][maxN];

void solve(int tcase) {
	printf("Case #%d: ", tcase);

	scanf("%d%d", &R, &B);

	cout << max(rs[R][B], rs[B][R]) << endl;

}


void precalc() {
	memset(ndp, -1, sizeof(ndp));
	ndp[0][0][0] = 0;
	int maxR = 500, maxB = 60;

	int u = 0, v = 1;

	vals.clear();
	for (int i = 0; i <= maxR; ++i) {
		for (int j = 0; j <= maxR; ++j) {
			vals.push_back(make_pair(i, j));
		}
	}
	sort(vals.begin(), vals.end(), cmp);
	
	int nsum = 0;

	for (int i = 1; i < 2000; ++i) {
		int vi = vals[i].first;
		int vj = vals[i].second;
		int changes = 0;
		for (int kk = 0; kk <= maxR; ++kk) {
			if (kk + vi > maxR) {
				break;
			}
			int br = kk + vi;
			for (int jj = 0; jj <= maxR; ++jj) {
				if (ndp[u][kk][jj] == -1) {
					continue;
				}
				if (jj + vj > maxR) {
					break;
				}
				/*if (ndp[u][kk][jj] > ndp[v][kk][jj]) {
					ndp[v][kk][jj] = ndp[u][kk][jj];
					changes = 1;
				}*/
				ndp[v][kk][jj] = max(ndp[v][kk][jj], ndp[u][kk][jj]);
				/*if (ndp[u][kk][jj] + 1 > ndp[v][br][jj + vj]) {
					nsum = max(nsum, vi + vj);
					ndp[v][br][jj + vj] = ndp[u][kk][jj] + 1;
					changes = 1;
				}*/
				ndp[v][br][jj + vj] = max(ndp[v][br][jj + vj], ndp[u][kk][jj] + 1);
			}
		}
		swap(u, v);
		//if (!changes) {
		//	break;
		//}
		//if (i % 1000 == 0) cerr << i << " " << nsum << endl;
	}
	for (int i = 0; i <= maxR; ++i) {
		for (int j = 0; j <= maxR; ++j) {
			rs[i][j] = ndp[u][i][j];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	precalc();
	//cerr << clock() << endl;
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
	}

	return 0;
}