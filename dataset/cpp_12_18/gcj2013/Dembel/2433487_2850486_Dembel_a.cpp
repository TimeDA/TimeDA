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
 
 using namespace std;
 
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
 		dbg("Case #%d: ", ii);
 		ll b;
 		int n;
 		scanf("%lld %d", &b, &n);
 		vector <ll> a(37, 0);
 		for (int i = 0; i < n; ++i)
 			scanf("%lld", &a[i]);
 		sort(a.begin(), a.end());
 		double res = 0.0;
 		for (int i = 1; i <= 36; ++i)
 			for (int j = i; j <= 37; ++j)
 			{
 				ll minY, maxY;
 				if (i == j)
 				{
 					maxY = a[j] - 1;
 					minY = a[j - 1];
 				}
 				else
 				{
 					maxY = (j == 37) ? ll(1e15) : a[j] - 1;
 					minY = max(a[i - 1], a[j - 1] - 1);
 				}
 				if (minY > maxY)
 					continue;
 				ll s1 = 0;
 				ll s2 = 0;
 				for (int k = 0; k < i; ++k)
 					s1 += a[k];
 				for (int k = i; k < j; ++k)
 					s2 += a[k];
 
 				while (minY < maxY)
 				{
 					ll mid = (minY + maxY + 1) / 2;
 					if (mid * j + (j - i) - s1 - s2 <= b)
 						minY = mid;
 					else
 						maxY = mid - 1;
 				}
 				ll y = minY;
 				if (y * j + (j - i) - s1 - s2 > b)
 					continue;
 				res = max(res, (36 - j) * y - s1 * 36.0 / i - (j - i) + s1 + s2);
 			}
 		printf("%.10lf\n", res);
 	}
 
 	return 0;
 }
