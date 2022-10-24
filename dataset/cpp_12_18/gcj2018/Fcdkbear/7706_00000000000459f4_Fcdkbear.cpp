#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <fstream>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

char s[50][50];
int a[50][50];
int was[50][50];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool isCor(int x, int y, int n, int m) {
	if ((x < 0) || (x >= n) || (y < 0) || (y >= m)) {
		return false;
	}
	return true;
}

void dfs(int x, int y, int n, int m, int &cnt) {
	if (!isCor(x, y, n, m)) {
		return;
	}
	if (was[x][y]) {
		return;
	}
	if (!a[x][y]) {
		return;
	}
	was[x][y] = 1;
	cnt--;
	FOR(k, 0, 4) {
		dfs(x + dx[k], y + dy[k], n, m, cnt);
	}
}

vector<vector<char>> p1, p2;

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	int tests;
	cin >> tests;
	for (int testNumber = 1; testNumber <= tests; ++testNumber) {
		int n, m;
		cin >> n >> m;
		p1.clear();
		p1.resize(n);
		FOR(i, 0, n) {
			scanf("%s", s[i]);
			FOR(j, 0, m) {
				p1[i].push_back(s[i][j]);
			}
		}
		FOR(it, 0, 5) {
			p2.clear();
			p2.resize(p1.size() * 2);
			FOR(i, 0, p1.size()) {
				FOR(j, 0, p1[0].size()) {
					p2[i * 2].push_back(p1[i][j]);
					p2[i * 2].push_back(p1[i][j]);
					p2[i * 2 + 1].push_back(p1[i][j]);
					p2[i * 2 + 1].push_back(p1[i][j]);
				}
			}
			p1 = p2;
		}
		int res = 0;
		FOR(mask, 1, (1 << (n*m))) {
			MEMS(a, 0);
			int cnt = 0;
			int x = -1;
			int y = -1;
			FOR(i, 0, n*m) {
				if ((mask >> i) & 1) {
					cnt++;
					x = i / m;
					y = i % m;
					a[i / m][i%m] = 1;
				}
			}
			int tot = cnt;
			if (tot < res) {
				continue;
			}
			MEMS(was, 0);
			dfs(x, y, n, m, cnt);
			if (cnt) {
				continue;
			}
			bool ok = false;
			FOR(i, 0, p1.size()) {
				FOR(j, 0, p1[0].size()) {
					ok = true;
					FOR(x, 0, n) {
						FOR(y, 0, m) {
							if (a[x][y] == 1) {
								if ((!isCor(i + x, j + y, p1.size(), p1[0].size())) || (p1[i + x][j + y] != s[x][y])) {
									ok = false;
								}
							}
						}
					}
					if (ok) {
						//cout << mask << " " << i << " " << j << endl;
						break;
					}
				}
				if (ok) {
					break;
				}
			}
			if (ok) {
				res = max(res, tot);
			}
		}
		printf("Case #%d: %d\n", testNumber, res);
	}


#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
