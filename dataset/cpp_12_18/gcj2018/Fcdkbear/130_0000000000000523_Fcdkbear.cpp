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
	//freopen("e.in", "r", stdin);
	//freopen("e_out.txt", "w", stdout);
	double beg = clock();
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> a >> b >> n;
		int l = a + 1;
		int r = b;
		while (l <= r) {
			int m = (l + r) / 2;
			cout << m << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if (s[0] == 'C') {
				break;
			}
			if (s == "TOO_BIG") {
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
	}

#ifdef Fcdkbear
	//double end = clock();
	//fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}