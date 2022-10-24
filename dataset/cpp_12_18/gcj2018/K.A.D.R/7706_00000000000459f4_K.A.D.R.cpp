#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#include <cstdio>
#define GETS gets_s
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <stdio.h>
#define GETS gets
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k, kolt;
char mas[22][22];
bool used[22][22];

const int di[] = { 0, 1, 0, -1 };
const int dj[] = { 1, 0, -1, 0 };

int dfs(int ci, int cj) {
	if (used[ci][cj]) return 0;
	used[ci][cj] = 1;
	int ans = 1;
	rept(i, 4) {
		int ni = ci + di[i];
		int nj = cj + dj[i];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || mas[ni][nj] != mas[ci][cj]) continue;
		ans += dfs(ni, nj);
	}
	return ans;
}
int maxcom(char col) {
	C(used);
	int ans = 0;
	rept(i, n) {
		rept(j, m) {
			if (used[i][j] || mas[i][j] != col) continue;
			int cur = dfs(i, j);
			ans = max(ans, cur);
		}
	}
	return ans;
}

inline int sg1(int l, int p) {
	return p < l;
}
inline pii sg(int hor, int ver, int bi, int bj) {
	return mp(sg1(hor, bi), sg1(ver, bj));
}
char need[2][3];

inline char opp(char ch) {
	if (ch == 'W') return 'B'; else
		return 'W';
}

bool uu[21][21][16][21][21];
int solve2(int hor, int ver, int bi, int bj) {
	auto s0 = sg(hor, ver, bi, bj);
	
	if (mas[bi][bj] != need[s0.x][s0.y]) {
		return 0;
	}

	int mask = 0;
	rept(i, 2) {
		rept(j, 2) {
			mask *= 2;
			if (need[i][j] == 'W') ++mask;
		}
	}
	if (uu[hor][ver][mask][bi][bj]) return 0;
	
	queue<pii> q;
	C(used);
	q.push(mp(bi, bj));
	used[bi][bj] = 1;
	uu[hor][ver][mask][bi][bj] = 1;
	int ans = 0;
	while (!q.empty()) {
		pii t = q.front();
		q.pop();
		++ans;
		int ci = t.x, cj = t.y;

		rept(i, 4) {
			int ni = ci + di[i];
			int nj = cj + dj[i];
			if (ni < 0 || ni >= n || nj < 0 || nj >= m || used[ni][nj]) continue;
			
			auto s = sg(hor, ver, ni, nj);
			if (need[s.x][s.y] != mas[ni][nj]) continue;

			used[ni][nj] = 1;
			uu[hor][ver][mask][ni][nj] = 1;
			q.push(mp(ni, nj));
		}
	}
	return ans;
}

int solve(int hor, int ver, int bi, int bj) {
	auto s0 = sg(hor, ver, bi, bj);
	if (hor == 0 || hor == n || ver == 0 || ver == m) {
		need[s0.x][s0.y] = mas[bi][bj];
		rept(i, 2) {
			rept(j, 2) {
				if (i != s0.x || j != s0.y) need[i][j] = opp(mas[i][j]);
			}
		}
		return solve2(hor, ver, bi, bj);
	}
	
	int ans = 0;
	rept(mask, 1 << 4) {
		rept(i, 2) {
			rept(j, 2) {
				if (mask & 1 << (i * 2 + j)) need[i][j] = 'W'; else
					need[i][j] = 'B';
			}
		}
		bool ok = 0;
		
		rept(i, n - 1) {
			rept(j, m - 1) {
				int hor2 = i + 1;
				int ver2 = j + 1;
				bool ok2 = 1;
				rept(ii, 2) {
					rept(jj, 2) {
						auto s = sg(hor2, ver2, i + ii, j + jj);
						if (need[s.x][s.y] != mas[i + ii][j + jj]) {
							ok2 = 0;
							break;
						}
					}
					if (!ok2) break;
				}
				if (ok2) {
					ok = 1;
					break;
				}
			}
			if (ok) break;
		}
		if (!ok) continue;
		int cur = solve2(hor, ver, bi, bj);
		ans = max(ans, cur);
	}
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d%d", &n, &m);
		rept(i, n) {
			scanf("%s", mas[i]);
		}
		printf("Case #%d: ", hod);

		int a1 = maxcom('W');
		int a2 = maxcom('B');

		int ans = max(a1, a2);
		if (!a1 || !a2) {
			printf("%d\n", ans);
			continue;
		}

		C(uu);

		rept(hor, n + 1) {
			rept(ver, m + 1) {
				rept(i, n) {
					rept(j, m) {
						bool ok = 0;
						if (i == hor || i + 1 == hor) ok = 1;
						if (j == ver || j + 1 == ver) ok = 1;
						if (!ok) continue;
						int cur = solve(hor, ver, i, j);
						ans = max(ans, cur);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}
