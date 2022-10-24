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
 
 char a[6][60];
 int n, m;
 int dp[40][60];
 int how[40][60];
 int nmasks[40][60];
 int r(int mask, int col) {
 	if (col == m) {
 		return 1;
 	}
 	if (dp[mask][col] != -1) {
 		return dp[mask][col];
 	}
 	int covered = 0;
 	FOR(i, 0, n) {
 		if (((a[i][col] == '-') || (a[i][col] == '|')) && ((mask >> i) & 1)) {
 			return dp[mask][col] = 0;
 		}
 	}
 	FOR(next, 0, (1 << n)) {
 		int nmask = mask;
 		covered = mask;
 		bool ok = true;
 		FOR(i, 0, n) {
 			if (a[i][col] == '#') {
 				if ((nmask >> i) & 1) {
 					nmask ^= (1<<i);
 				}
 				continue;
 			}
 			if (a[i][col] == '.') {
 				continue;
 			}
 			if ((next >> i) & 1) {
 				if ((nmask >> i) & 1) {
 					nmask ^= (1 << i);
 				}
 				int p = i - 1;
 				while (p >= 0) {
 					if (a[p][col] == '#') {
 						break;
 					}
 					if (a[p][col] == '.') {
 						covered |= (1 << p);
 					}
 					else {
 						ok = false;
 					}
 					p--;
 				}
 				p = i + 1;
 				while (p < n) {
 					if (a[p][col] == '#') {
 						break;
 					}
 					if (a[p][col] == '.') {
 						covered |= (1 << p);
 					}
 					else {
 						ok = false;
 					}
 					p++;
 				}
 			}
 			else {
 				nmask |= (1 << i);
 			}
 		}
 		FOR(i, 0, n) {
 			if (a[i][col] == '.') {
 				if ((covered >> i) & 1)
 					continue;
 				ok = false;
 			}
 		}
 		if (ok) {
 			int v = r(nmask, col + 1);
 			if (v) {
 				how[mask][col] = next;
 				nmasks[mask][col] = nmask;
 				return dp[mask][col] = 1;
 			}
 		}
 	}
 	return dp[mask][col] = 0;
 }
 
 int main()
 {
 #ifdef Fcdkbear
 	freopen("in.txt", "r", stdin);
 	freopen("out.txt", "w", stdout);
 	double beg = clock();
 #endif
 
 	int tests;
 	cin >> tests;
 	FOR(testnumber, 1, tests + 1) {
 		cin >> n >> m;
 		FOR(i, 0, n) {
 			scanf("%s", a[i]);
 		}
 		MEMS(dp, -1);
 		int res = r(0, 0);
 		if (!res) {
 			printf("Case #%d: IMPOSSIBLE\n", testnumber);
 		}
 		else {
 			printf("Case #%d: POSSIBLE\n", testnumber);
 			int mask = 0;
 			FOR(col, 0, m) {
 				int next = how[mask][col];
 				int nmask = nmasks[mask][col];
 				FOR(i, 0, n) {
 					if ((a[i][col] == '-') || (a[i][col] == '|')) {
 						if ((next >> i) & 1)
 							a[i][col] = '|';
 						else
 							a[i][col] = '-';
 					}
 				}
 				mask = nmask;
 			}
 			FOR(i, 0, n) {
 				printf("%s\n", a[i]);
 			}
 		}
 	}
 
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }