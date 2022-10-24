#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 55;

const vector < int > ans = {
	0, 1,
	0, 7,
	0, 13,
	0, 37,
	1, 2,
	1, 6,
	1, 19,
	2, 3,
	2, 34,
	2, 49,
	3, 4,
	3, 5,
	3, 25,
	4, 17,
	4, 22,
	4, 32,
	5, 20,
	5, 33,
	5, 38,
	6, 10,
	6, 27,
	6, 30,
	7, 8,
	7, 12,
	7, 23,
	8, 9,
	8, 15,
	8, 31,
	9, 16,
	9, 27,
	9, 35,
	10, 11,
	10, 15,
	10, 18,
	11, 23,
	11, 29,
	11, 42,
	12, 28,
	12, 30,
	12, 35,
	13, 14,
	13, 18,
	13, 22,
	14, 33,
	14, 39,
	14, 48,
	15, 31,
	15, 44,
	16, 19,
	16, 27,
	16, 41,
	17, 23,
	17, 29,
	17, 47,
	18, 36,
	18, 39,
	19, 20,
	19, 26,
	20, 21,
	20, 44,
	21, 24,
	21, 25,
	21, 31,
	22, 26,
	22, 39,
	23, 46,
	24, 28,
	24, 33,
	24, 48,
	25, 30,
	25, 40,
	26, 36,
	26, 37,
	27, 28,
	28, 43,
	29, 42,
	29, 46,
	30, 49,
	31, 32,
	32, 37,
	32, 38,
	33, 45,
	34, 41,
	34, 42,
	34, 45,
	35, 44,
	35, 46,
	36, 38,
	36, 43,
	37, 40,
	38, 41,
	39, 45,
	40, 43,
	40, 44,
	41, 49,
	42, 47,
	43, 47,
	45, 48,
	46, 49,
	47, 48

};

int a[maxN][maxN];
int b[maxN][maxN];
int deg[maxN];

void initcore(int n) {
	for (int i = 1; i < n; ++i) {
		while (true) {
			int x = rand() % i;
			if (deg[x] < 3) {
				a[i][x] = a[x][i] = 1;
				++deg[i], ++deg[x];
				break;
			}
		}
	}
}

bool check(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i][j] = a[i][j];
			if (b[i][j] == 0) {
				b[i][j] = 1000000;
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		b[i][i] = 10000;
	}

	set < vector < int > > resset;
	for (int i = 0; i < n; ++i) {
		vector < int > cur;
		for (int j = 0; j < n; ++j) {
			cur.push_back(b[i][j]);
		}
		sort(cur.begin(), cur.end());
		//for (int j = 0; j < n; ++j) {
		//	cout << cur[j] << " ";
		//}
		//cout << endl;
		resset.insert(cur);
	}
	if (resset.size() >= 45) {
		return true;
	}
	return false;
}

void gen(int n) {
	memset(a, 0, sizeof(a));
	memset(deg, 0, sizeof(deg));
	initcore(n);

	if (!check(n)) {
		return;
	}
	/*for (int i = 0; i + 1 < n; ++i) {
	a[i][i + 1] = a[i + 1][i] = 1;
	++deg[i];
	++deg[i + 1];
	}*/

	int res = n - 1;
	int iter = 0;
	while (res < 2 * n) {
		++iter;
		if (iter > 10000000) return;
		int x = rand() % n, y = x + rand() % (n - x);
		//cerr << x << " " << y << endl;
		if (a[x][y]) continue;
		if (deg[x] > 3 || deg[y] > 3) continue;
		if (x == y) continue;
		a[x][y] = a[y][x] = 1;
		++res;
		++deg[x], ++deg[y];
		/*for (int i = 0; i < n; ++i) {
		cout << deg[i] << " ";
		}
		cout << endl;*/
		//cerr << res << endl;
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i][j] = a[i][j];
			if (b[i][j] == 0) {
				b[i][j] = 1000000;
			}
		}
	}


	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		b[i][i] = 10000;
	}

	int tot[maxN];
	for (int i = 0; i < n; ++i) {
		vector<int> cur;
		int pt = 0;
		for (int j = 0; j < n; ++j) {
			pt += b[i][j];
			cur.push_back(b[i][j]);
		}
		sort(cur.begin(), cur.end());
		//for (int j = 0; j < n; ++j) {
		//	cout << cur[j] << " ";
		//}
		//cout << endl;
		//resset.insert(pt);
		tot[i] = pt;
	}

	set < pair < int, int > > resset;
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) {
				ans += tot[j];
			}
		}
		resset.insert(make_pair(tot[i], ans));
	}

	cerr << "Size: " << resset.size() << endl;

	if (resset.size() == n) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (a[i][j]) {
					printf("%d %d\n", i, j);
				}
			}
		}

		/*for (auto x : resset) {
		for (int i = 0; i < x.size(); ++i) {
		cout << x[i] << " ";
		}
		cout << endl;
		}*/
		cerr << "Success!" << endl;
		exit(0);
	}
}

int g[maxN][maxN];
int gc[maxN][maxN];

int ac[maxN][maxN];

void solve() {
	int u, l;
	cin >> u >> l;
	int n = 50;

	memset(g, 0, sizeof(g));
	memset(gc, 0, sizeof(gc));
	memset(a, 0, sizeof(a));
	memset(ac, 0, sizeof(ac));

	cout << n << endl;
	for (int i = 0; i < 2 * n; ++i) {
		int nx = ans[2 * i], ny = ans[2 * i + 1];
		cout << ans[2 * i] + 1 << " " << ans[2 * i + 1] + 1 << endl;
		a[nx][ny] = a[ny][nx] = 1;
	}

	int x;
	cin >> x;
	if (x == -1) {
		exit(0);
	}
	for (int i = 0; i < 2 * n; ++i) {
		int cx, cy;
		cin >> cx >> cy;
		--cx, --cy;
		g[cx][cy] = g[cy][cx] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			gc[i][j] = g[i][j];
			ac[i][j] = a[i][j];
			if (gc[i][j] == 0) {
				gc[i][j] = 1000000;
			}
			if (ac[i][j] == 0) {
				ac[i][j] = 1000000;
			}
		}

	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				gc[i][j] = min(gc[i][j], gc[i][k] + gc[k][j]);
				ac[i][j] = min(ac[i][j], ac[i][k] + ac[k][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		gc[i][i] = 10000;
		ac[i][i] = 10000;
	}

	vector < int > tota(n);
	vector < int > totg(n);

	for (int i = 0; i < n; ++i) {
		int res1 = 0;
		int res2 = 0;
		for (int j = 0; j < n; ++j) {
			res1 += gc[i][j];
			res2 += ac[i][j];
		}
		tota[i] = res2;
		totg[i] = res1;
	}

	map < int, pair < int, int > > ansa;
	map < pair < int, int >, int > ansg;


	for (int i = 0; i < n; ++i) {
		int sumg = 0;
		int suma = 0;
		for (int j = 0; j < n; ++j) {
			if (a[i][j]) {
				suma += tota[j];
			}
			if (g[i][j]) {
				sumg += totg[j];
			}
		}
		ansa[i] = make_pair(tota[i], suma);
		ansg[make_pair(totg[i], sumg)] = i;
	}

	for (int i = 0; i < n; ++i) {
		int res = ansg[ansa[i]];
		cout << res + 1 << " ";
	}
	cout << endl;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
		//cerr << i << ": " << clock() << endl;
	}

	return 0;
}
