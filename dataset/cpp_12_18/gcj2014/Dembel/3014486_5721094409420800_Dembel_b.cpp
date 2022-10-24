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
 		int n;
 		scanf("%d", &n);
 		vector <int> a(n);
 		for (int i = 0; i < n; ++i)
 			scanf("%d", &a[i]);
 		int res = 0;
 		for (int i = 0; i < n; ++i)
 		{
 			int cnt1 = 0, cnt2 = 0;
 			for (int j = 0; j < i; ++j)
 				if (a[j] > a[i])
 					++cnt1;
 			for (int j = i + 1; j < n; ++j)
 				if (a[j] > a[i])
 					++cnt2;
 			res += min(cnt1, cnt2);
 		}
 		printf("%d\n", res);
 	}
 
 	return 0;
 }
