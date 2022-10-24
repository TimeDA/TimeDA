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
 
 LL dp[20][10][2];
 LL p[20];
 string s;
 const LL INF = 2000000000000000000ll;
 
 LL r(int pos, int last, int f) {
 	if (pos == s.size()) {
 		return 0;
 	}
 	if (dp[pos][last][f] != -1) {
 		return dp[pos][last][f];
 	}
 	int from = last;
 	int to = 9;
 	if (f == 0) {
 		to = (s[pos] - '0');
 	}
 	LL res = INF;
 	LL add = p[s.size() - pos - 1];
 	FOR(digit, from, to + 1) {
 		int nf = f;
 		if (digit < (s[pos] - '0')) {
 			nf = 1;
 		}
 		LL ans = r(pos + 1, digit, nf);
 		if (ans == INF) {
 			continue;
 		}
 		ans += add * digit;
 		if (res == INF) {
 			res = ans;
 		}
 		else {
 			res = max(res, ans);
 		}
 	}
 	return dp[pos][last][f] = res;
 }
 
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
 	p[0] = 1;
 	FOR(i, 1, 19) {
 		p[i] = p[i - 1] * 10;
 	}
 	FOR(testNumber, 1, tests + 1) {
 		cin >> s;
 		MEMS(dp, -1);
 		cout << "Case #" << testNumber << ": " << r(0, 0, 0) << endl;
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }