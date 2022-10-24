#include <cstdio>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <vector>
 #include <cstdarg>
 #include <iostream>
 
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
 
 const int N = 20;
 
 bool used[N + 1][1 << N];
 double dp[N + 1][1 << N];
 
 double solve(int n, int mask)
 {
 	if (used[n][mask])
 		return dp[n][mask];
 	double &ans = dp[n][mask];
 	used[n][mask] = true;
 
 	if (mask == (1 << n) - 1)
 	{
 		return ans = 0;
 	}
 
 	ans = 0;
 	for (int i = 0; i < n; ++i)
 	{
 		int j = i;
 		int cur = n;
 		while (mask & (1 << j))
 		{
 			--cur;
 			j = j + 1;
 			if (j == n)
 				j = 0;
 		}
 		ans += cur + solve(n, mask | (1 << j));
 	}
 	ans /= n;
 	return ans;
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
 		string s;
 		cin >> s;
 		int n = int(s.length());
 		int mask = 0;
 		for (int i = 0; i < n; ++i)
 			if (s[i] == 'X')
 				mask |= (1 << i);
 		printf("%.10lf\n", solve(n, mask));
 	}
 
 	return 0;
 }
