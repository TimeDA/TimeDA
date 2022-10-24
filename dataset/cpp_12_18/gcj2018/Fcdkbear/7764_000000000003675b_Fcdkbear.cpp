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
		vector<int> d(n), a(n), b(n);
		FOR(i, 0, n) {
			cin >> d[i] >> a[i] >> b[i];
		}
		int res = 0;
		int cnt = 0;
		FOR(le, 0, n) {
			FOR(ri, le, n) {
				FOR(k, le, ri + 1) {
					bool assigned = false;
					int other = 0;
					bool f = true;
					FOR(i, le, ri + 1) {
						if (d[i] + a[i] == d[k] + a[k]) {
							continue;
						}
						if ((!assigned) || (d[i] - b[i] == other)) {
							assigned = true;
							other = d[i] - b[i];
						}
						else {
							f = false;
							break;
						}
					}
					if (f) {
						if (ri - le + 1 > res) {
							res = ri - le + 1;
							cnt = 1;
						}
						else if (ri - le + 1 == res) {
							cnt++;
						}
						break;
					}
				}
			}
		}
		printf("Case #%d: %d %d\n", testNumber, res, cnt);
	}
	

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}