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

char ans[110][110];

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
		int m;
		cin >> m;
		vector<int> a(m);
		int sum = 0;
		FOR(i, 0, m) {
			cin >> a[i];
			sum += a[i];
		}
		printf("Case #%d: ", testNumber);
		if ((a[0] == 0) || (a[m - 1] == 0) || (sum != m)) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		int rows = 1;
		int l = 0;
		int r = 0;
		int curSum = 0;
		int res = 0;
		vector<int> le(m, -1);
		vector<int> ri(m, -1);
		while (l < m) {
			curSum += a[r];
			if (curSum == r - l + 1) {
				int last = l;
				FOR(i, l, r + 1) {
					int val = a[i];
					while (val > 0) {
						if ((last < i) && (le[i] == -1)) {
							le[i] = last;
						}
						if (last > i) {
							ri[i] = last;
						}
						res = max(res, ABS(i - last));
						val--;
						last++;
					}
				}
				r++;
				l = r;
				curSum = 0;
			}
			else {
				r++;
			}
		}
		res++;
		cout << res << endl;
		FOR(i, 0, res) {
			FOR(j, 0, m) {
				ans[i][j] = '.';
			}
		}
		FOR(i, 0, m) {
			if (le[i] != -1) {
				int x = res - 2;
				int y = i - 1;
				while (y >= le[i]) {
					ans[x][y] = '\\';
					x--;
					y--;
				}
			}
			if (ri[i] != -1) {
				int x = res - 2;
				int y = i + 1;
				while (y <= ri[i]) {
					ans[x][y] = '/';
					x--;
					y++;
				}
			}
		}
		FOR(i, 0, res) {
			FOR(j, 0, m) {
				printf("%c", ans[i][j]);
			}
			printf("\n");
		}
	}


#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}