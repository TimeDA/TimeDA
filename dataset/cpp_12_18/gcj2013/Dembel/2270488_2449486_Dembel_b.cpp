#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstring>
 #include <string>
 #include <cstdarg>
 
 #pragma comment(linker, "/STACK:64000000")
 
 #define DBG2 1
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
 #if DBG2
 	va_list args;
 	va_start(args, fmt);
 	vfprintf(stderr, fmt, args);
 	va_end(args);
 
 	fflush(stderr);
 #endif
 #endif
 }
 
 using namespace std;
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a, b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int, int> pii;
 
 int a[200][200];
 int minColumn[200], maxColumn[200];
 int minRow[200], maxRow[200];
 const int INF = 1000;
 
 int main()
 {
 #ifdef DBG1
 	freopen(".in", "r", stdin);
 	freopen(".out", "w", stdout);
 	freopen(".err", "w", stderr);
 #endif
 
 	int tt;
 	scanf("%d", &tt);
 	for (int ii = 1; ii <= tt; ++ii)
 	{
 		printf("Case #%d: ", ii);
 
 		int n, m;
 		scanf("%d%d", &n, &m);
 		for (int i = 0; i < n; ++i)
 		{
 			minRow[i] = INF;
 			maxRow[i] = -INF;
 		}
 		for (int j = 0; j < m; ++j)
 		{
 			minColumn[j] = INF;
 			maxColumn[j] = -INF;
 	    }
 
 		for (int i = 0; i < n; ++i)
 			for (int j = 0; j < m; ++j)
 			{
 				scanf("%d", &a[i][j]);
 				minRow[i] = min(minRow[i], a[i][j]);
 				minColumn[j] = min(minColumn[j], a[i][j]);
 
 				maxRow[i] = max(maxRow[i], a[i][j]);
 				maxColumn[j] = max(maxColumn[j], a[i][j]);
 			}
 		bool ok = true;
 		for (int i = 0; i < n; ++i)
 			for (int j = 0; j < m; ++j)
 				ok &= /*a[i][j] == minRow[i] || a[i][j] == minColumn[j] || */a[i][j] == maxRow[i] || a[i][j] == maxColumn[j];
 		printf("%s\n", ok ? "YES" : "NO");
 	}
 
 	return 0;
 }