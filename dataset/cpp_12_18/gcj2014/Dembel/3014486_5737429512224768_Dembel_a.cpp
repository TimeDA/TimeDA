#include <cstdio>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdarg>
 
 #define clr(a) memset(a, 0, sizeof(a))
 #define fill(a, b) memset(a b, sizeof(a))
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef std::pair<int,int> pii;
 
 #define DBG2 1
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
 #if DBG2
 	FILE* file = stderr;
 	va_list args;
 	va_start(args, fmt);
 	vfprintf(file, fmt, args);
 	va_end(args);
 
 	fflush(file);
 #endif
 #endif
 }
 
 using namespace std;
 
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
 		int n, x;
 		scanf("%d%d", &n, &x);
 		vector <int> a(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		sort(a.begin(), a.end());
 		int i = 0;
 		int j = n - 1;
 		int ans = 0;
 		while (i <= j)
 		{
 			if (i == j || a[i] + a[j] > x)
 			{
 				++ans;
 				--j;
 			}
 			else
 			{
 				++ans;
 				++i;
 				--j;
 			}
 		}
 		printf("%d\n", ans);
 	}
 
 	return 0;
 }
