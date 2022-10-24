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
 #define fill(a, b) memset(a, b, sizeof(a))
 
 using namespace std;
 
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
 
 vector <int> gen(int n, int p, int q, int r, int s)
 {
 	vector <int> v(n);
 	for (int i = 0; i < n; ++i)
 		v[i] = (ll(i) * p + q) % r + s;
 	return v;
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
 		int n, p, q, r, S;
 		scanf("%d%d%d%d%d", &n, &p, &q, &r, &S);
 		vector <int> v = gen(n, p, q, r, S);
 		vector <ll> s(n + 1, 0);
 		for (int i = 1; i <= n; ++i)
 			s[i] = s[i - 1] + v[i - 1];
 		ll res = s[n];
 		for (int L = 0, R = 1; L < n; ++L)
 		{
 			ll sum1 = s[L];
 			ll sum2, sum3;
 			while (R < n && s[R] - s[L] < s[n] - s[R])
 			{
 				sum2 = s[R] - s[L];
 				sum3 = s[n] - s[R];
 				res = min(res, max(sum1, max(sum2, sum3)));
 				++R;
 			}
 			sum2 = s[R] - s[L];
 			sum3 = s[n] - s[R];
 			res = min(res, max(sum1, max(sum2, sum3)));
 		}
 		printf("%.20lf\n", double(s[n] - res) / s[n]);
 	}
 
 	return 0;
 }
 
 
