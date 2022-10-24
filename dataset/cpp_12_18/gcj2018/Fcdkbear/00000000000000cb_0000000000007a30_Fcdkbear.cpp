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

char was[513][70][1001];
double dp[513][70][1001];
double C = 1000;

double r(int mask, int cnt, int attempts) {
	if (attempts > C) {
		return 0;
	}
	if ((cnt == 1) && (mask == 511)) {
		return 1;
	}
	if (was[mask][cnt][attempts]) {
		return dp[mask][cnt][attempts];
	}
	was[mask][cnt][attempts] = 1;
	if (((mask&7) == 7) && (cnt > 1)) {
		return dp[mask][cnt][attempts] = r(mask >> 3, cnt - 1, attempts);
	}
	double res = 0;
	FOR(i,0,9) {
		int nmask = mask | (1 << i);
		res += r(nmask, cnt, attempts + 1);
	}
	return dp[mask][cnt][attempts] = res / 9.0;
}

int main()
{
	int tests;
	cin >> tests;
	FOR(testNumber, 1, tests + 1) {
		int a;
		cin >> a;
		int rows = (a + 2) / 3 - 2;
		int x = 500;
		int y = 500;
		int mask = 0;
		while (1) {
			if ((rows == 1) && (mask == 511)) {
				break;
			}
			printf("%d %d\n",x,y);
			fflush(stdout);
			int rx,ry;
			scanf("%d%d",&rx,&ry);
			if ((rx == 0) && (ry == 0)) {
				break;
			}
			int idx = (rx - x + 1) * 3 + (ry - y + 1);
			mask |= (1 << idx);
			if ((rows > 1) && ((mask&7) == 7)) {
				rows--;
				mask >>= 3;
				x++;
			}
		}
	}
	return 0;
}