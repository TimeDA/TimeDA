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
 
 map<LL, LL> cnt;
 map<LL, LL> nextCnt;
 
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
 		LL n, k;
 		cin >> n >> k;
 		cnt.clear();
 		nextCnt.clear();
 		cnt[n] = 1;
 		LL res1 = 0;
 		LL res2 = 0;
 		while (k) {
 			auto it = cnt.end();
 			nextCnt.clear();
 			while (it != cnt.begin()) {
 				it--;
 				if (it->second >= k) {
 					k = 0;
 					res1 = (it->first / 2);
 					res2 = (it->first - 1) / 2;
 					break;
 				}
 				k -= it->second;
 				nextCnt[it->first / 2] += it->second;
 				nextCnt[(it->first - 1) / 2] += it->second;
 			}
 			cnt = nextCnt;
 		}
 		cout << "Case #" << testNumber << ": " << res1 << " " << res2 << endl;
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }