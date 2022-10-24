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

int dp[501][501][35];

int r(int red, int blue, int col) {
	if (col > red) {
		return 0;
	}
	if (dp[red][blue][col] != -1) {
		return dp[red][blue][col];
	}
	int leftBlue = blue;
	int leftRed = red;
	int res = 0;
	int cnt = 0;
	while ((leftBlue >= cnt) && (leftRed >= col)) {
		int add = cnt + 1;
		if (col == 0) {
			add--;
		}
		leftBlue -= cnt;
		leftRed -= col;
		res = max(res, add + r(leftRed, leftBlue, col + 1));
		cnt++;
	}
	return dp[red][blue][col] = res;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	MEMS(dp, -1);
	int tests;
	cin >> tests;
	for (int testNumber = 1; testNumber <= tests; ++testNumber) {
		int red, blue;
		cin >> red >> blue;
		int res = r(red, blue, 0);
		printf("Case #%d: %d\n", testNumber, res);
	}


#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}