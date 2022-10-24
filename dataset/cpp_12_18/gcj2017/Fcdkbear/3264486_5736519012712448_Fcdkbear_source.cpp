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
 
 char s[1010];
 
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
 		int k;
 		scanf("%s%d", s, &k);
 		int n = strlen(s);
 		int res = 0;
 		for (int i = 0; i + k <= n; ++i) {
 			if (s[i] == '-') {
 				res++;
 				FOR(j, 0, k) {
 					if (s[i + j] == '-') {
 						s[i + j] = '+';
 					}
 					else {
 						s[i + j] = '-';
 					}
 				}
 			}
 		}
 		bool ok = true;
 		FOR(i, 0, n) {
 			if (s[i] == '-') {
 				ok = false;
 			}
 		}
 		printf("Case #%d: ", testNumber);
 		if (ok) {
 			printf("%d\n", res);
 		}
 		else {
 			printf("IMPOSSIBLE\n");
 		}
 	}
 
 #ifdef Fcdkbear
 	double end = clock();
 	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
 	return 0;
 }