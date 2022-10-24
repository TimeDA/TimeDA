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
 
 int cnt[1010];
 vector<int> a;
 int n, c, m;
 pair<bool, int> ok(int mid) {
 	if (n*mid < a.size()) {
 		return mp(false, 0);
 	}
 	int p = 0;
 	FOR(i, 1, n + 1) {
 		p += mid;
 		if (p >= a.size()) {
 			break;
 		}
 		int idx = min(p, (int)a.size() - 1);
 		if (a[idx] <= i) {
 			return mp(false, 0);
 		}
 	}
 	int res = 0;
 	int already = 1;
 	FOR(i, 1, a.size()) {
 		if (a[i] == a[i - 1]) {
 			already++;
 		}
 		else {
 			already = 1;
 		}
 		if (already > mid) {
 			res++;
 		}
 	}
 	return mp(true, res);
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
 		cin >> n >> c >> m;
 		MEMS(cnt, 0);
 		a.clear();
 		a.resize(m);
 		int l = 0;
 		FOR(i, 0, m) {
 			int p, b;
 			cin >> p >> b;
 			a[i] = p;
 			cnt[b - 1]++;
 			l = max(l, cnt[b - 1]);
 		}
 		int r = m;
 		int res1 = -1;
 		int res2 = -1;
 		sort(a.begin(), a.end());
 		while (l <= r) {
 			int mid = (l + r) / 2;
 			pnt temp = ok(mid);
 			if (temp.first) {
 				res1 = mid;
 				res2 = temp.second;
 				r = mid - 1;
 			}
 			else {
 				l = mid + 1;
 			}
 		}
 		printf("Case #%d: %d %d\n", testnumber, res1, res2);
 	}
 
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }