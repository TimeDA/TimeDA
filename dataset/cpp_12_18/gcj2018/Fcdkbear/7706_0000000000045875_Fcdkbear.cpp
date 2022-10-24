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

int a[110][110];
int b[110][110];

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
		int n;
		cin >> n;
		FOR(i, 0, n) {
			FOR(j, 0, n) {
				cin >> a[i][j];
			}
		}
		int res = 1000000000;
		FOR(mask, 0, (1 << (n*n))) {
			FOR(i, 0, n) {
				FOR(j, 0, n) {
					b[i][j] = a[i][j];
				}
			}
			int cnt = n + 1;
			int tot = 0;
			FOR(i, 0, n*n) {
				if ((mask >> i) & 1) {
					b[i / n][i%n] = cnt;
					cnt++;
					tot++;
				}
			}
			bool ok = true;
			FOR(i, 0, n) {
				FOR(j, 0, n) {
					FOR(k, 0, n) {
						if ((i != k) && (b[i][j] == b[k][j])) {
							ok = false;
						}
						if ((j != k) && (b[i][j] == b[i][k])) {
							ok = false;
						}
					}
				}
			}
			if (ok) {
				res = min(res, tot);
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