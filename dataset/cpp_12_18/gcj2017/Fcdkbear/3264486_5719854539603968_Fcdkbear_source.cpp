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
 
 int mt[210];
 int was[210];
 vector<vector<int>> g;
 int n;
 
 bool kuhn(int v) {
 	if (was[v]) {
 		return false;
 	}
 	was[v] = 1;
 	FOR(i, 0, g[v].size()) {
 		int to = g[v][i];
 		if ((mt[to] == -1) || (kuhn(mt[to]))) {
 			mt[to] = v;
 			return true;
 		}
 	}
 	return false;
 }
 
 char oldA[110][110];
 char a[110][110];
 int addX[110][110];
 int addPlus[110][110];
 int badCol[110];
 int badRow[110];
 
 void runMatching() {
 	MEMS(mt, -1);
 	FOR(i, 0, g.size()) {
 		MEMS(was, 0);
 		kuhn(i);
 	}
 }
 
 void goRows() {
 	g.clear();
 	g.resize(n);
 	MEMS(badRow, 0);
 	MEMS(badCol, 0);
 	FOR(i, 0, n) {
 		FOR(j, 0, n) {
 			if ((a[i][j] == 'x') || (a[i][j] == 'o')) {
 				badRow[i] = 1;
 				badCol[j] = 1;
 			}
 		}
 	}
 	FOR(i, 0, n) {
 		FOR(j, 0, n) {
 			if ((badRow[i] == 0) && (badCol[j] == 0)) {
 				g[i].push_back(j);
 			}
 		}
 	}
 	runMatching();
 	FOR(i, 0, g.size()) {
 		if (mt[i] != -1) {
 			addX[mt[i]][i] = 1;
 		}
 	}
 }
 
 int badDiag1[210];
 int badDiag2[210];
 
 void goDiagonals() {
 	g.clear();
 	g.resize(n + n - 1);
 	MEMS(badDiag1, 0);
 	MEMS(badDiag2, 0);
 	FOR(i, 0, n) {
 		FOR(j, 0, n) {
 			if ((a[i][j] == '+') || (a[i][j] == 'o')) {
 				badDiag1[i + j] = 1;
 				badDiag2[i - j + n - 1] = 1;
 			}
 		}
 	}
 	FOR(i, 0, n) {
 		FOR(j, 0, n) {
 			if ((badDiag1[i + j] == 0) && (badDiag2[i - j + n - 1] == 0)) {
 				g[i + j].push_back(i - j + n - 1);
 			}
 		}
 	}
 	runMatching();
 	FOR(i, 0, g.size()) {
 		if (mt[i] != -1) {
 			int x = (i + mt[i] - n + 1) / 2;
 			int y = mt[i] - x;
 			addPlus[x][y] = 1;
 		}
 	}
 }
 
 char s[3];
 vector<pnt> ans;
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	double beg = clock();
 	freopen("out.txt", "w", stdout);
 #else
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 #endif
 
 	int tests;
 	scanf("%d", &tests);
 	FOR(testNumber, 1, tests + 1) {
 		int m;
 		cin >> n >> m;
 		FOR(i, 0, n) {
 			FOR(j, 0, n) {
 				oldA[i][j] = a[i][j] = '.';
 			}
 		}
 		FOR(i, 0, m) {
 			int x, y;
 			scanf("%s%d%d", s, &x, &y);
 			x--;
 			y--;
 			oldA[x][y] = a[x][y] = s[0];
 		}
 		MEMS(addPlus, 0);
 		MEMS(addX, 0);
 		goRows();
 		goDiagonals();
 		ans.clear();
 		int res = 0;
 		FOR(i, 0, n) {
 			FOR(j, 0, n) {
 				if ((addPlus[i][j]) && (addX[i][j])) {
 					a[i][j] = 'o';				
 				}
 				else if (addPlus[i][j]) {
 					if (a[i][j] == 'x') {
 						a[i][j] = 'o';
 					}
 					else {
 						a[i][j] = '+';
 					}
 				}
 				else if (addX[i][j]) {
 					if (a[i][j] == '+') {
 						a[i][j] = 'o';
 					}
 					else {
 						a[i][j] = 'x';
 					}
 				}
 				if ((a[i][j] == '+') || (a[i][j] == 'x')) {
 					res++;
 				}
 				else if (a[i][j] == 'o') {
 					res += 2;
 				}
 				if (a[i][j] != oldA[i][j]) {
 					ans.push_back(mp(i, j));
 				}
 			}
 		}
 		printf("Case #%d: %d %d\n", testNumber, res, ans.size());
 		FOR(i, 0, ans.size()) {
 			printf("%c %d %d\n", a[ans[i].first][ans[i].second], ans[i].first + 1, ans[i].second + 1);
 		}
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }