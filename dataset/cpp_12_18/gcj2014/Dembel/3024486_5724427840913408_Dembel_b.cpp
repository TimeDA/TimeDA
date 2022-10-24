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
 
 int solve(int p, int q, int n, const vector <int> & h, const vector <int> & g,
 		  vector < vector <int> > & dp, int i, int j)
 {
 	if (i == n)
 		return 0;
 	int & res = dp[i][j];
 	if (res != -1)
 		return res;
 	
 	res = solve(p, q, n, h, g, dp, i + 1, j + (h[i] + q - 1) / q);
 	for (int k = 0; k * q < h[i]; ++k)
 	{
 		for (int l = 1; l <= j + k; ++l)
 		{
 			if (k * q + l * p >= h[i] && k * q + (l - 1) * p < h[i])
 			{
 //				dbg("h[%d] = %d, k = %d, l = %d\n", i, h[i], k, l);
 				res = max(res, g[i] + solve(p, q, n, h, g, dp, i + 1, j + k - l));
 			}
 		}
 	}
 //	dbg("dp[%d][%d] = %d\n", i, j, res);
 	return res;
 }
 
 void solve()
 {
 	int p, q, n;
 	scanf("%d%d%d", &p, &q, &n);
 	vector <int> h(n), g(n);
 	for (int i = 0; i < n; ++i)
 		scanf("%d%d", &h[i], &g[i]);
 	vector < vector <int> > dp(n, vector <int> (300, -1));
 	h[0] += q;
 	printf("%d\n", solve(p, q, n, h, g, dp, 0, 0));
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
 		solve();
 	}
 
 	return 0;
 }
