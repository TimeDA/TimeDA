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
 
 ll bit_reverse(ll a, int n)
 {
 	ll res = 0;
 	for (int i = 0; i < n; ++i)
 	{
 		res = res * 2 + (a & 1);
 		a /= 2;
 	}
 	return res;
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
 		dbg("Case #%d:\n", ii);
 		int n;
 		ll p;
 		cin >> n >> p;
 		ll cnt = (1LL << n);
 
 		if (p == cnt)
 		{
 			cout << cnt - 1 << " " << cnt - 1 << endl;
 			continue;
 		}
 
 		ll A = p;
 		for (int i = 0; i < n; ++i)
 		{
 			if ((A & (1LL << i)) != 0)
 			{
 				if (A + (1LL << i) < cnt)
 					A += (1LL << i);
 			}
 			dbg("A = %lld, i = %d\n", A, i);
 		}	
 
 		ll B = p - 1;
 		for (int i = 0; i < n; ++i)
 		{
 			if ((B & (1LL << i)) == 0)
 			{
 				if (B - (1LL << i) >= 0)
 					B -= (1LL << i);
 			}
 			dbg("B = %lld, i = %d\n", B, i);
 		}
 		cout << bit_reverse(A, n) - 1 << " " << bit_reverse(B, n) << endl;
 	}
 
 	return 0;
 }
